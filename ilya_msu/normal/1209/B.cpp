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
    int n;
    int m = 1000;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int> > d(m, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        d[0][i] = (s[i] == '1');
    }
    for (int i = 0; i < n; ++i) {
        int x = b[i];
        while (x < m) {
            d[x][i] = 1;
            x += a[i];
        }
        for (int j = 1; j < m; ++j) {
            d[j][i] = d[j - 1][i] ^ d[j][i];
        }
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += d[i][j];
        }
        res = max(res, cur);
    }
    cout << res << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}