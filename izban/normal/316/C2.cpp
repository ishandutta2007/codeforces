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

const int maxn = 80;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct edge {
	int from, to, cost, cap, flow;

	edge() {}
	edge(int from, int to, int cost, int cap) : from(from), to(to), cost(cost), cap(cap), flow(0) {}
};

int n, m;
int a[maxn][maxn], num[maxn][maxn];
vector<int> e[maxn * maxn + 2];
vector<edge> edges;

bool reading() {
	if (!(cin >> n >> m)) return 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	return 1;
}

bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}


void addedge(int from, int to, int cost, int cap) {
	e[from].push_back(edges.size());
	edges.push_back(edge(from, to, cost, cap));
}

void add(int u, int v, int cost) {
	addedge(u, v, cost, 1);
	addedge(v, u,-cost, 0);
	addedge(v, u, cost, 1);
	addedge(u, v,-cost, 0);
}

void makegraph() {
	srand(13);
	edges.clear();
	for (int i = 0; i < n * m + 2; i++) e[i].clear();

	vector<pair<int, int> > ffuu;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ffuu.push_back(make_pair(i, j));
	random_shuffle(ffuu.begin(), ffuu.end());
	int cnt[2] = {0};
	for (int i = 0; i < ffuu.size(); i++) num[ffuu[i].first][ffuu[i].second] = ++cnt[(ffuu[i].first + ffuu[i].second) & 1];
	//int cnt[2] = {0};
	//for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) num[i][j] = ++cnt[(i + j) & 1];

	for (int i = 1; i <= cnt[0]; i++) add(0, i, 0);
	for (int i = 1; i <= cnt[1]; i++) add(cnt[0] + i, cnt[0] + cnt[1] + 1, 0);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if ((i + j) % 2 == 1) for (int k = 0; k < 4; k++) if (ok(i + dx[k], j + dy[k])) add(num[i][j], cnt[0] + num[i + dx[k]][j + dy[k]], a[i][j] != a[i + dx[k]][j + dy[k]]);
}

vector<int> d, p, id;

bool bfs2() {
	d.assign(n * m + 2, inf);
	p.assign(n * m + 2, -1);
	id.assign(n * m + 2, 0);
	d[0] = 0;
	deque<int> q;
	q.push_back(0);
	id[0] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		id[v] = 2;
		for (int i = 0; i < e[v].size(); i++) {
			edge &cur = edges[e[v][i]];
			if (d[cur.to] > d[v] + cur.cost && cur.flow < cur.cap) {
				d[cur.to] = d[v] + cur.cost;
				p[cur.to] = e[v][i];
				if (id[cur.to] == 0) 
					q.push_back(cur.to);
				if (id[cur.to] == 2)
					q.push_front(cur.to);
				id[cur.to] = 1;
			}
		}
	}
	return p[n * m + 1] != -1;
}

bool bfs() {
	d.assign(n * m + 2, inf);
	p.assign(n * m + 2, -1);
	d[0] = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int v = q.front().first, dist = q.front().second;
		q.pop();
		if (dist != d[v]) continue;
		for (int i = 0; i < e[v].size(); i++) {
			edge cur = edges[e[v][i]];
			if (d[cur.to] > d[v] + cur.cost && cur.flow < cur.cap) {
				d[cur.to] = d[v] + cur.cost;
				p[cur.to] = e[v][i];
				q.push(make_pair(cur.to, d[cur.to]));
			}
		}
	}
	return p[n * m + 1] != -1;
}

int c[maxn * maxn + 2];

bool dijkstra() {
	d.assign(n * m + 2, inf);
	p.assign(n * m + 2, -1);
	set<pair<int, int> > st;
	d[0] = 0;
	for (int i = 0; i <= n * m + 1; i++) st.insert(make_pair(d[i], i));

	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (int i = 0; i < e[v].size(); i++) {
			edge cur = edges[e[v][i]];
			if (cur.flow == cur.cap) continue;
			if (d[cur.to] > d[v] + cur.cost + c[v] - c[cur.to]) {
				st.erase(make_pair(d[cur.to], cur.to));
				d[cur.to] = d[v] + cur.cost + c[v] - c[cur.to];
				p[cur.to] = e[v][i];
				st.insert(make_pair(d[cur.to], cur.to));
			}
		}
	}
	return p[n * m + 1] != -1;
}

int mincost() {
	for (int i = 0; i < n * m + 2; i++) c[i] = 0;
	int ans = 0;
	while (bfs2()) {
		ans += d[n * m + 1];// + c[n * m + 1];
		//for (int i = 0; i < n * m + 2; i++) c[i] += d[i];
		int v = n * m + 1;
		while (v) {
			edges[p[v]].flow += 1;
			edges[p[v]^1].flow -= 1;
			v = edges[p[v]].from;
		}
	}
	return ans;
}

int fastsolve() {
	makegraph();
	return mincost();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	
	while (reading()) printf("%d\n", fastsolve());

	return 0;
}