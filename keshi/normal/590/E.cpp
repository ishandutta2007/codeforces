//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 800;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll maxm = 1e7 + 100;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll n, t, nxt[maxm][2], g[maxm][2], par[maxm], f[maxm], a[maxn], b[maxm], q[maxm];
bool gg[maxn][maxn];
string s[maxn];
ll match[2][maxn], mark[maxn << 1];

void bld(){
	ll l = 0, r = 0;
	q[r++] = 0;
	while(l < r){
		ll v = q[l++];
		if(b[v]) f[v] = v;
		else f[v] = f[par[v]];
		for(ll i = 0; i < 2; i++){
			if(g[v][i]){
				nxt[v][i] = g[v][i];
				if(v) par[nxt[v][i]] = nxt[par[v]][i];
				q[r++] = nxt[v][i];
			}
			else{
				nxt[v][i] = nxt[par[v]][i];
			}
		}
	}
	return;
}

bool dfs(ll v, ll j){
	if(mark[v] == j) return 0;
	mark[v] = j;
	for(ll u = 1; u <= n; u++){
		if(!gg[v][u]) continue;
		if(match[1][u] == -1 || dfs(match[1][u], j)){
			match[1][u] = v;
			match[0][v] = u;
			return 1;
		}
	}
	return 0;
}

bool bd[maxn], db[maxn];

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> s[i];
		ll x = 0;
		for(char c : s[i]){
			if(!g[x][c - 'a']) g[x][c - 'a'] = ++t;
			x = g[x][c - 'a'];
		}
		a[i] = x;
		b[x] = i;
	}
	bld();
	for(ll i = 1; i <= n; i++){
		ll x = 0;
		for(char c : s[i]){
			x = g[x][c - 'a'];
			ll j = f[x];
			while(j && !gg[i][b[j]]){
				gg[i][b[j]] = 1;
				j = f[par[j]];
			}
		}
		gg[i][i] = 0;
	}
	
	fill(match[0], match[0] + n + 10, -1);
	fill(match[1], match[1] + n + 10, -1);
	fill(mark, mark + n + 10, -1);
	for(ll i = 1; i <= n; i++){
		dfs(i, i);
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		if(match[0][i] == -1) ans++;
	}
	fill(mark, mark + n + 10, 0);
	ll l = 0, r = 0;
	for(ll i = 1; i <= n; i++){
		if(match[0][i] == -1){
			q[r++] = i;
			mark[i] = 1;
		}
	}
	while(l < r){
		ll v = q[l++];
		if(v <= n){
			bd[v] = 1;
			for(ll u = 1; u <= n; u++){
				if(mark[u + n]) continue;
				if(gg[v][u]){
					mark[u + n] = 1;
					q[r++] = u + n;
				}
			}
			continue;
		}
		if(match[1][v - n]){
			mark[match[1][v - n]] = 1;
			q[r++] = match[1][v - n];
		}
	}
	cout << ans << "\n";
	for(ll i = 1; i <= n; i++){
		if(match[0][i] == -1) continue;
		if(bd[i]) db[match[0][i]] = 1;
		else db[i] = 1;
	}
	for(ll i = 1; i <= n; i++){
		if(!db[i]) cout << i << " ";
	}
	
	
	return 0;
}