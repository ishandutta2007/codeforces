//#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int MAXN = (1 << 20);
struct dsu
{
	int sz;
	vector<int> par, psz;

	void init(int n)
	{
		sz = n;
		par.assign(sz + 1, 0);
		psz.assign(sz + 1, 0);
		for(int i = 0; i <= sz; i++)
			par[i] = i, psz[i] = 1;
	}

	int root(int u) { return par[u] = ((u == par[u]) ? u : root(par[u])); }

	bool connected(int x, int y) { return root(x) == root(y); }

	void unite(int x, int y)
	{
		x = root(x), y = root(y);
		if(x == y) return;
		if(psz[x] > psz[y]) swap(x, y);
		par[x] = y, psz[y] += psz[x];
	}
};
dsu d;
void move(vi x) {
	if(x.empty()) return;
	cout << "next ";
	for(auto i :x) cout << i << " ";
	cout << endl;
	int k;
	cin >> k;
	string t;
	d.init(10);
	while(k--) {
		cin >> t;
		for(int i = 1; i < t.size(); i++) {
			d.unite(t[i]-'0', t[i-1]-'0');
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	d.init(10);
	while(!d.connected(0, 1)) {//2(l+r)
		move({0, 1});
		move({1});
	}
	vi gg;
	for(int i = 0; i < 10; i++) gg.pb(i);
	while(!d.connected(0, 2)) {
		move(gg);
	}
	while(true) {
		vi t;
		for(int i = 0; i < 10; i++) if(!d.connected(2, i)) t.pb(i);
		if(t.empty()) break;
		move(t);
	}
	cout << "done" << endl;
}