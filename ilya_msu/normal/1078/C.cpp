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
//const ll mod = 1000 * 1000 * 1000 + 7;
const ll mod = 998244353;


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

int n;
vector<vector<int> > g;
vector<ll> d0, d1, d;

void dfs(int pos, int p) {
    d0[pos] = 0;
    d1[pos] = 1;
    d[pos] = 1;
    ll m0 = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs(to, pos);
        m0 = (m0 * (d[to] + d0[to])) % mod;
    }
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        
        d0[pos] = (d0[pos] + ((m0 * d1[to]) % mod) * inv(d[to] + d0[to])) % mod;
        d[pos] = (d[pos] * d[to]) % mod;
        d1[pos] = (d1[pos] * (d0[to] + d[to])) % mod;
    }
    d[pos] += d0[pos];
    d[pos] %= mod;
}

void solve() {
    cin >> n;
    g.resize(n);
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d0.assign(n, 0);
    d1.assign(n, 0);
    d.assign(n, 0);
    dfs(0, -1);
    //for (int i = 0; i < n; ++i) {
    //    cout << d0[i] << " " << d1[i] << " " << d[i] << endl;
    //}
    cout << d[0] << endl;

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