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
const int N = 50;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int dp[N][N][N][N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '#')
                dp[i][i][j][j] = 1;
            else 
                dp[i][i][j][j] = 0;
        }
    }
    for (int w = 0; w < n; ++w) {
        for (int h = 0; h < n; ++h) {
            if ((w == 0) && (h == 0))
                continue;
            for (int i1 = 0; i1 + w < n; ++i1) {
            int i2 = i1 + w;
            for (int j1 = 0; j1 + h < n; ++j1) {
                int j2 = j1 + h;
                dp[i1][i2][j1][j2] = max(i2 - i1 + 1, j2 - j1 + 1);
                if (i2 - i1 >= j2 - j1) {
                    for (int i = i1; i < i2; ++i) {
                        dp[i1][i2][j1][j2] = min(dp[i1][i2][j1][j2], 
                        dp[i1][i][j1][j2] + dp[i + 1][i2][j1][j2]);
                    }
                }
                else {
                    for (int j = j1; j < j2; ++j) {
                        dp[i1][i2][j1][j2] = min(dp[i1][i2][j1][j2], 
                        dp[i1][i2][j1][j] + dp[i1][i2][j + 1][j2]);
                    }
                }
            }
            }
        }
    }
    cout << dp[0][n - 1][0][n - 1] << endl;
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