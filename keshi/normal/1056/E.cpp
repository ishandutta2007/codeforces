//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
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

ll n, m, p[cmod][maxn], dp[cmod][maxn], a, b, ca, cb, f, ans, o;

string t, s;

ll get(ll l, ll r, ll m){
	return ((dp[m][r] - dp[m][l] * p[m][r - l]) % mod[m] + mod[m]) % mod[m];
}

int main(){
	fast_io;
	for(ll c = 0; c < cmod; c++){
		p[c][0] = 1;
		for(ll i = 1; i < maxn; i++){
			p[c][i] = (p[c][i - 1] * 31) % mod[c];
		}
	}
	
	cin >> t >> s;
	m = t.size();
	for(ll i = 0; i < m; i++){
		if(t[i] == '0') ca++;
		else cb++;
	}
	n = s.size();
	s = ' ' + s;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < cmod; j++){
			dp[j][i] = (dp[j][i - 1] * 31 + (s[i] - 'a')) % mod[j];
		}
	}
	for(ll i = 1; i < n; i++){
		if(i * ca < n && (n - i * ca) % cb == 0){
			ll j = (n - i * ca) / cb;
			f = 1;
			for(ll c = 0; c < cmod; c++){
				o = 0;
				a = b = -1;
				for(ll k = 0; k < m; k++){
					if(t[k] == '0'){
						if(a == -1) a = get(o, o + i, c);
						if(get(o, o + i, c) != a) f = 0;
						o += i;
					}
					else{
						if(b == -1) b = get(o, o + j, c);
						if(get(o, o + j, c) != b) f = 0;
						o += j;
					}
				}
			}
			if(i == j && a == b) f = 0;
			ans += f;
		}
	}
	cout << ans;
	
	return 0;
}