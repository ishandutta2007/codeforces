#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n, sol, val, curr;
vector <int> v[MAXN];
llint par[MAXN], siz[MAXN];

void dfs (int x, int rod) {
	par[x] = rod;
	siz[x] = 1;
	for (auto sus : v[x]) {
		if (sus == rod) continue;
		dfs(sus, x);
		siz[x] += siz[sus];
	}
}

void rjesi (int x) {
	sol = max(sol, curr);
	for (auto sus : v[x]) {
		if (sus == par[x]) continue;
		curr += siz[1] - 2*siz[sus];
		rjesi(sus);
		curr -= siz[1] - 2*siz[sus];
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	for (int i=1; i<=n; i++) {
		val += siz[i];
	}
	curr = val;
	rjesi(1);
	cout << sol;
	return 0;
}