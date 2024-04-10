//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans, x, dp[maxn];

vector<pair<ll, char> > a, b, s;

string st;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> st;
		x = 0;
		for(ll i = 0; i < st.size() - 2; i++){
			x = x * 10 + (st[i] - '0');
		}
		if(a.empty() || a.back().S != st[st.size() - 1]) a.pb(Mp(x, st[st.size() - 1]));
		else a.back().F += x;
	}
	for(ll i = 0; i < m; i++){
		cin >> st;
		x = 0;
		for(ll i = 0; i < st.size() - 2; i++){
			x = x * 10 + (st[i] - '0');
		}
		if(b.empty() || b.back().S != st[st.size() - 1]) b.pb(Mp(x, st[st.size() - 1]));
		else b.back().F += x;
	}
	n = a.size();
	m = b.size();
	if(m == 1){
		for(ll i = 0; i < n; i++){
			if(a[i].S == b[0].S) ans += max(0ll, a[i].F - b[0].F + 1);
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		for(ll i = 0; i + 1 < n; i++){
			if(a[i].S == b[0].S && a[i + 1].S == b[1].S && a[i].F >= b[0].F && a[i + 1].F >= b[1].F) ans++;
		}
		cout << ans;
		return 0;
	}
	for(ll i = 1; i + 1 < m; i++){
		s.pb(b[i]);
	}
	s.pb(Mp(-1ll, ' '));
	for(ll i = 0; i < n; i++){
		s.pb(a[i]);
	}
	for(ll i = 1; i < s.size(); i++){
		ll j = dp[i - 1];
		while(j && s[i] != s[j]) j = dp[j - 1];
		if(s[i] == s[j]) j++;
		dp[i] = j;
	}
	
	for(ll i = 1; i + m - 2 < n; i++){
		if(dp[i + 2 * m - 4] >= m - 2 && a[i - 1].S == b[0].S && a[i - 1].F >= b[0].F && a[i + m - 2].S == b.back().S && a[i + m - 2].F >= b.back().F) ans++;
	}
	cout << ans;
	
	return 0;
}