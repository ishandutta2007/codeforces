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
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], b[maxn], c[maxn], s, ans;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i] >> b[i];
		}
		s = 0;
		ans = inf;
		for(ll i = 0; i < n; i++){
			c[i] = max(0ll, a[i] - b[(i - 1 + n) % n]);
			s += c[i];
		}
		for(ll i = 0; i < n; i++){
			ans = min(ans, s - c[i] + a[i]);
		}
		cout << ans << '\n';
	}
	
	return 0;
}