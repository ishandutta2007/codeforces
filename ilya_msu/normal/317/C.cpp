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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 1000 * 1000 + 10;
//const ll mod = 1000 * 1000 * 1000 + 7;;
ll n, v, e;
vector<vector<int> > g;
vector<int> p;
vector<pll> subtree;
vector<int> used;
vector<pll> a;
struct DSU {
    int n;
    vector<int> p, r;
    DSU(int nn) {
        n = nn;
        r.assign(n, 1);
        p.resize(n);
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
    bool unite(int x, int y) {
        int p1 = find(x), p2 = find(y);
        if (p1 == p2)
            return 0;
        if (r[p1] < r[p2])
            swap(p1, p2);
        p[p2] = p1;
        r[p1] += r[p2];
        return true;
    }
};
struct mov {
    int from, to, num;
    mov() {}
    mov(int a, int b, int c) : from(a), to(b), num(c) {}
};

vector<mov> res;

pll dfs(int pos, int pr = -1) {
    used[pos] = true;
    p[pos] = pr;
    pll x = a[pos];
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (!used[to]) {
            pll add = dfs(to, pos);
            x.first += add.first;
            x.second += add.second;
        }
    }
    subtree[pos] = x;
    return x;
}

void up(int pos) {
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p[pos])
            continue;
        up(to);
        ll num = min(a[to].first, max(subtree[to].first - subtree[to].second, (ll)(0)));
        num = min(num, v - a[pos].first);
        res.push_back(mov(to + 1, pos + 1, num));
        a[to].first -= num;
        a[pos].first += num;
        subtree[to].first -= num;
    }
}

void down(int pos) {
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p[pos])
            continue;
        down(to);
        ll num = min((ll)a[pos].first, max(subtree[to].second - subtree[to].first, (ll)(0)));
        num = min(num, v - a[to].first);
        res.push_back(mov(pos + 1, to + 1, num));
        a[to].first += num;
        a[pos].first -= num;
        subtree[to].first += num;
    }
}

void solve(int pos) {
    bool ok = true;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p[pos])
            continue;
        if (subtree[to].first == subtree[to].second) {
            solve(to);
            continue;
        }
        if (subtree[to].first < subtree[to].second) {
            down(to);
            ok = false;
        }
        if (subtree[to].first > subtree[to].second) {
            up(to);
            ok = false;
            ll num = min(subtree[to].first - subtree[to].second, (ll)a[to].first);
            num = min(num, v - a[pos].first);
            res.push_back(mov(to + 1, pos + 1, num));
            a[to].first -= num;
            a[pos].first += num;
            subtree[to].first -= num;
        }
    }
    if (ok)
        return;
    for (int i = 0; i < g[pos].size(); ++i) {
        int to = g[pos][i];
        if (to == p[pos])
            continue;
        if (subtree[to].first < subtree[to].second) {
            ll num = min(subtree[to].second - subtree[to].first, (ll)a[pos].first);
            num = min(num, v - a[to].first);
            res.push_back(mov(pos + 1, to + 1, num));
            a[to].first += num;
            a[pos].first -= num;
            subtree[to].first += num;
        }
    }
    solve(pos);
}

int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> v >> e;
    a.resize(n);
    g.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first;
    for (int i = 0; i < n; ++i)
        cin >> a[i].second;
    vector<pii> ed(e);
    for (int i = 0; i < e; ++i) {
        int x, y;
        //scanf("%d %d", &x, &y);
        cin >> x >> y;
        ed[i] = pii(x - 1, y - 1);
    }
    DSU dsu(n);
    for (int i = 0; i < e; ++i) {
        if (dsu.unite(ed[i].first, ed[i].second)) {
            g[ed[i].first].push_back(ed[i].second);
            g[ed[i].second].push_back(ed[i].first);
        }
    }
    used.assign(n, false);
    subtree.resize(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            pll x = dfs(i);
            if (x.first != x.second) {
                cout << "NO\n";
                return 0;
            }
            solve(i);
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].from << " " << res[i].to << " " << res[i].num << "\n";
    }

    return 0;
}