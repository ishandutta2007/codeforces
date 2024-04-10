// In The Name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 100;
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

ll n, m, a, b[MAXN], c[30], bit[30];

ll isval(ll x){
	ll y = 29;
	for(ll i = 0; i < 30; i++){
		c[i] = bit[i];
	}
	
	for(ll i = x - 1; i > -1; i--){
		while(y > b[i]){
			c[y - 1] += 2 * c[y];
			y--;
		}
		if(c[b[i]] < 1){
			return 1;
		}
		c[b[i]]--;
	}
	return 0;
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
	return l;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		for(ll j = 0; j < 30; j++){
			if(a % 2){
				bit[j]++;
			}
			a /= 2;
		}
	}
	
	for(ll i = 0; i < m; i++){
		cin >> b[i];
	}
	
	sort(b, b + m);
	
	cout << binary_search();
	
	return 0;
}