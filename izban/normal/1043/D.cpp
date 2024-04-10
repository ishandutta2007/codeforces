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



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<vector<int>> a(m, vector<int>(n));
        vector<vector<int>> nxt(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
                a[i][j]--;
            }
        }
        for (int i = 0; i < m; i++) {
            a[i].push_back(n);
            for (int j = 0; j < n; j++) {
                nxt[a[i][j]].push_back(a[i][j + 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            sort(nxt[i].begin(), nxt[i].end());
        }

        ll ans = 0;
        int r = -1;
        for (int l = 0; l < n; l++) {
            if (r < l) r = l;
            while (r + 1 < n && nxt[a[0][r]][0] == nxt[a[0][r]].back()) {
                r++;
            }
            ans += r - l + 1;
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}