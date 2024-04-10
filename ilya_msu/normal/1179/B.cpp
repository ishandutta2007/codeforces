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


void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > a(m, vector<int>(n));
    int x = 1;
    for (int i = 0; i < m / 2; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = x;
                a[m - i - 1][n - j - 1] = x + 1;
                x += 2;
            }
        }
        else {
            for (int j = 0; j < n; ++j) {
                a[i][n - j - 1] = x;
                a[m - i - 1][j] = x + 1;
                x += 2;
            }
        }
    }
    if (m & 1) {
        for (int i = 0; i < n / 2; ++i) {
            a[m / 2][i] = x;
            a[m / 2][n - 1 - i] = x + 1;
            x += 2;
        }
        if (n & 1) {
            a[m / 2][n / 2] = x;
        }
    }
    vector<pii> res(m * n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[a[i][j] - 1] = pii(i + 1, j + 1);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first << " " << res[i].second << "\n";
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