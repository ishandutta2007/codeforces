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

ll power(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}


ll inv(int x) {
    return power(x, mod - 2);
}



void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<ll> w(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    int w0 = 0, w1 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i])
            w1 += w[i];
        else
            w0 += w[i];
    }
    vector<ll> d(m + 1, 0), dd(m + 1, 0);
    d[0] = 1;
    vector<int> invs(2 * m - 1);
    for (int i = 0; i < 2 * m - 1; ++i)
        invs[i] = inv(i + w0 + w1 - m + 1);
    for (int i = 0; i < m; ++i) {
        dd.assign(m + 1, 0);
        for (int j = 0; j <= i; ++j) {
            int ww1 = w1 + j;
            int ww0 = w0 - (i - j);
            if (ww0 < 0)
                continue;
            dd[j + 1] = (dd[j + 1] + ((d[j] * ww1) % mod) * invs[m - 1 + ww0 + ww1 - w1 - w0]) % mod;
            dd[j] = (dd[j] + ((d[j] * ww0) % mod) * invs[m - 1 + ww0 + ww1 - w1 - w0]) % mod;
        }
        swap(d, dd);
    }
    dd.assign(d.begin(), d.end());
    reverse(dd.begin(), dd.end());
    vector<int> res(n);
    ll m1 = 0, m2 = 0;
    for (int i = 0; i <= m; ++i) {
        //cerr << dd[i] << endl;
        m1 = (m1 + ((d[i] * (w1 + i)) % mod) * inv(w1)) % mod;
        m2 = (m2 + ((dd[i] * (w0 - i)) % mod) * inv(w0)) % mod;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            res[i] = (w[i] * m1) % mod;
        }
        else 
            res[i] = (w[i] * m2) % mod;
        cout << res[i] << "\n";
    }
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
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