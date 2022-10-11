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

ll q, n, m, x, ans, dp[30][maxn];

string s, t;

vector<ll> v[maxn];

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> s >> t;
		n = s.size();
		m = t.size();
		for(ll i = 0; i < 26; i++){
			v[i].clear();
		}
		for(ll i = 0; i < n; i++){
			v[s[i] - 'a'].pb(i);
		}
		for(ll i = 0; i < 26; i++){
			if(!v[i].empty()){
				v[i].pb(v[i][0] + n);
			}
		}
		x = -1;
		ans = 1;
		for(ll i = 0; i < m; i++){
			if(v[t[i] - 'a'].empty()){
				ans = -1;
				break;
			}
			x = *upper_bound(v[t[i] - 'a'].begin(), v[t[i] - 'a'].end(), x);
			if(x >= n){
				x -= n;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}