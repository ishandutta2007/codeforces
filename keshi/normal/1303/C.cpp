//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, x, p, c, y;

bool g[30][30], vis[30], f;

string s, e;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		for(ll i = 0; i < 26; i++){
			vis[i] = 0;
			fill(g[i], g[i] + 26, 0);
		}
		cin >> s;
		n = s.size();
		if(n == 1){
			cout << "YES\n";
			for(ll i = 0; i < 26; i++){
				if(!vis[i]) cout << char('a' + i);
			}
			cout << '\n';
			continue;
		}
		for(ll i = 0; i + 1 < n; i++){
			g[s[i] - 'a'][s[i + 1] - 'a'] = 1;
			g[s[i + 1] - 'a'][s[i] - 'a'] = 1;
		}
		f = 0;
		x = -1;
		for(ll i = 0; i < 26; i++){
			if(g[i][i]) f = 1;
			c = 0;
			for(ll j = 0; j < 26; j++){
				if(g[i][j]) c++;
			}
			if(c > 2) f = 1;
			if(c == 1) x = i;
		}
		if(f || x == -1){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		p = -1;
		while(true){
			cout << char('a' + x);
			vis[x] = 1;
			y = -1;
			for(ll i = 0; i < 26; i++){
				if(g[x][i] && i != p) y = i;
			}
			if(y == -1) break;
			p = x;
			x = y;
		}
		for(ll i = 0; i < 26; i++){
			if(!vis[i]) cout << char('a' + i);
		}
		cout << '\n';
	}
	
	return 0;
}