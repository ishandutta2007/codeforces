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


class Fenvick {
    vector<ll> a;
    ll get(int r) {
        ll res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += a[r];
        return res;
    }
public:
    void build(int n) {
        a.assign(n, 0);
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
    void inc(int pos, int delta) {
        for (; pos < a.size(); pos = pos | (pos + 1)) {
            a[pos] += delta;
        }
    }
};

Fenvick tr;
int n;
vector<vector<int> > g;
vector<ll> res;
vector<vector<pii> > q;
vector<int> dp;

void dfs(int pos, int p) {
    //cerr << pos << endl;
    if (p != -1)
        dp[pos] = dp[p] + 1;
    for (int i = 0; i < q[pos].size(); ++i) {
        int d1 = dp[pos];
        int d2 = min(dp[pos] + q[pos][i].first, n - 1);
        //tr.addToSeg(d1, d2, q[pos][i].second);
        tr.inc(d1, q[pos][i].second);
        tr.inc(d2 + 1, -q[pos][i].second);

    }
    res[pos] = tr.get(0, dp[pos]);
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs(to, pos);
    }
    for (int i = 0; i < q[pos].size(); ++i) {
        int d1 = dp[pos];
        int d2 = min(dp[pos] + q[pos][i].first, n - 1);
        //tr.addToSeg(d1, d2, -q[pos][i].second);
        tr.inc(d1, -q[pos][i].second);
        tr.inc(d2 + 1, q[pos][i].second);
    }

}


void solve() {
    cin >> n;
    g.resize(n);
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    tr.build(n + 5);
    res.resize(n);
    int m;
    cin >> m;
    q.assign(n, vector<pii>());
    int v, d, x;
    for (int i = 0; i < m; ++i) {
        cin >> v >> d >> x;
        q[v - 1].push_back(pii(d, x));
    }
    dp.assign(n, 0);
    dfs(0, -1);
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;

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