#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int MOD = (int)1e9 + 7;
const int K = 17;
const int N = 1 << K;

const string NO = "NO";
const string YES = "YES";

int n, q;
int p[N][K];
int mask[N][K];
int tp[N];
int h[N];

pair<int, int> getP(int v, int h) {
    int cmask = 0;
    for (int i = 0; i < K; i++) {
        if (h & (1 << i)) {
            cmask |= mask[v][i];
            v = p[v][i];
        }
    }
    return {v, cmask};
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = getP(u, h[u] - h[v]).first;
    if (u == v) return u;
    for (int i = K - 1; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    if (p[u][0] != p[v][0]) {
        return -1;
    }
    return p[u][0];
}

int go(int v, int nmask) {
    for (int i = K - 1; i >= 0; i--) {
        if (mask[v][i] == nmask) {
            v = p[v][i];
        }
    }
    return v;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i][0]);
            if (p[i][0] == -1) p[i][0] = i;
            else p[i][0]--;

            scanf("%d", &tp[i]);
        }

        for (int i = 0; i < n; i++) {
            if (p[i][0] == i) {
                h[i] = 0;
            } else {
                h[i] = h[p[i][0]] + 1;
            }
            if (tp[i] != -1) mask[i][0] = 1 << tp[i];

            for (int j = 1; j < K; j++) {
                p[i][j] = p[p[i][j - 1]][j - 1];
                mask[i][j] = mask[i][j - 1] | mask[p[i][j - 1]][j - 1];
            }
        }

        scanf("%d", &q);
        vector<string> res;
        for (int ii = 0; ii < q; ii++) {
            int t, u, v;
            scanf("%d%d%d", &t, &u, &v);
            --u; --v;

            if (u == v) {
                res.push_back(NO);
                continue;
            }

            if (t == 1) {
                if (h[v] <= h[u]) {
                    res.push_back(NO);
                    continue;
                }
                auto o = getP(v, h[v] - h[u]);
                if (o.first != u) {
                    res.push_back(NO);
                    continue;
                }
                if (o.second & 2) {
                    res.push_back(NO);
                    continue;
                }
                res.push_back(YES);
                continue;
            }
            if (t == 2) {
                int w = lca(u, v);
                if (w == -1) {
                    res.push_back(NO);
                    continue;
                }
                auto o1 = getP(u, h[u] - h[w]);
                assert(o1.first == w);
                if (o1.second & 2) {
                    res.push_back(NO);
                    continue;
                }
                /*auto o2 = getP(v, h[v] - h[w]);
                assert(o2.first == w);
                if (!(o2.second & 2)) {
                    res.push_back(NO);
                    continue;
                }
                res.push_back(YES);
                continue;*/
                int nv = go(v, 1);
                if (h[nv] <= h[w]) {
                    res.push_back(NO);
                    continue;
                }
                int nv2 = go(v, 2);
                if (h[nv2] > h[w]) {
                    res.push_back(NO);
                    continue;
                }
                res.push_back(YES);
            }
        }
        for (string s : res) printf("%s\n", s.c_str());
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}