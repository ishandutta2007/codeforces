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
//#include<unordered_map>




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
    if (n < 0)
        return 0;
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k + 1, 0), b(k + 1, 0);
    a[0] = 1;
    for (int i = 0; i < k; ++i) {
        b.assign(k + 1, 0);
        for (int l = 0; l + 1 < k + 1; ++l) {
            b[l] += a[l] * l;
            b[l + 1] += a[l] * (n - l);
        }
        for (int i = 0; i <= k; ++i) {
            a[i] = b[i] % mod;
        }
    }
    ll res = 0;
    for (int i = 0; i <= k; ++i) {
        res = (res + power(2, n - i) * a[i]) % mod;
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