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

ll n, m, h[MAXN], p[MAXN];

ll isval(ll x){
	ll p1 = 0, p2 = 0, f;
	while(p1 < n && p2 < m){
		if(h[p1] > p[p2]){
			f = x - 2 * (h[p1] - p[p2]) + h[p1];
			f = max(f, h[p1] + (x - h[p1] + p[p2]) / 2);
			if(x < h[p1] - p[p2]){
				return 0;
			}
		}
		else{
			f = x + h[p1];
		}
		while(p2 < m && p[p2] <= f){
			p2++;
		}
		p1++;
	}
	if(p2 != m){
		return 0;
	}
	return 1;
}

ll binary_search(){
	ll l = -1, r = 1e15, mi;
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
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> h[i];
	}
	
	for(ll i = 0; i < m; i++){
		cin >> p[i];
	}
	
	cout << binary_search();
	
	return 0;
}