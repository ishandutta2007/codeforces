#include<bits/stdc++.h>
#define log 20
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
int n, m;
vvi g;
vi p;
vector<bool> ans;
vi tin, tout;
vi score;
int needscore = 0;
vvi up;
int timer = 0;

int get_p(int v) {
	if(p[v] == v) return v;
	int par = get_p(p[v]);
	p[v] = par;
	return par;
}

int eq(int a, int b) {
	return get_p(a) == get_p(b);
}

void join(int a, int b) {
	a = get_p(a);
	b = get_p(b);
	p[a] = b;
}

void dfs(int v, int p) {
	tin[v] = timer++;
	up[v][0] = p;
	for(int i = 1; i < log; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for(const auto& u : g[v]) {
		if(u == p) continue;
		dfs(u, v);
	}
	tout[v] = timer++;
}

bool upper(int v, int u) {
	return tin[v] <= tin[u] && tout[v] >= tout[u];
}

void dfs1(int v, int p, int curr) {
	curr += score[v];
	if(curr != needscore) ans[v] = false;
	for(const auto& u : g[v]) {
		if(u == p) continue;
		dfs1(u, v, curr);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;
	g.resize(n);
	tin.resize(n);
	tout.resize(n);
	score.assign(n, 0);
	up.assign(n, vi(log));
	p.resize(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	ans.assign(n, true);
	vector<pair<int, int>> e(m);
	vector<bool> ok(m, false);
	for(int i = 0; i < m; i++) {
		cin >> e[i].first >> e[i].second;
		--e[i].first;
		--e[i].second;
		if(eq(e[i].first, e[i].second)) {

		} else {
			join(e[i].first, e[i].second);
			g[e[i].first].push_back(e[i].second);
			g[e[i].second].push_back(e[i].first);
			ok[i] = true;
		}
	}
	dfs(0, 0);
	for(int i = 0; i < m; i++) {
		if(!ok[i]) {
			needscore++;
			int v = e[i].first;
			int u = e[i].second;
			if(upper(u, v)) swap(v, u);
			if(upper(v, u)) {
				score[0]++;
				score[u]++;
				for(int i = log - 1; i >= 0; i--) {
					int now = up[u][i];
					if(!upper(now, v)) u = now;
				}
				score[u]--;
			} else {
				score[v]++;
				score[u]++;
			}
		}
	}
	dfs1(0, -1, 0);
	for(int i = 0; i < n; i++) {
		if(ans[i]) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
}