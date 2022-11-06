#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, ct;

struct _edge {
    int x, a, b, i;
    _edge() {}
    _edge(int x, int a, int b) : x(x), a(a), b(b) {}
    _edge(int x, int a, int b, int i) : x(x), a(a), b(b), i(i) {}
    pll getPll() const {
        return pll(a, b);
    }
};
vector<_edge> tpEdge[100001];
vector<_edge> child[100001];
vector<_edge> edge[200001];

void addVertex(const vector<_edge> &eg, int s, int e, int p) {
    if (e <= s + 1) {
        for (int i = s; i <= e; ++i) {
            edge[p].emplace_back(eg[i].x, eg[i].a, eg[i].b, ++ct);
            edge[eg[i].x].emplace_back(p, eg[i].a, eg[i].b, ct);
        }
        return;
    }
    int x = ++n;
    int y = eg[s].x;
    
    edge[x].emplace_back(p, 0, 0, ++ct);
    edge[p].emplace_back(x, 0, 0, ct);
    edge[y].emplace_back(p, eg[s].a, eg[s].b, ++ct);
    edge[p].emplace_back(y, eg[s].a, eg[s].b, ct);
    addVertex(eg, s + 1, e, x);
}

void addVertex(int x, int p) {
    for (_edge i : tpEdge[x]) {
        if (i.x == p) continue;
        child[x].push_back(i);
    }
    addVertex(child[x], 0, child[x].size() - 1, x);
    for (_edge i : child[x]) {
        addVertex(i.x, x);
    }
}

int sz[200001];
int del[200001];
void dfsSz(int x, int p) {
    sz[x] = 1;
    for (_edge i : edge[x]) {
        if (i.x == p || del[i.i]) continue;
        dfsSz(i.x, x);
        sz[x] += sz[i.x];
    }
}

pll operator+(pll i, pll j) {
    i.first += j.first;
    i.second += j.second;
    return i;
}

llong get(pll l, int x) {
    return l.first * x + l.second;
}

vector<pll> push[2];
void dfsPush(int x, int p, pll s, int it) {
    int leaf = 1;
    for (_edge i : edge[x]) {
        if (i.x == p || del[i.i]) continue;
        leaf = 0;
        dfsPush(i.x, x, s + i.getPll(), it);
    }
    if (leaf) push[it].push_back(s);
}

ld intersect(pll i, pll j) {
    return (ld)(i.second - j.second) / (j.first - i.first);
}

void sortPush(vector<pll> &v) {
    sort(v.begin(), v.end());
    vector<pll> a;
    for (pll i : v) {
        if (!a.empty() && a.back().second <= i.second) a.pop_back();
        a.push_back(i);
    }
    v.clear();
    for (pll i : a) {
        int sz;
        while ((sz = v.size()) > 1 && intersect(v[sz - 1], i) < intersect(v[sz - 2], v[sz - 1]))
            v.pop_back();
        v.push_back(i);
    }
}

vector<pll> pushTree;
void addPushSum() {
    sortPush(push[0]);
    sortPush(push[1]);
    
    for (int i = 0, j = 0; i + 1 < push[0].size() || j + 1 < push[1].size(); ) {
        pushTree.push_back(push[0][i] + push[1][j]);
        if (i == push[0].size() - 1) ++j;
        else if (j == push[1].size() - 1) ++i;
        else if (intersect(push[0][i], push[0][i + 1]) < intersect(push[1][j], push[1][j + 1])) ++i;
        else ++j;
    }
    pushTree.push_back(push[0].back() + push[1].back());
    
    push[0].clear();
    push[1].clear();
}

void centroid(int x) {
    dfsSz(x, 0);
    if (sz[x] <= 1) return;
    
    {
        int p = 0, loop = 1, S = sz[x];
        while (loop) {
            loop = 0;
            for (_edge i : edge[x]) {
                if (i.x == p || del[i.i]) continue;
                if (S < (sz[i.x] << 1)) {
                    p = x;
                    x = i.x;
                    loop = 1;
                    break;
                }
            }
        }
    }
    int c = 0;
    for (_edge i : edge[x]) {
        if (del[i.i]) continue;
        if (sz[c] < sz[i.x]) c = i.x;
    }
    _edge e;
    for (_edge i : edge[x]) {
        if (i.x == c) e = i;
    }
    dfsPush(x, c, pll(0, 0), 0);
    dfsPush(c, x, e.getPll(), 1);
    addPushSum();
    del[e.i] = 1;
    centroid(x);
    centroid(c);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        tpEdge[u].emplace_back(v, a, b);
        tpEdge[v].emplace_back(u, a, b);
	}
	addVertex(1, 0);
	centroid(1);
	pushTree.emplace_back(0, 0);
	sortPush(pushTree);
	for (int i = 0, j = 0; i < m; ++i) {
        while (j + 1 < pushTree.size() && get(pushTree[j], i) < get(pushTree[j + 1], i)) ++j;
        printf("%lld ", get(pushTree[j], i));
	}
	return 0;
}