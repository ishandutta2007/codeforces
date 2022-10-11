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

ll n, a[MAXN], l, r, x, s, sum, c, m, k, ans, y;

int main(){
	fast_io;
	
	cin >> n >> l >> r >> x;
	
	s = 1;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		s *= 2;
	}
	
	for(ll i = 1; i < s; i++){
		sum = 0;
		c = 0;
		m = 0;
		k = INF;
		y = i;
		for(ll j = 0; j < n; j++){
			if(y % 2){
				c++;
				sum += a[j];
				m = max(m, a[j]);
				k = min(k, a[j]);
			}
			y /= 2;
		}
		if(c >= 2){
			if(sum >= l && sum <= r && m - k >= x){
				ans++;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}