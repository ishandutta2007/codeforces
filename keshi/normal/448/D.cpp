#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m, k;

ll cal(ll x){
	ll ans = 0;
	for(ll i = 1; i <= min(x, n); i++){
		ans += min(m, x / i);
	}
	return ans;
}

ll isval(ll x){
	//cout << x << " => " << cal(x) << endl;
	return cal(x) >= k;
}

ll binary_search(){
	ll l = 0, r = n * m + 1, mi;
	while(r - l > 1){
		//cout << l << " " << r << endl;
		mi = (l + r) / 2;
		if(isval(mi)){
			r = mi;
		}
		else{
			l = mi;
		}
	}
	return r;
}

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	
	cout << binary_search();
	
	return 0;
}