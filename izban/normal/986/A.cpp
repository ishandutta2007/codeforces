#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

void print(vector<int> a) {
    for (int i = 0; i < (int)a.size(); i++) printf("%d%c", a[i], " \n"[i + 1 == (int)a.size()]);
}

vector<int> fast(int n, int k, int s, vector<int> a, vector<pair<int, int>> ed) {
    vector<vector<int>> vct(n);

    vector<vector<int>> e(n);
    for (auto o : ed) {
        e[o.first].push_back(o.second);
        e[o.second].push_back(o.first);
    }

    for (int i = 0; i < k; i++) {
        vector<int> d(n, INF);
        vector<int> q;
        for (int j = 0; j < n; j++) if (a[j] == i) {
                d[j] = 0;
                q.push_back(j);
            }

        for (int qq = 0; qq < (int)q.size(); qq++) {
            int v = q[qq];
            for (int to : e[v]) {
                if (d[to] > d[v] + 1) {
                    d[to] = d[v] + 1;
                    q.push_back(to);
                }
            }
        }
        for (int i = 0; i < n; i++) vct[i].push_back(d[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        nth_element(vct[i].begin(), vct[i].begin() + (s - 1), vct[i].end());
        for (int j = 0; j < s; j++) ans[i] += vct[i][j];
    }
    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m, k, s;
    while (scanf("%d%d%d%d", &n, &m, &k, &s) == 4) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        vector<pair<int, int>> ed(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &ed[i].first, &ed[i].second);
            ed[i].first--;
            ed[i].second--;
        }

        print(fast(n, k, s, a, ed));
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}