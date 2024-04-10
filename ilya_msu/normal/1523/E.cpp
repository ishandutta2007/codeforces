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
#include <random>
#include <chrono>


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
const ll mod = 1000000007;

vector<ll> fact;
vector<ll> ifact;

ll power(ll x, int n) {
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

int inv(int x) {
    return power(x, mod - 2);
}

void init() {
    int N = 100000 + 10;
    fact.assign(N, 1);
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    ifact.resize(N, 1);
    for (int i = 0; i < N; ++i)
        ifact[i] = inv(fact[i]);
}

ll fun(int n, int m) {
    ll res = (fact[n] * ifact[n - m]) % mod;
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    ll res = 1;
    for (int l = 1; l < n; ++l) {
        int m = n - (l - 1) * (k - 1);
        if (m < l)
            break;
        res += fun(m, l) * inv(fun(n, l));
        res %= mod;
    }
    cout << res << endl;
}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t;
    init();
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}