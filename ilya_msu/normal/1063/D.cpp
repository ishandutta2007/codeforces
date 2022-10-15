#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 998244353;

const int N = 1000000;

ll solve(ll k, ll d, ll n, ll lowk1) {
    if (n < N) {
        for (int m = n; m >= 0; --m) {
            ll q = (k - (n - d)) / (m + n);
            ll r = k - q * (m + n);
            ll k1 = r - (n - d);
            if ((k1 < lowk1) || (k1 > n - d)) {
                continue;
            }
            if ((m < k1) || (m > k1 + d))
                continue;
            return m;
        }
        return -1;
    }
    ll res = -1;
    k -= n - d;
    if (k < lowk1) 
        return -1;
    if (k <= n - d) {
        res = k + d;
    }

    for (ll q = 1; q * n <= k; ++q) {
        ll x = k / q;
        ll y = k % q;
        for (ll i = 0; ; ++i) {
            ll m = x - i - n;
            ll k1 = y + i * q;
            if (m <= res) {
                break;
            }
            if (k1 > m) {
                break;
            }
            if (k1 < lowk1) {
                continue;
            }
            if (m > k1 + d) {
                i = max(i, (m - k1 - d) / (q + 1) -  4);
                continue;
            }
            if (k1 > n - d)
                break;
            res = max(res, m);
        }
    }
    return res;

}



void solve() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (r < l)
        r += n;
    ll d = r - l + 1;
    d = n - d;
    ll res = -1;
    res = max(solve(k, d, n, 0), solve(k + 1, d, n, 1));
    cout << res << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}