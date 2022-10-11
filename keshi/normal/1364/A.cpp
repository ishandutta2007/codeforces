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

ll t, n, a[maxn], ps[maxn], x, s, ans;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		s = n + 1;
		ans = -1;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			ps[i] = (ps[i - 1] + a[i]) % x;
			if(ps[i] != 0) s = min(s, i);
		}
		for(ll i = 1; i <= n; i++){
			if(ps[i] != 0) ans = max(ans, i);
			else ans = max(ans, i - s);
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}