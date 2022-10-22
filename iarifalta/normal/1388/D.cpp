#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 2E5 + 10;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll t;
ll n;
vector<ll> g[N];
ll a[N], b[N];
ll gl[N];
ll up[N];

void dfs(ll v, ll p) {
	if(v)
		gl[v] = gl[p] + 1;
	for(auto u : g[v])
		if(u != p) {
			dfs(u, v);
		}	
}

int main() {
	speed;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		if(b[i] == -1)
			b[i] = 0;
		g[b[i]].pb(i);
	}
	dfs(0, 0);
	vector<pill> sub1, sub2;
	for(int i = 1; i <= n; i++)
		sub1.pb({gl[i], i});
	sort(all(sub1));
	reverse(all(sub1));
	vector<ll> ans;
	ll answ = 0;
	for(auto u : sub1) {
		a[u.s] += up[u.s];
		if(a[u.s] < 0) {
			sub2.pb(u);
			up[u.s] = 0;
		}
		else {
			up[b[u.s]] += a[u.s];
			answ += a[u.s];
			ans.pb(u.s);
			up[u.s] = 0;
		}
	}
	sort(all(sub2));
	for(auto u : sub2) {
		a[u.s] += up[u.s];
		answ += a[u.s];
		ans.pb(u.s);
	}
	cout << answ << '\n';
	for(auto u : ans)
		cout << u << " ";
		
}

/*

*/