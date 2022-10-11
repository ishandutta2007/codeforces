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

ll t, n, k, l1, r1, l2, r2, x, y, ans;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		cin >> l1 >> r1;
		cin >> l2 >> r2;
		r1--;
		r2--;
		if(l1 > l2 || (l1 == l2 && r1 > r2)){
			swap(l1, l2);
			swap(r1, r2);
		}
		x = 0, y = 0;
		if(r2 <= r1){
			k -= (r2 - l2 + 1) * n;
			x = 0;
			y = r1 - l1 - (r2 - l2);
		}
		else if(l2 > r1){
			x = l2 - r1 - 1;
			y = r2 - l1 + 1;
		}
		else{
			k -= (r1 - l2 + 1) * n;
			x = 0;
			y = l2 - l1 + r2 - r1;
		}
		if(k <= 0){
			cout << "0\n";
			continue;
		}
		ans = inf;
		for(ll i = 1; i <= n; i++){
			if(k <= y * i){
				ans = min(ans, x * i + k);
			}
			else{
				ans = min(ans, x * i + y * i + (k - y * i) * 2);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}