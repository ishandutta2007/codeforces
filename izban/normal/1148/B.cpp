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


const ll INF = 4e9;



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n, m, ta, tb, k;
    while (scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k) == 5) {
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);



        ll res = -1;

        int j = 0;
        for (int i = 0; i <= n; i++) {
            if (i > k) break;
            if (i == n) {
                res = INF;
                break;
            }

            while (j < m && b[j] < a[i] + ta) {
                j++;
            }
            int fly = j + k - i;
            if (fly >= m) {
                res = INF;
                break;
            }
            res = max(res, (ll)b[fly] + tb);
        }
        if (res == INF) res = -1;
        cout << res << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}