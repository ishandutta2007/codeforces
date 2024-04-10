//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll t, n, m, c[maxn];
pll q[maxn];
bool vis[maxn];
string s[maxn];

inline ll get(ll x, ll y){
	return x * m + y;
}
inline pll pget(ll x){
	return Mp(x / m, x % m);
}
inline bool ok(ll x, ll y){
	if(0 > x || x >= n || 0 > y || y >= m) return 0;
	return (s[x][y] != '#');
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		fill(c, c + n * m + 10, 0);
		fill(vis, vis + n * m + 10, 0);
		for(ll i = 0; i < n; i++){
			cin >> s[i];
		}
		ll l = 0, r = 0;
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				ll k = get(i, j);
				if(s[i][j] == 'L'){
					vis[k] = 1;
					q[r++] = Mp(i, j);
				}
				if(ok(i - 1, j)) c[k]++;
				if(ok(i + 1, j)) c[k]++;
				if(ok(i, j - 1)) c[k]++;
				if(ok(i, j + 1)) c[k]++;
			}
		}
		while(l < r){
			ll x = q[l].F, y = q[l].S;
			l++;
			if(ok(x - 1, y)){
				ll u = get(x - 1, y);
				if(!vis[u]){
					c[u]--;
					if(c[u] <= 1){
						q[r++] = Mp(x - 1, y);
						vis[u] = 1;
					}
				}
			}
			if(ok(x + 1, y)){
				ll u = get(x + 1, y);
				if(!vis[u]){
					c[u]--;
					if(c[u] <= 1){
						q[r++] = Mp(x + 1, y);
						vis[u] = 1;
					}
				}
			}
			if(ok(x, y - 1)){
				ll u = get(x, y - 1);
				if(!vis[u]){
					c[u]--;
					if(c[u] <= 1){
						q[r++] = Mp(x, y - 1);
						vis[u] = 1;
					}
				}
			}
			if(ok(x, y + 1)){
				ll u = get(x, y + 1);
				if(!vis[u]){
					c[u]--;
					if(c[u] <= 1){
						q[r++] = Mp(x, y + 1);
						vis[u] = 1;
					}
				}
			}
		}
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				if(s[i][j] == '.' && vis[get(i, j)]) s[i][j] = '+';
			}
			cout << s[i] << "\n";
		} 
	}
	
	return 0;
}