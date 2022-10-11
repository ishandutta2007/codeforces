//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, k, z, a[maxn], x, ans, s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k >> z;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		ans = x = 0;
		s = a[0];
		for(ll i = 1; i < n; i++){
			k--;
			if(k < 0) continue;
			x = max(x, a[i - 1] + a[i]);
			s += a[i];
			if((k + 1) / 2 <= z){
				ans = max(ans, s + (k & 1 ? a[i - 1] : 0) + (k / 2) * x);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}