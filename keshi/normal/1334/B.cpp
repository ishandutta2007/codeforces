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

ll t, n, x, s, ans, a[maxn];

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n >> x;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n, greater<ll>());
		ans = 0;
		s = 0;
		for(ll i = 0; i < n; i++){
			s += a[i];
			if((i + 1) * x <= s) ans = i + 1;
		}
		cout << ans << '\n';
	}
	
	return 0;
}