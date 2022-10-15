#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 10;
const int N = 314159;
const int MOD = 1000 * 1000 * 1000 + 7;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;

struct dsu {
    int n;
    vector<int> p, diam, h;
    dsu(int nn) {
        n = nn;
        p.resize(n);
        diam.assign(n, 0);
        h.assign(n, 0);
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int root(int x) {
        if (p[x] == x)
            return x;
        p[x] = root(p[x]);
        return p[x];
    }
    int get(int x) {
        return diam[root(x)];
    }
    void unite(int x, int y) {
        int r1 = root(x), r2 = root(y);
        if (r1 == r2)
            return;
        if (h[r1] >= h[r2]) {
            p[r2] = r1;
            diam[r1] = max(diam[r1], diam[r2]);
            diam[r1] = max(diam[r1], h[r1] + h[r2] + 1);
            h[r1] = max(h[r1], h[r2] + 1);
        }
        else {
            p[r1] = r2;
            diam[r2] = max(diam[r1], diam[r2]);
            diam[r2] = max(diam[r2], h[r1] + h[r2] + 1);
            h[r2] = max(h[r2], h[r1] + 1);

        }
    }
};

vector<vector<int> > g;
vector<int> used, d1, d2;
pii arg;
int maxDiam;
vector<int> comp;

pii dfs1(int pos) {
    used[pos] = 1;
    comp.push_back(pos);
    pii m1(-1, pos), m2(-1, pos);
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (used[to])
            continue;
        pii m = dfs1(to);
        if (m.first > m1.first) {
            m2 = m1;
            m1 = m;
        }
        else {
            if (m.first > m2.first) {
                m2 = m;
            }
        }
    }
    int curd = m1.first + m2.first + 2;
    if (curd > maxDiam) {
        maxDiam = curd;
        arg = pii(m1.second, m2.second);
    }
    m1.first++;
    return m1;
}

void dfs2(int pos, int pr = -1) {
    if (pr == -1)
        d1[pos] = 0;
    else
        d1[pos] = d1[pr] + 1;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        dfs2(to, pos);
    }

}

int dfs3(int pos, int pr = -1) {
    int res = -1;
    if (pr == -1)
        d2[pos] = 0;
    else
        d2[pos] = d2[pr] + 1;
    if ((d1[pos] + d2[pos] == maxDiam) && (abs(d1[pos] - d2[pos]) <= 1))
        return pos;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == pr)
            continue;
        res = max(res, dfs3(to, pos));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    used.assign(n, false);
    dsu tr(n);
    d1.assign(n, 0);
    d2.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        if (used[i])
            continue;
        
        comp.clear();
        maxDiam = -1;
        dfs1(i);
        int v1 = arg.first, v2 = arg.second;
        dfs2(v1);
        int r = dfs3(v2);
        for (int j = 0; j < comp.size(); ++j) {
            tr.p[comp[j]] = r;
            tr.h[comp[j]] = (maxDiam + 1) / 2;
            tr.diam[comp[j]] = maxDiam;
        }
    }
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t;
        if (t == 1) {
            cin >> x;
            cout << tr.get(x - 1) << "\n";
        }
        else {
            cin >> x >> y;
            tr.unite(x - 1, y - 1);           
        }
    }
    return 0;
}