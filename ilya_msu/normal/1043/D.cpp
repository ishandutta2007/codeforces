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
    vector<vector<int> > a(m, vector<int>(n + 2, -1)), p(m, vector<int> (n + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            a[i][j];
            p[i][a[i][j]] = j;
        }
    }
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
        l[i] = a[0][p[0][i] - 1];
        r[i] = a[0][p[0][i] + 1];
        for (int j = 1; j < m; ++j) {
            int x = a[j][p[j][i] - 1];
            int y = a[j][p[j][i] + 1];
            if (x != l[i]) {
                l[i] = -1;
            }
            if (y != r[i]) {
                r[i] = -1;
            }
        }

    }
    ll res = 0;
    int len = 0;
    for (int i = 1; i <= n; ++i) {
        if (l[i] == -1) {
            ll len = 1;
            int id = i;
            while (r[id] != -1) {
                id = r[id];
                ++len;
            }
            res += len * (len + 1) / 2;

        }
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