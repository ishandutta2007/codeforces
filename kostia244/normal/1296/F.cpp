#pragma GCC optimize("trapv")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, col[500100];
vector<vector<pi>> g;

void read() {
	cin >> n;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb({t, i});
		g[t].pb({f, i});
	}
}
int ccnt;
bool paint(int v, int p, int t, int c) {
	if(v==t) return true;
	for(auto i : g[v]) {
		if(i.first==p) continue;
		if(paint(i.first, v, t, c)) {
			if(!col[i.second]||col[i.second]==c)
				col[i.second] = c, ccnt++;
			return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	int m;
	vector<pair<int, pair<int, int>>> a;
	cin >> m;
	a.resize(m);
	for(auto &i : a) cin >> i.second.first >> i.second.second >> i.first;
	sort(rall(a));
	for(auto i : a) {
		ccnt = 0;
		paint(i.second.first, -1, i.second.second, i.first);
		if(ccnt==0)
			return cout << -1, 0;
	}
	for(int i = 1; i < n; i++)
		cout << max(col[i], 1) << " ";
	return 0;
}