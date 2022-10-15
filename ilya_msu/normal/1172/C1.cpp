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


int solve1(ll w, const vector<ll>& d, int t) {
    int m = d.size() - 1;
    ll res = (w * d[0]) % mod;
    vector<ll> d1(m + 1, 0), d2(m + 1, 0);
    d1[0] = 1;
    for (int i = 0; i < m; ++i) {
        d2.assign(m + 1, 0);
        for (int j = 0; j <= i; ++j) {
            int ww1 = w + j;
            d2[j + 1] = (d2[j + 1] + ((d1[j] * ww1) % mod) * inv(t + i)) % mod;
            d2[j] = (d2[j] + ((d1[j] * (t + i - ww1)) % mod) * inv(t + i)) % mod;
        }
        swap(d1, d2);
        ll add = 0;
        for (int j = 0; j < d1.size(); ++j)
            add = (add + d1[j] * (j + w)) % mod;
        res = (res + d[i + 1] * add) % mod;
    }
    return res;


}



int solve0(ll w, const vector<ll>& d, int t) {
    int m = d.size() - 1;
    ll res = (w * d[0]) % mod;
    vector<ll> d1(m + 1, 0), d2(m + 1, 0);
    d1[0] = 1;
    for (int i = 0; i < m; ++i) {
        d2.assign(m + 1, 0);
        for (int j = 0; j <= i; ++j) {
            int ww1 = w - j;
            if (ww1 < 0)
                continue;
            d2[j + 1] = (d2[j + 1] + ((d1[j] * ww1) % mod) * inv(t - i)) % mod;
            d2[j] = (d2[j] + ((d1[j] * (t - i - ww1)) % mod) * inv(t - i)) % mod;
        }
        swap(d1, d2);
        ll add = 0;
        for (int j = 0; j < d1.size(); ++j)
            add = (add + d1[j] * (w - j)) % mod;
        res = (res + d[i + 1] * add) % mod;
    }
    return res;
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> w(n);
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
    vector<int> invs(m);
    for (int i = 0; i < m; ++i)
        invs[i] = inv(i + w0 + w1);
    for (int i = 0; i < m; ++i) {
        dd.assign(m + 1, 0);
        for (int j = 0; j <= i; ++j) {
            int ww1 = w1 + j;
            int ww0 = w0 - (i - j);
            if (ww0 < 0)
                continue;
            dd[j + 1] = (dd[j + 1] + ((d[j] * ww1) % mod) * inv(ww0 + ww1)) % mod;
            dd[j] = (dd[j] + ((d[j] * ww0) % mod) * inv(ww0 + ww1)) % mod;
        }
        swap(d, dd);
    }
    dd.assign(d.begin(), d.end());
    reverse(dd.begin(), dd.end());
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            res[i] = solve1(w[i], d, w1);
        }
        else 
            res[i] = solve0(w[i], dd, w0);
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