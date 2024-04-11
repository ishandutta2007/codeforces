#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
template<typename T>
using ordset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m, t = 0;
vector<int> g[100100];
map<int, int> cnt[100100], frq[100100];

vector<pair<int, int>> queries[100100];
vi answers, col;

void dfs(int v, int p) {
	for(auto i : g[v]) {
		if(i == p) continue;
		dfs(i, v);
		if(cnt[i].size()>cnt[v].size()) {
			swap(cnt[v], cnt[i]);
			swap(frq[v], frq[i]);
		}
	}
	for(auto i : g[v]) {
		if(i == p) continue;
		for(auto j : cnt[i]) {
			frq[v][cnt[v][j.first]]--;
			cnt[v][j.first]+=j.second;
			frq[v][cnt[v][j.first]]++;
		}
	}
	frq[v][cnt[v][col[v]]]--;
	cnt[v][col[v]]++;
	frq[v][cnt[v][col[v]]]++;
	int S = 0;
	for(auto i : frq[v]) S+=i.second;
	int qi = 0;
	for(auto i : frq[v]) {
		if(qi >= queries[v].size()) break;
		while(qi < queries[v].size() && i.first >= queries[v][qi].first)
			answers[queries[v][qi++].second] = S;
//		cout << v << " " << i.first << " " << i.second << " " << qi << " " << S << "v\n";
		S-=i.second;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	col.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> col[i];
	for(int f, t, i = 1; i <n ; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int v, k;
	for(int i = 0; i < m; i++) {
		cin >> v >> k;
		queries[v].pb({k, i});
	}

	for(int i = 1; i <= n; i++) {
		sort(all(queries[i]));
	}

	answers.resize(m);
	dfs(1, 1);

	for(auto i : answers) cout << i << " ";
}