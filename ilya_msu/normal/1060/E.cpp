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

int n;
vector<vector<int> > g;
ll v0 = 1, v1 = 0;
ll res = 0;
vector<ll> d0, d1, h;
void dfs(int pos, int p, int hh) {
    h[pos] = hh;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs(to, pos, hh + 1);
        ++d1[pos];
        d1[pos] += d0[to];
        d0[pos] += d1[to];
    }
}

void dfs2(int pos, int p) {
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs2(to, pos);
        ll v0 = d0[to];
        ll u0 = d0[0] + 1;
        ll v1 = d1[to];
        ll u1 = d1[0];
        if (h[pos] & 1)
            swap(u0, u1);
        --u0, --u1;
        u0 -= v0;
        u1 -= v1;
        //res += u0 * v0 + u0 * v1 + u0;
        //res += u1;
        //res += v0 + v1 + 1;
        res += (u0 + u1 + 1) * (v0 + v1 + 1);
    }

}

void solve() {
    cin >> n;
    g.resize(n);
    vector<ll> dg(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d0.assign(n, 0), d1.assign(n, 0), h.assign(n, 0);
    dfs(0, -1, 0);
    dfs2(0, -1);
    //cout << res << endl;
    res += (d0[0] + 1) * d1[0];
    cout << res / 2 << endl;

}

//#define LOCAL

int main() {
    //ios_base::sync_with_stdio(0);
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