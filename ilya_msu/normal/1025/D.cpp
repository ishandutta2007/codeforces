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


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int> > ed(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d = gcd(a[i], a[j]);
            ed[i][j] = (d > 1);
        }
    }
    vector<vector<int> > dl(n, vector<int>(n, 0)), dr(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            dl[i][i] = ed[i][i - 1];
        }
        if (i + 1 < n) {
            dr[i][i] = ed[i][i + 1];
        }
    }
    for (int d = 1; d < n; ++d) {
        for (int l = 0; l < n; ++l) {
            int r = l + d;
            if (r >= n)
                break;
            if (l > 0) {
                for (int m = l; m <= r; ++m) {
                    if (ed[m][l - 1] == 0)
                        continue;
                    if (((m == l) || (dr[l][m - 1])) && ((m == r) || (dl[m + 1][r]))) {
                        dl[l][r] = 1;
                        break;
                    }
                }
            }
            if (r + 1 < n) {
                for (int m = l; m <= r; ++m) {
                    if (ed[m][r + 1] == 0)
                        continue;
                    if (((m == l) || (dr[l][m - 1])) && ((m == r) || (dl[m + 1][r]))) {
                        dr[l][r] = 1;
                        break;
                    }
                }
            }
        }
    }
    int res = dl[1][n - 1] || dr[0][n - 2];
    for (int m = 1; m + 1 < n; ++m) {
        if ((dl[m + 1][n - 1]) && (dr[0][m - 1]))
            res = 1;
    }
    if (res) 
        cout << "Yes\n";
    else
        cout << "No\n";

    
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