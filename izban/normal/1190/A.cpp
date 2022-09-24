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

    ll n;
    int m;
    ll k;
    while (scanf("%lld%d%lld", &n, &m, &k) == 3) {
        vector<ll> p(m);
        for (int i = 0; i < m; i++) {
            scanf("%lld", &p[i]);
            p[i]--;
        }

        sort(p.begin(), p.end());

        int ans = 0;
        for (int i = 0; i < m;) {
            ans++;
            int j = i;
            while (i < m && (p[i] - j) / k == (p[j] - j) / k) {
                i++;
            }
        }
        cout << ans << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}