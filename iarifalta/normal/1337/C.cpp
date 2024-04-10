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

const ll N = 2e5 + 10;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll n, k;

vector<ll> g[N];

ll pr[N];

set<pill> FindAns;

ll dfs(ll v = 1, ll p = -1, ll gl = 0) {
	pr[v] = gl;
	ll sz = 0;
	for(auto u : g[v])
		if(u != p)
			sz += dfs(u, v, gl + 1);
	pr[v] -= sz;
	return sz + 1;
}

int main() {
    speed;
	cin >> n >> k;
	rep(1, n, 1){
		ll a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs();
	sort(pr + 1, pr + 1 + n);
	ll ans = 0;
	for(int i = n ; i > n - k; i--)
		ans += pr[i];
	cout << ans;
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/