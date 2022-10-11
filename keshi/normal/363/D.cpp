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

ll n, m, c, a[MAXN], b[MAXN];

ll cal(ll x){
	// minimum of c
	
	ll ans = 0;
	
	for(ll i = 0; i < x; i++){
		ans += max(0ll, b[i] - a[n - x + i]);
	}
	
	return ans;
}

ll isval(ll x){
	//cout << x << " => " << cal(x) << endl;
	return cal(x) > c;
}

ll binary_search(){
	ll l = 0, r = min(n, m) + 1, mi;
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
	return l;
}

void cal2(ll x){
	
	cout << x << " ";
	
	ll ans = 0;
	
	for(ll i = 0; i < x; i++){
		ans += b[i];
	}
	
	cout << max(0ll, ans - c);
	
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m >> c;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	
	for(ll i = 0; i < m; i++){
		cin >> b[i];
	}
	sort(b, b + m);
	
	cal2(binary_search());
	
	return 0;
}