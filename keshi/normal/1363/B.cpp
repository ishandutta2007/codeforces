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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, x, p, ans;
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> s;
		x = p = 0;
		n = s.size();
		for(ll i = 0; i < n; i++){
			if(s[i] == '0') x++;
		}
		ans = inf;
		for(ll i = 0; i < n; i++){
			ans = min(ans, x + p);
			if(s[i] == '1') p++;
			else x--;
		}
		ans = min(ans, x + p);
		x = p = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] == '1') x++;
		}
		for(ll i = 0; i < n; i++){
			ans = min(ans, x + p);
			if(s[i] == '0') p++;
			else x--;
		}
		ans = min(ans, x + p);
		cout << ans << '\n';
	}
	
	return 0;
}