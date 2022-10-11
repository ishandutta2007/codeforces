//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 30;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dis[maxn][maxn], v, u, c, ans;

char c1, c2;

string s, t, d;

int main(){
	fast_io;
	
	cin >> s >> t;
	
	if(s.size() != t.size()){
		cout << -1;
		return 0;
	}
	
	for(ll i = 0; i < maxn; i++){
		fill(dis[i], dis[i] + maxn, inf);
		dis[i][i] = 0;
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> c1 >> c2 >> c;
		v = c1 - 'a';
		u = c2 - 'a';
		dis[v][u] = min(dis[v][u], c);
	}
	
	for(ll i = 0; i < 26; i++){
		for(ll j = 0; j < 26; j++){
			for(ll k = 0; k < 26; k++){
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	
	for(ll i = 0; i < s.size(); i++){
		v = s[i] - 'a';
		u = t[i] - 'a';
		c = inf;
		c1 = ' ';
		for(ll j = 0; j < 26; j++){
			if(dis[v][j] + dis[u][j] < c){
				c = dis[v][j] + dis[u][j];
				c1 = char('a' + j);
			}
		}
		if(c1 == ' '){
			cout << -1;
			return 0;
		}
		ans += c;
		d += c1;
	}
	
	cout << ans << '\n' << d;
	
	return 0;
}