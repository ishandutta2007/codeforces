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
vector<int> d;
int M;
int nxt;
vector<pii> ed;
vector<int> cst;

void dfs1(int pos, int p = -1) {
    d[pos] = 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs1(to, pos);
        d[pos] += d[to];
    }
}

void dfs2(int pos, int p) {
    cerr << nxt << endl;
    cst.push_back(nxt - d[p]);
    ed.push_back(pii(pos, p));
    d[pos] = nxt;
    ++nxt;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs2(to, pos);
    }
}

void dfs3(int pos, int p, int k) {
    cst.push_back(k * nxt - d[p]);
    ed.push_back(pii(pos, p));
    d[pos] = nxt * k;
    ++nxt;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p)
            continue;
        dfs3(to, pos, k);
    }
}

bool check(int v) {
    //cerr << v << endl;
    d.assign(n, 0);
    dfs1(v, -1);
    vector<pii> dg(g[v].size());
    for (int i = 0; i < g[v].size(); ++i) {
        dg[i] = pii(d[g[v][i]], i);
    }
    dg.push_back(pii(1, -1));
    sort(dg.begin(), dg.end());
    int k = 0;
    bool ok = 0;
    vector<int> part(dg.size() - 1, 0);
    for (int i = 0; i < dg.size(); ++i) {
        k += dg[i].first;
        int id = dg[i].second;
        if (id != -1) 
            part[id] = 1;
        if (k * (n - k + 1) > M) {
            //cerr << v << " " << k << " " << i + 1 << " " << endl;
            ok = 1;
            break;
        }
    }
    if (!ok)
        return 0;
    d.assign(n, 0);
    nxt = 1;
    ed.resize(0);
    cst.resize(0);
    for (int i = 0; i < part.size(); ++i) {
        if (part[i]) {
            dfs2(g[v][i], v);
        }
    }
    nxt = 1;
    for (int i = 0; i < part.size(); ++i) {
        if (part[i] == 0) {
            dfs3(g[v][i], v, k);
        }
    }
    for (int i = 0; i < ed.size(); ++i) {
        cout << ed[i].first + 1 << " " << ed[i].second + 1 << " " << cst[i] << "\n";
    }
    return 1;


}

void solve() {
    cin >> n;
    int x, y;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    M = (2 * n * n) / 9;
    for (int i = 0; i < n; ++i) {
        if (check(i))
            return;
    }

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