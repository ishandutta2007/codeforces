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

ll t, n, a[maxn], mx, mn, x, ans;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		mx = 0;
		mn = 1e9;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		for(ll i = 0; i + 1 < n; i++){
			if(a[i] + a[i + 1] == -2) continue;
			if(a[i] == -1){
				mx = max(mx, a[i + 1]);
				mn = min(mn, a[i + 1]);
			}
			if(a[i + 1] == -1){
				mx = max(mx, a[i]);
				mn = min(mn, a[i]);
			}
		}
		x = (mn + mx) / 2;
		for(ll i = 0; i < n; i++){
			if(a[i] == -1) a[i] = x;
		}
		ans = 0;
		for(ll i = 0; i + 1 < n; i++){
			ans = max(ans, abs(a[i] - a[i + 1]));
		}
		cout << ans << " " << x << '\n';
	}
	
	return 0;
}