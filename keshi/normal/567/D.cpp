#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m, k, t, s, a[MAXN];
bool b[MAXN];

ll cal(ll x){
	// maximum number of ship
	ll ans = 0, l = -1;
	fill(b, b + n, 0);
	
	for(ll i = 0; i < x; i++){
		b[a[i]] = 1;
	}
	
	b[n] = 1;
	
	for(ll i = 0; i <= n; i++){
		if(b[i]){
			ans += (i - l) / (t + 1);
			l = i;
		}
	}
	
	return ans;
}

ll isval(ll x){
	//cout << x << " => " << cal(x) << endl;
	return cal(x) < k;
}

ll binary_search(){
	ll l = 0, r = m + 1, mi;
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
	
	cin >> n >> k >> t >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> a[i];
		a[i]--;
	}
	
	s = binary_search();
	if(s > m){
		s = -1;
	}
	cout << s;
	
	return 0;
}