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
#include<unordered_map>
#include<deque>
#include<cmath>
#include<iterator>
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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 31607;

ll power(ll x, int n) {
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

ll solve(vector<vector<int> > a) {
    int n = a.size();
    int N = 1 << n;
    vector<int> v(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            v[j] = (v[j] * a[i][j]) % mod;
        }
    }
    int vv = 1;
    for (int j = 0; j < n; ++j)
        vv = (vv * (mod + 1 - v[j])) % mod;
    int res = (mod + 1 - vv) % mod;
    int n1 = n / 2;
    int n2 = n - n1;
    vector<vector<int> > pre1(n, vector<int>(1 << n1));
    vector<vector<int> > pre2(n, vector<int>(1 << n2));
    for (int m = 0; m < (1 << n1); ++m) {
        for (int i = 0; i < n; ++i) {
            int r = 1;
            for (int j = 0; j < n1; ++j) {
                if ((m >> j) & 1) 
                    continue;
                r = (r * a[i][j]) % mod;
            }
            pre1[i][m] = r;
        }
    }
    for (int m = 0; m < (1 << n2); ++m) {
        for (int i = 0; i < n; ++i) {
            int r = 1;
            for (int j = 0; j < n2; ++j) {
                if ((m >> j) & 1) 
                    continue;
                r = (r * a[i][n1 + j]) % mod;
            }
            pre2[i][m] = r;
        }
    }
    for (int m = 0; m < N; ++m) {
        int add = 1;
        for (int j = 0; j < n; ++j) {
            if ((m >> j) & 1) {
                add = (add * (mod - v[j])) % mod;
            }
        }
        int cur = 1;
        int m1 = m & ((1 << n1) - 1);
        int m2 = m >> n1;
        for (int i = 0; i < n; ++i) {
            int r = (pre1[i][m1] * pre2[i][m2]) % mod;
            cur = (cur * (mod + 1 - r)) % mod;
        }
        add = (add * (mod + 1 - cur)) % mod;
        res = (res + add) % mod;
    }
    return res;

}
    
void solve() {
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0;  j < n; ++j) {
            cin >> a[i][j];
            a[i][j] = (a[i][j] * inv(10000)) % mod;
        }
    }
    ll res = 0;
    res += solve(a);
    ll p2 = 1, p3 = 1;
    for (int i = 0; i < n; ++i) {
        p2 = (p2 * a[i][i]) % mod;
        p3 = (p3 * a[i][n - i - 1]) % mod;
    }
    res += p2 + p3;
    vector<vector<int> > b(a), c(a);
    for (int i = 0; i < n; ++i) {
        b[i][i] = 1;
        c[i][n - i - 1] = 1;
    }
    res -= p2 * solve(b);
    res -= p3 * solve(c);
    for (int i = 0; i < n; ++i) {
        b[i][n - i - 1] = 1;
        if (i != n - i - 1)
            p2 = (p2 * a[i][n - i - 1]) % mod;
    }
    res -= p2;
    res += p2 * solve(b);
    res = ((res % mod) + mod) % mod;
    cout << res << endl;
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