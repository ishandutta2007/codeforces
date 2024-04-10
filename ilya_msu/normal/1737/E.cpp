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
const ll mod = 1000000007;

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

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n, 0);
    p[n - 1] = power((mod + 1) / 2, (n - 1) / 2);
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    vector<ll> suf(n);
    suf[n - 1] = p[n - 1];
    for (int i = n - 2; i > 0; --i) {
        p[i] = power((mod + 1) / 2, (i + 2) / 2);
        if (2 * (i + 1) - 1 <= n - 1)
            p[i] = (p[i] * (mod + 1 - suf[2 * i + 1])) % mod;
        suf[i] = (suf[i + 1] + p[i]) % mod;
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}