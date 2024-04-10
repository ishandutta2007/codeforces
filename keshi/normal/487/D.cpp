//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 1000;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll sq = 320;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, q, t;
pll nxt[maxn][12];
ll vis[maxn][12];
string s[maxn];

pll dfs(ll x, ll y, ll i){
	if(y < 0 || y >= m || x < sq * i || x >= sq * (i + 1)) return Mp(x, y);
	if(vis[x][y] == t){
		return nxt[x][y];
	}
	vis[x][y] = t;
	if(s[x][y] == '<') nxt[x][y] = dfs(x, y - 1, i);
	else if(s[x][y] == '>') nxt[x][y] = dfs(x, y + 1, i);
	else nxt[x][y] = dfs(x - 1, y, i);
	return nxt[x][y];
}

int main(){
	fast_io;
	
	cin >> n >> m >> q;
	for(ll i = 0; i < n; i++){
		cin >> s[i];
	}
	for(ll i = 0; sq * i < n; i++){
		t++;
		for(ll j = sq * i; j < sq * (i + 1); j++){
			fill(nxt[j], nxt[j] + 12, Mp(-2, -2));
		}
		for(ll j = sq * i; j < min(n, sq * (i + 1)); j++){
			for(ll k = 0; k < m; k++){
				dfs(j, k, i);
			}
		}
	}
	while(q--){
		char c;
		ll x, y;
		cin >> c >> x >> y;
		if(c == 'C'){
			x--;
			y--;
			cin >> s[x][y];
			ll i = x / sq;
			for(ll j = sq * i; j < sq * (i + 1); j++){
				fill(nxt[j], nxt[j] + 12, Mp(-2, -2));
			}
			t++;
			for(ll j = sq * i; j < min(n, sq * (i + 1)); j++){
				for(ll k = 0; k < m; k++){
					dfs(j, k, i);
				}
			}
		}
		else{
			x--;
			y--;
			while(0 <= x && 0 <= y && y < m){
				pll p = nxt[x][y];
				x = p.F;
				y = p.S;
			}
			cout << x + 1 << " " << y + 1 << "\n";
		}
	}
	
	return 0;
}