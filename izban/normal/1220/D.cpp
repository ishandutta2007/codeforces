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

    int n;
    while (scanf("%d", &n) == 1) {
        vector<ll> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);


        vector<vector<ll>> vct(100);
        for (ll cur : a) {
            ll x = cur;
            int y = 0;
            while (x % 2 == 0) {
                x /= 2;
                y++;
            }

            vct[y].push_back(cur);
        }

        int mx = 0;
        for (int i = 1; i < (int)vct.size(); i++) if (vct[i].size() > vct[mx].size()) mx = i;

        vector<ll> ans;
        for (int i = 0; i < (int)vct.size(); i++) if (i != mx) for (ll x : vct[i]) ans.push_back(x);

        printf("%d\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) printf("%lld%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}