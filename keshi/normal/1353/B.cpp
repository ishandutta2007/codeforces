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

ll t, n, k, a[maxn], b[maxn], ps[maxn], sp[maxn], ans;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(ll i = 1; i <= n; i++){
			cin >> b[i];
		}
		sort(a + 1, a + n + 1, greater<ll>());
		sort(b + 1, b + n + 1, greater<ll>());
		for(ll i = 1; i <= n; i++){
			ps[i] = ps[i - 1] + a[i];
			sp[i] = sp[i - 1] + b[i];
		}
		ans = 0;
		for(ll i = 0; i <= k; i++){
			ans = max(ans, sp[i] + ps[n - i]);
		}
		cout << ans << '\n';
	}
	
	return 0;
}