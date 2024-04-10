//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 8080;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, d[maxn], ans, q[maxn], p[maxn], inn[maxn], bd[maxn], vis[maxn];
bitset<maxn> g[maxn];
queue<ll> qu;

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n / 4; j++){
			char c;
			cin >> c;
			ll x = (c - '0');
			if('A' <= c && c <= 'F') x = 10 + (c - 'A');
			for(ll k = 4; k--;){
				d[(j << 2) + k] += (g[i][(j << 2) + k] = (x & 1));
				x >>= 1;
			}
		}
	}
	ll t = n - 1;
	for(ll i = 0; i < n; i++){
		if(d[i] == 0 || d[i] == t){
			qu.push(i);
			vis[i] = 1;
		}
	}
	while(!qu.empty()){
		ll v = qu.front();
		qu.pop();
		bd[v] = 1;
		ans += (614 * n + 1) * t;
		t--;
		for(ll i = 0; i < n; i++){
			if(bd[i]) continue;
			if(g[v][i]){
				d[i]--;
			}
			if(!vis[i] && (d[i] == 0 || d[i] == t)){
				qu.push(i);
				vis[i] = 1;
			}
		}
	}
	
	ll x = -1;
	for(ll i = 0; i < n; i++){
		if(!bd[i] && (x == -1 || d[x] < d[i])) x = i;
	}
	for(ll i = 0; i < n; i++){
		if(bd[i]) continue;
		if(g[x][i]) q[i] = 1;
		else p[i] = 1;
	}
	for(ll i = 0; i < n; i++){
		if(bd[i]) continue;
		for(ll j = 0; j < n; j++){
			if(bd[j]) continue;
			if(g[i][j] && (q[i] ^ q[j])){
				inn[j]++;
			}
		}
	}
	for(ll i = 0; i < n; i++){
		if(bd[i]) continue;
		for(ll j = i + 1; j < n; j++){
			if(bd[j]) continue;
			if(p[i]){
				if(p[j]) ans += 3 + (inn[i] == inn[j]);
				else ans += 3;
			}
			else{
				if(q[j]) ans += 3 + (inn[i] == inn[j]);
				else ans += 3;
			}
		}
	}
	cout << ans;
	
	
	return 0;
}