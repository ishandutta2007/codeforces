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
const ll mod = 998244353;


void solve() {
    int n, m;
    cin >> n >> m;
    int mm = max(m, n);
    vector<vector<int> > a(n, vector<int> (mm));
    vector<int> c(mm, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            c[j] = max(c[j], a[i][j]);
        }
    }
    m = mm;
    vector<pii> p(m);
    for (int i = 0; i < m; ++i) {
        p[i] = pii(c[i], i);
    }
    sort(p.rbegin(), p.rend());
    vector<vector<int> > b(2 * n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j][i] = b[j + n][i] = a[j][p[i].second];
        }
    }
    ll up = 1;
    for (int i = 1; i < n; ++i) {
        up *= n;
    }
    int res = 0;
    for (ll msk = 0; msk < up; ++msk) {
        int cur = 0;
        
        for (int i = 0; i < n; ++i) {
            int x = b[i][0];
            ll curMsk = msk; 
            for (int j = 1; j < n; ++j) {
                int r = curMsk % n;
                curMsk /= n;
                x = max(x, b[i + r][j]);
            }
            cur += x;
        }
        res = max(res, cur);
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
    cin >> t;
    for (int i = 0; i < t; ++i) 
        solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}