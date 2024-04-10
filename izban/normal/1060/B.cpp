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

ll sum(ll x) {
    ll res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll solve(ll n) {
    string s = to_string(n);

    ll a = 0;
    for (int i = 1; i < (int)s.length(); i++) {
        a = 10 * a + 9;
    }
    ll b = n - a;
    return sum(a) + sum(b);
}

ll slow(ll n) {
    ll res = 0;
    for (ll a = 0; a <= n; a++) res = max(res, sum(a) + sum(n - a));
    return res;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    /*for (ll n = 1; n <= 1e4; n++) {
        cerr << n << endl;
        assert(solve(n) == slow(n));
    }*/
    ll n;
    while (cin >> n) {
        cout << solve(n) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}