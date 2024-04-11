#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
//using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
	ll cst, u;
	node(ll cc = 1e9, ll uu = -1) {
		cst = cc, u = uu;
	}
	bool operator<(const node &rhs) const {
		return pair<ll ,ll>(cst, u) > pair<ll, ll>(rhs.cst, rhs.u);
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	vi c, k, el, p;
	vector<pair<ll, ll>> co;
	cin >> n;
	co.resize(n);
	for(auto &i : co) cin >> i.first >> i.second;
	c.resize(n);
	el.resize(n, 0);
	k.resize(n);
	p.resize(n, -1);
	for(auto& i : c) cin >> i;
	for(auto& i : k) cin >> i;
	priority_queue<node> a;
	for(int i = 0; i < n; i++)
		a.push(node(c[i], i));
	ll ans = 0;
	while(!a.empty()) {
		node t = a.top();
		a.pop();
		if(t.cst > c[t.u]||el[t.u]) continue;
		el[t.u] = 1;
		ans += t.cst;
		for(int i = 0; i < n; i++) {
			ll w = (k[i] + k[t.u])*(abs(co[i].first-co[t.u].first)+abs(co[i].second-co[t.u].second));
			if(w < c[i]&&!el[i]) {
				p[i] = t.u;
				c[i] = w;
				a.push({c[i], i});
			}
		}
	}
	vector<int> u;
	vector<pair<int, int>> z;
	for(int i = 0; i < n; i++)if(p[i]==-1)u.pb(i+1);
	else z.pb({p[i]+1, i+1});
	cout << ans << "\n";
	cout << u.size() << "\n";
	for(auto i : u) cout << i << " ";
	cout << "\n" << z.size() << "\n";
	for(auto i : z) cout << i.first << " " << i.second << "\n";
}