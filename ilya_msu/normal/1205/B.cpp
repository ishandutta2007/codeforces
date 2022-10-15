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

vector<vector<int> > g;


void solve2(int n) {
    int res = n + 5;
    for (int i = 0; i < n; ++i) {
        vector<int> used(n, 0);
        vector<int> d(n, 0);
        queue<int> q;
        q.push(i);
        used[i] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < g[v].size(); ++j) {
                int to = g[v][j];
                if (used[to]) {
                    if ((d[to] >= d[v]) && (d[to] + d[v] + 1 > 2))
                        res = min(d[to] + d[v] + 1, res);
                    continue;
                }
                d[to] = d[v] + 1;
                used[to] = 1;
                q.push(to);
            }
        }
    }
    if (res > n)
        res = -1;
    cout << res << endl;
    return;


}



void solve() {
    int n;
    cin >> n;
    vector<ll> a;
    a.reserve(n);
    ll x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x != 0)
            a.push_back(x);
    }
    vector<ll> c(60, 0);
    n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 60; ++j) {
            if ((a[i] >> j) & 1)
                ++c[j];
        }
    }
    for (int i = 0; i < 60; ++i) {
        if (c[i] >= 3) {
            cout << 3 << endl;
            return;
        }
    }
    g.resize(n);
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] == 2) {
            vector<int> ed;
            for (int j = 0; j < n; ++j) {
                if ((a[j] >> i) & 1)
                    ed.push_back(j);
            }
            g[ed[0]].push_back(ed[1]);
            g[ed[1]].push_back(ed[0]);
        }
    }
    for (int i = 0; i < g.size(); ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
    }
    solve2(n);


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