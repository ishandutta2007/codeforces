//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x, m, a[maxn], ans;

ll cal(ll s, ll k){
	ll d, dis = 0;
	for(ll i = 0; i < k; i++){
		dis += a[s + i] - a[s];
	}
	d = dis;
	for(ll i = 1; i < k; i++){
		dis += (a[s + i] - a[s + i - 1]) * (2 * i - k);
		d = min(d, dis);
	}
	return d;
}

ll cost(ll k){
	ll dis = 0;
	for(ll i = 0; i < m; i += k){
		dis += cal(i, k);
	}
	return dis;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		if(x) a[m++] = i;
	}
	
	if(m == 1){
		cout << -1;
		return 0;
	}
	
	ans = inf;
	
	for(ll i = 2; i <= m; i++){
		if(m % i == 0){
			ans = min(ans, cost(i));
		}
	}
	
	cout << ans;
	
	return 0;
}