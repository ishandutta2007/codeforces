//In the name of GOD
//Good Bye 2019
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

ll t, n, a[maxn], mx, mn;

pll ans;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		mn = 0;
		mx = 0;
		ans = {-1, -1};
		for(ll i = 1; i < n; i++){
			if(a[mx] + mx > a[i] + i){
				ans = {mx, i};
			}
			else{
				mx = i;
			}
			if(a[mn] - mn < a[i] - i){
				ans = {mn, i};
			}
			else{
				mn = i;
			}
		}
		if(ans.F != -1){
			cout << "YES\n" << ans.F + 1 << " " << ans.S + 1 << '\n';
		}
		else cout << "NO\n";
	}
	
	return 0;
}