// In The Name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, w, a[MAXN], b[MAXN];

ll cal(ll x){
	ll c = 0, ans = 0;
	for(ll i = 0; i < n; i++){
		if(i >= w){
			c -= b[i - w];
		}
		b[i] = max(0ll, x - (a[i] + c));
		c += b[i];
		ans += b[i];
	}
	return ans;
}

ll isval(ll x){
	//cout << x << " => " << cal(x) << endl;
	return cal(x) > m;
}

ll binary_search(){
	ll l = 0, r = 1e10, mi;
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

int main(){
	fast_io;
	
	cin >> n >> m >> w;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cout << binary_search();
	
	
	return 0;
}