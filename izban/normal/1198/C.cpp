#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pair<int, int>>> e(3 * n);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }

        vector<char> used(n * 3);
        vector<int> mt;
        for (int i = 0; i < 3 * n; i++) {
            if (used[i]) continue;
            for (auto o : e[i]) {
                int to = o.first, id = o.second;
                if (used[to]) continue;
                used[i] = used[to] = 1;
                mt.push_back(id);
                break;
            }
        }

        if ((int)mt.size() >= n) {
            printf("Matching\n");
            for (int i = 0; i < n; i++) printf("%d%c", mt[i] + 1, " \n"[i + 1 == n]);
        } else {
            printf("IndSet\n");
            vector<int> vct;
            for (int i = 0; i < 3 * n; i++) if (!used[i]) vct.push_back(i);
            assert((int)vct.size() >= n);
            for (int i = 0; i < n; i++) printf("%d%c", vct[i] + 1, " \n"[i + 1 == n]);
        }
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}