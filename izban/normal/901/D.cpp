#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;

const int N = 1 << 17;

int n, m;
vector<int> e[N];
int c[N];
int u1[N], u2[N];
int col[N];
ll ans[N];
ll a[N];

void dfs1(int v, int pr) {
    col[v] = 1;
    a[v] = 0;
    for (int id : e[v]) {
        if (id == pr) continue;
        int to = u1[id] ^ u2[id] ^ v;
        if (col[to] == 0) {
            dfs1(to, id);
            ans[id] = c[to] - a[to];
            a[to] += ans[id];
            a[v] += ans[id];
        } else if (col[to] == 1) {
            ans[id] = 0;
        } else {
            continue;
        }
    }
    col[v] = 2;
}

vector<int> cycle;
int col2[N];
int part[N];
vector<int> st;
void dfs2(int v, int pr, int cc) {
    col2[v] = 1;
    a[v] = 0;
    part[v] = cc;
    st.push_back(pr);
    for (int id : e[v]) {
        if (id == pr) continue;
        int to = u1[id] ^ u2[id] ^ v;
        if (col2[to] == 0) {
            dfs2(to, id, cc ^ 1);
        } else if (col2[to] == 1) {
            if (part[v] == part[to] && cycle.empty()) {
                cycle.push_back(id);
                for (int i = (int)st.size() - 1;; i--) {
                    if (st[i] == -1) break;
                    cycle.push_back(st[i]);
                    if (u1[st[i]] == to || u2[st[i]] == to) break;
                }
            }
        } else {
            continue;
        }
    }
    st.pop_back();
    col2[v] = 2;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u1[i], &u2[i]);
            u1[i]--; u2[i]--;
            e[u1[i]].push_back(i);
            e[u2[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            col[i] = 0;
            col2[i] = 0;
            part[i] = -1;
        }

        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (col[i] != 0) continue;
            assert(i == 0);
            cycle.clear();
            dfs2(i, -1, 0);
            int v = i;
            if (!cycle.empty()) {
                v = u1[cycle[0]];
                assert(cycle.size() % 2 == 1);
                int iid = cycle.back();
                if (!(u1[iid] == v || u2[iid] == v)) {
                    rotate(cycle.begin(), cycle.begin() + 1, cycle.end());
                }
            }
            dfs1(v, -1);
            if (a[v] != c[v]) {
                //continue;
                if (cycle.empty()) {
                    ok = 0;
                } else {
                    assert((a[v] - c[v]) % 2 == 0);
                    ll o = (c[v] - a[v]) / 2;
                    int iid = cycle.back();
                    bool f = u1[iid] == v || u2[iid] == v;
                    for (int j = 0; j < (int)cycle.size(); j++) {
                        ans[cycle[j]] += o * ((j % 2) ? -1 : 1);
                    }
                }
            }
        }

        if (ok) {
            vector<ll> d(n);
            for (int i = 0; i < m; i++) {
                d[u1[i]] += ans[i];
                d[u2[i]] += ans[i];
            }
            for (int i = 0; i < n; i++) {
                assert(d[i] == c[i]);
            }
            printf("YES\n");
            for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);
        } else {
            printf("NO\n");
        }
    }

#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}