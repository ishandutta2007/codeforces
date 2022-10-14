#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define all(a) begin(a), end(a)
#define K first
#define V second
#define N 200010
#define L 20

vector<ll> graph[N];
ll par[N][L], u[N], v[N], dep[N];

void dfs(ll i, ll p) {
	par[i][0] = p;
	dep[i] = dep[p] + 1;
	F(l, 1, L) par[i][l] = par[par[i][l - 1]][l - 1];
	for(ll j : graph[i]) if(!par[j][0]) dfs(j, i);
}

ll lca(ll a, ll b) {
	if(dep[a] < dep[b]) swap(a, b);
	FD(l, L - 1, -1) if((dep[a] - dep[b]) >> l) a = par[a][l];
	if(a == b) return a;
	FD(l, L - 1, -1) if(par[a][l] - par[b][l]) a = par[a][l], b = par[b][l];
	return par[a][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(n) G(m) G(s)
	F(i, 0, m) {
		cin >> u[i] >> v[i];
		graph[u[i]].push_back(v[i]);
	}
	dfs(s, s);
	F(i, 0, m) if(par[u[i]][0] && par[v[i]][0] && u[i] != par[v[i]][0] && v[i] != s && lca(u[i], v[i]) == s) {
		vector<ll> v1, v2;
		while(u[i] != s) {
			v1.push_back(u[i]);
			u[i] = par[u[i]][0];
		}
		v1.push_back(s); reverse(all(v1)); v1.push_back(v[i]);
		while(v[i] != s) {
			v2.push_back(v[i]);
			v[i] = par[v[i]][0];
		}
		v2.push_back(s); reverse(all(v2));
		cout << "Possible\n";
		cout << v1.size() << '\n';
		for(ll x : v1) cout << x << ' ';
		cout << '\n';
		cout << v2.size() << '\n';
		for(ll x : v2) cout << x << ' ';
		cout << '\n';
		exit(0);
	}
	cout << "Impossible\n";
}