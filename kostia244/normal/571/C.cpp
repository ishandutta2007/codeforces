#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1<<19, maxk = 5050, mod = 1e9 + 7;
ll n, m, deg[maxn], f[maxn];
vector<int> cl[maxn], to[maxn];

void decr(int);
int satisfied[maxn];
void notify(int v) {
	if(satisfied[v]) return;
	satisfied[v] = 1;
	for(auto &j : cl[v]) {
		deg[j]--;
		decr(j);
	}
}
void decr(int x) {
	if(f[x] || f[x^1]) return;
	if(deg[x]^deg[x^1]) {
		if(deg[x^1]) x ^= 1;
		f[x] = 1;
		for(auto &i : to[x]) notify(i);
	}
}

int unset[maxn];
void solve() {
	for(int i = 0; i < 2*m; i+=2) decr(i);
	
	set<pair<int, int>> q;
	for(int i = 0; i < n; i++) {
		if(satisfied[i]) continue;
		for(auto j : cl[i]) unset[i] += f[j]+f[j^1]==0;
		q.insert({unset[i], i});
	}
	while(!q.empty()) {
		int v = q.begin()->second;
		satisfied[v] = 1;
		q.erase(q.begin());
		if(unset[v] == 0) {cout << "NO\n", exit(0);}
		int p = -1;
		for(auto &i : cl[v]) {
			if(f[i]+f[i^1]==0) p = i;
		}
		f[p] = 1;
		p = to[p^1][0];
		if(satisfied[p]) continue;
		q.erase({unset[p], p});
		q.insert({--unset[p], p});
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cl[i].resize(t);
		for(auto &j : cl[i]) {
			cin >> j;j = 2*abs(j) + (j<0) - 2;
			to[j].push_back(i);
			deg[j]++;
		}
	}
	solve();
	cout << "YES\n";
	for(int i = 0; i < m; i++) cout << f[2*i]; cout << endl;
}