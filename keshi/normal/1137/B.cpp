//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a, b, c, d, f[maxn];
string s, t;

int main(){
	fast_io;
	
	cin >> s >> t;
	n = s.size();
	m = t.size();
	for(ll i = 0; i < n; i++){
		if(s[i] == '1') a++;
		else b++;
	}
	for(ll i = 1; i < m; i++){
		ll x = f[i - 1];
		while(x && t[x] != t[i]) x = f[x - 1];
		if(t[x] == t[i]) x++;
		f[i] = x;
	}
	for(ll i = 0; i < m; i++){
		if(t[i] == '1') a--;
		else b--;
	}
	if(a < 0 || b < 0){
		cout << s;
		return 0;
	}
	for(ll i = f[m - 1]; i < m; i++){
		if(t[i] == '1') c++;
		else d++;
	}
	cout << t;
	while(a >= c && b >= d){
		a -= c;
		b -= d;
		for(ll i = f[m - 1]; i < m; i++){
			cout << t[i];
		}
	}
	while(a--) cout << 1;
	while(b--) cout << 0;
	
	return 0;
}