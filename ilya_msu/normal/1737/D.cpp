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
#include<unordered_set>
#include<chrono>
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
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;



void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<vector<ll> > ed(n, vector<ll>(n, INF));
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i], --v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        ed[u[i]][v[i]] = ed[v[i]][u[i]] = 1;
    }

    vector<vector<ll> > d(ed);
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll res = LINF;
    for (int i = 0; i < m; ++i) {
        res = min(res, (d[0][u[i]] + d[n - 1][v[i]] + 1) * w[i]);
        res = min(res, (d[n - 1][u[i]] + d[0][v[i]] + 1) * w[i]);
        ll len = n + 10;
        for (int j = 0; j < n; ++j) {
            //res = min(res, (d1[u[i]] + d2[u[i]] + 1) * w[i]);
            //res = min(res, (d1[v[i]] + d2[v[i]] + 1) * w[i]);
            len = min(len, (d[j][0] + d[j][n - 1] + min(d[j][u[i]], d[j][v[i]]) + 2));
        }
        res = min(res, len * w[i]);

    }
    cout << res << "\n";

    
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}