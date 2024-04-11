#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119 * (1 << 23) + 1);
struct node {
	int v;
	ll cst;
	node(int v = 0, ll cst = 1e15){
		this->v=v;
		this->cst = cst;
	}
	bool operator<(const node &rhs) const {
		return cst > rhs.cst;
	}
};
void bt(int v, vi &p) {
	if(p[v] != -1) bt(p[v], p);
	cout << v << " ";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	vector<vector<pair<ll, ll>>> g;
	cin >> n >> m;
	g.resize(n+1);
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		g[f].emplace_back(t,c);
		g[t].emplace_back(f,c);
	}
	priority_queue<node> pq;
	vi dst(n+1, 1e15);
	dst[1] = 0;
	pq.push(node(1, 0));
	vi p(n+1, -1);
	while(!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		if(x.cst > dst[x.v]) continue;
		for(auto i : g[x.v]) {
			if(x.cst + i.second < dst[i.first]) {
				dst[i.first] = x.cst + i.second;
				p[i.first] = x.v;
				pq.push(node{i.first, dst[i.first]});
			}
		}
	}
	if(dst[n]==1e15)cout<<-1;
	else bt(n, p);
}