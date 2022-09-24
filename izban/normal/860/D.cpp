#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 18;
const int MOD = (int)1e9 + 7;

int n, m;
char c[N];
vector<int> e[N];
vector<pair<pair<int, int>, int> > ans;

bool dfs(int v, int pr) {
    c[v] = 1;

    vector<int> vct;
    for (int to : e[v]) {
        if (to == pr) continue;
        if (c[to] == 0) {
            bool f = dfs(to, v);
            if (f) vct.push_back(to);
        } else
        if (c[to] == 1) {
            vct.push_back(to);
        }
    }
    c[v] = 2;
    for (int i = 0; i < (int)vct.size() - 1; i += 2) {
        ans.push_back({{vct[i], v}, vct[i + 1]});
    }
    if (vct.size() % 2 == 1 && pr != -1) {
        ans.push_back({{vct.back(), v}, pr});
        return 0;
    }
    return 1;
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
            c[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        ans.clear();
        for (int i = 0; i < n; i++) {
            if (c[i] != 0) continue;
            dfs(i, -1);
        }
        printf("%d\n", (int)ans.size());
        for (auto o : ans) printf("%d %d %d\n", o.first.first + 1, o.first.second + 1, o.second + 1);
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}