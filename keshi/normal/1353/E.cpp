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

ll q, n, k, c, t, d, x, ans;
string s;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n >> k >> s;
		c = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] == '1') c++;
		}
		ans = c;
		for(ll i = 0; i < k; i++){
			t = x = 0;
			d = inf;
			for(ll j = i; j < n; j += k){
				if(s[j] == '1') t--;
				else t++;
				d = min(d, t - x);
				x = max(x, t);
			}
			ans = min(ans, c + d);
		}
		cout << ans << '\n';
	}
	
	return 0;
}