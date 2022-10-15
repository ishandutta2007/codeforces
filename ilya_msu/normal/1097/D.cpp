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
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

ll inv(ll x) {
    return power(x, mod - 2);
}

vector<vector<ll> > mult(const vector<vector<ll> >& a, const vector<vector<ll> >& b) {
    int n = a.size();
    vector<vector<ll> > res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll > > power(vector<vector<ll> > x, ll n) {
    int sz = x.size();
    vector<vector<ll> > res(sz, vector<ll>(sz, 0));
    for (int i = 0; i < sz; ++i)
        res[i][i] = 1;
    while (n) {
        if (n & 1) {
            res = mult(res, x);
        }
        x = mult(x, x);
        n /= 2;
    }
    return res;
}



void solve() {
    ll n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    vector<pll> d;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) {
                n /= i;
                ++c;
            }
            d.push_back(pll(i, c));
        }
    }
    if (n != 1) {
        d.push_back(pll(n, 1));
    }
    ll ans = 1;
    vector<ll> invs(100);
    for (int i = 1; i < invs.size(); ++i)
        invs[i] = inv(i);
    for (int i = 0; i < d.size(); ++i) {
        vector<ll> res(d[i].second + 1, 0);
        ll p = d[i].first;
        res[0] = 1;
        for (int j = 1; j < res.size(); ++j) {
            res[j] = res[j - 1] * p;
        }
        int m = res.size();
        vector<ll> tmp(m);
        for (int kk = 0; kk < k; ++kk) {
            tmp.assign(m, 0);
            for (int j = 0; j < m; ++j) {
                for (int l = 0; l <= j; ++l) 
                    tmp[j] += res[l];
                tmp[j] = ((tmp[j] % mod) * invs[j + 1]) % mod;
            }
            swap(tmp, res);
        }
        ans = (ans * res[m - 1]) % mod;
    }
    cout << ans << endl;
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