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
#include<unordered_set>
#include<chrono>
#include<random>



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
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;

vector<ll> f, invf;

ll power(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

ll inv(ll x) {
    return power(x, mod - 2);
}


void init() {
    int N = 100000 + 10;
    f.resize(N);
    invf.resize(N);
    f[0] = invf[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = (f[i - 1] * i) % mod;
        invf[i] = inv(f[i]);
    }
}


ll binom(ll n, ll k) {
    return (((f[n] * invf[k]) % mod)* invf[n - k]) % mod;

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pii> b;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            b.push_back(pii(a[i], i));
        }
    }
    int m = b.size();
    if (m == 0) {
        cout << power(2, n - 1) << "\n";
        return;
    }
    int l = 0, r = m - 1;
    ll sl = b[0].first, sr = b[m - 1].first;
    int sz = 0;
    vector<int> l0, r0;
    l0.push_back(b[0].second);
    r0.push_back(n - 1 - b[m - 1].second);
    ll res = 1;
    if (m == 1) {
        sz = 1;
    }
    while (l < r) {
        if (sl == sr) {
            sz += 2;
            if (r == l + 1) {
                ll x = b[r].second - b[l].second - 1;
                res = power(2, x + 1) % mod;
                break;
            }
            if (r == l + 2) {
                l0.push_back(b[l + 1].second - b[l].second - 1);
                r0.push_back(b[r].second - b[r - 1].second - 1);
                ++sz;
                break;
            }
            l0.push_back(b[l + 1].second - b[l].second - 1);
            r0.push_back(b[r].second - b[r - 1].second - 1);
            ++l;
            --r;
            sl = b[l].first;
            sr = b[r].first;
            continue;
        }
        if (sl < sr) {
            ++l;
            sl += b[l].first;
            continue;
        }
        if (sl > sr) {
            --r;
            sr += b[r].first;
            continue;
        }
    }


    int k = sz / 2;
    for (int i = 0; i < l0.size(); ++i) {
        m = min(l0[i], r0[i]) + (i > 0);
        ll add = 0;
        for (int j = 0; j <= m; ++j) {
            add = (add + binom(l0[i] + (i > 0), j) * binom(r0[i] + (i > 0), j)) % mod;

        }
        res = (res * add) % mod;
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    init();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}