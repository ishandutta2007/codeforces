//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e6 + 100;
const ll cmod = 2;
const ll mod[cmod] = {1000000007, 1000000009};
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, p[cmod], a[cmod], b[cmod], dp[maxn], ans;

string s;

ll cal(char c){
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'a' && c <= 'z') return c - 'a' + 10;
	return c - 'A' + 36;
}

int main(){
	fast_io;
	fill(p, p + cmod, 1);
	
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for(ll i = 1; i <= n; i++){
		bool f = 1;
		for(ll j = 0; j < cmod; j++){
			a[j] = (a[j] * 67 + cal(s[i])) % mod[j];
			b[j] = (b[j] + p[j] * cal(s[i])) % mod[j];
			p[j] = (p[j] * 67) % mod[j];
			if(a[j] != b[j]) f = 0;
		}
		if(f) dp[i] = dp[i / 2] + 1;
		ans += dp[i];
	}
	
	cout << ans;
	
	return 0;
}