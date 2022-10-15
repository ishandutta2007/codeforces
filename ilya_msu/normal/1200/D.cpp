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


vector<vector<int> > solve1(vector<int> l, vector<int> r, int n, int k) {
    int m = n - k + 1;
    vector<vector<int> > res(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        if ((r[i] >= l[i]) && (r[i] - l[i] + 1 <= k)) {
            int x = max(r[i] - k + 1, 0);
            for (int j = max(i - k + 1, 0); j <= i; ++j) {
                res[j][x] += 1;
                res[j][l[i] + 1] -= 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            res[i][j] += res[i][j - 1];
        }
    }
    res.resize(m);
    for (int i = 0; i < m; ++i) {
        res[i].resize(m);
    }
    return res;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    int res = 0;
    vector<int> l(n, n), r(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'B') {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
        }
        if (l[i] > r[i])
            ++res;
    }
    vector<int> u(n, n), d(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j][i] == 'B') {
                u[i] = min(u[i], j);
                d[i] = max(d[i], j);
            }
        }
        if (u[i] > d[i])
            ++res;
    }
    vector<vector<int> > v1 = solve1(l, r, n, k), v2 = solve1(u, d, n, k);
    int m = n - k + 1;
    int add = 0;
    for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
        add = max(add, v1[i][j] + v2[j][i]);
    }
    }
    cout << res + add << endl;
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