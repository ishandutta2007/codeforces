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

ll b, c, x, p[10], ans;

string s, t;

vector<ll> g;

int main(){
	fast_io;
	
	cin >> s >> t >> c;
	
	for(ll i = 0; i < s.size(); i++){
		b = (b * 10 + (s[i] - '0')) % c;
	}
	
	p[0] = 1;
	for(ll i = 1; i < 10; i++){
		p[i] = (p[i - 1] * b) % c;
	}
	
	for(ll i = 0; i < t.size(); i++){
		g.pb(t[i] - '0');
	}
	
	for(ll i = 1; i <= g.size(); i++){
		g[g.size() - i]--;
		if(g[g.size() - i] == -1) g[g.size() - i] = 9;
		else break;
	}
	
	ans = 1;
	
	for(ll i = 0; i < g.size(); i++){
		x = 1;
		for(ll j = 0; j < 10; j++){
			x = (x * ans) % c;
		}
		ans = (x * p[g[i]]) % c;
	}
	
	ans = (ans * (b - 1)) % c;
	ans = (ans + c) % c;
	if(ans == 0) ans = c;
	cout << ans;
	
	return 0;
}