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

ll check4(ll x) {
    ll a = pow(x, 0.25);
    while (a * a * a * a > x) {
        --a;
    }
    while (a * a * a * a < x)
        ++a;
    if (a * a * a * a == x)
        return a;
    return 0;
}

ll check3(ll x) {
    ll a = pow(x, 1.0 / 3);
    while (a * a * a > x) {
        --a;
    }
    while (a * a * a < x)
        ++a;
    if (a * a * a == x)
        return a;
    return 0;
}

ll check2(ll x) {
    ll a = pow(x, 0.5);
    while (a * a > x) {
        --a;
    }
    while (a * a < x)
        ++a;
    if (a * a == x)
        return a;
    return 0;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pll> pp;
    vector<ll> b;
    for (int i = 0; i < n; ++i) {
        ll r = check4(a[i]);
        if (r) {
            pp.push_back(pll(r, 4));
            continue;
        }
        r = check3(a[i]);
        if (r) {
            pp.push_back(pll(r, 3));
            continue;
        }
        r = check2(a[i]);
        if (r) {
            pp.push_back(pll(r, 2));
            continue;
        }
        b.push_back(a[i]);
    }
    
    map<ll, int> mp;
    for (int i = 0; i < pp.size(); ++i) {
        ll p = pp[i].first;
        if (mp.find(p) != mp.end()) {
            mp[p] += pp[i].second;
        }
        else
            mp[p] = pp[i].second;
    }
    vector<ll> c;
    for (int i = 0; i < b.size(); ++i) {
        bool ok = 0;
        for (int j = 0; j < b.size(); ++j) {
            if (b[i] == b[j]) {
                continue;
            }
            ll d = gcd(b[i], b[j]);
            if (d > 1) {
                mp[d] += 1;
                //cerr << d << "\n";
                mp[b[i] / d] += 1;
                ok = 1;
                break;
            }
        }
        if (ok)
            continue;
        for (int j = 0; j < pp.size(); ++j) {
            ll d = gcd(b[i], pp[j].first);
            if (d > 1) {
                mp[d] += 1;
                mp[b[i] / d] += 1;
                ok = 1;
                break;
            }
        }
        if (!ok)
            c.push_back(b[i]);
    }
    //cout << c.size() << endl;
    sort(c.begin(), c.end());
    c.push_back(-1);
    int cnt = 1;
    ll res = 1;
    for (int i = 1; i < c.size(); ++i) {
        if (c[i] != c[i - 1]) {
            res = (res * (cnt + 1) * (cnt + 1)) % mod;
            cnt = 1;
        }
        else
            ++cnt;
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        res = (res * (it->second + 1)) % mod;
    }
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