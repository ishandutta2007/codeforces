#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000007;

struct edge {
	int u, v, c, ans;

	int another(int x) {
		if (u == x) return v;
		else return u;
	}

	edge() {}
	edge(int v, int u, int c, int ans) : v(v), u(u), c(c), ans(ans) {}
};

int n, m;
vector<int> e[maxn];
vector<edge> edges;
int balance[maxn];
set<pair<int, int> > st;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		e[v].push_back(edges.size());
		e[u].push_back(edges.size());
		edges.push_back(edge(u, v, c, -1));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			balance[i] += edges[e[i][j]].c;
		}
		if (i == 1) balance[i] = 0;
		if (i == n) balance[i] = 2 * inf;
		st.insert(make_pair(balance[i], i));
	}

	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (int i = 0; i < e[v].size(); i++) {
			edge cur = edges[e[v][i]];
			int to = cur.another(v);
			if (cur.ans != -1) continue;
			edges[e[v][i]].ans = cur.v != v;
			st.erase(make_pair(balance[to], to));
			balance[to] -= 2 * cur.c;
			st.insert(make_pair(balance[to], to));
		}
	}

	for (int i = 0; i < m; i++)
		cout << edges[i].ans << endl;

	return 0;
}