#include <bits/stdc++.h>
#define pw(x) (1LL << (x))
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;


int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<vector<int>> e(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        int root = 0;
        for (int i = 1; i < n; i++) {
            if (e[i].size() > e[root].size()) {
                root = i;
            }
        }

        bool ok = 1;
        for (int i = 0; i < n; i++) {
            ok &= i == root || e[i].size() <= 2;
        }

        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (i != root && e[i].size() == 1) {
                ans.push_back({root + 1, i + 1});
            }
        }

        if (ok) {
            printf("Yes\n");
            printf("%d\n", (int)ans.size());
            for (auto o : ans) printf("%d %d\n", o.first, o.second);
        } else {
            printf("No\n");
        }
    }

#ifdef HOME
    cerr << "time = " << (clock() * 1. / CLOCKS_PER_SEC) << "\n";
#endif
    return 0;
}