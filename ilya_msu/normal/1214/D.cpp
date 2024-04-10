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



void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int> > g1(n, vector<int>(m, 0)), g2(n, vector<int>(m, 0));
    g1[0][0] = 1;
    g2[n - 1][m - 1] = 1;
    for (int d = 0; d < m + n - 2; ++d) {
        for (int i = max(0, d - m); i < n; ++i) {
            int j = d - i;
            if (j >= m)
                continue;
            if (j < 0)
                break;
            if (g1[i][j] == 1) {
                if (i + 1 < n) {
                    if (a[i + 1][j] == '.')
                        g1[i + 1][j] = 1;
                }
                if (j + 1 < m) {
                    if (a[i][j + 1] == '.')
                        g1[i][j + 1] = 1;
                }
            }
        }
    }
    for (int d = m + n - 2; d > 0; --d) {
        for (int i = max(0, d - m); i < n; ++i) {
            int j = d - i;
            if (j >= m)
                continue;
            if (j < 0)
                break;
            if (g2[i][j] == 1) {
                if (i > 0) {
                    if (a[i - 1][j] == '.')
                        g2[i - 1][j] = 1;
                }
                if (j > 0) {
                    if (a[i][j - 1] == '.')
                        g2[i][j - 1] = 1;
                }
            }
        }
    }
    int res = 2;
    for (int d = 1; d < m + n - 2; ++d) {
        int sm = 0;
        for (int i = max(0, d - m); i < n; ++i) {
            int j = d - i;
            if (j >= m)
                continue;
            if (j < 0)
                break;
            if ((g1[i][j] == 1) && (g2[i][j] == 1)) 
                ++sm;
        }
        res = min(res, sm);

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
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}