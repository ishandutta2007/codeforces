// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, a[MAXN], ans;

ll cal(ll l){
	ll s = 0;
	map<ll, ll> c;
	for(ll i = 0; i < n; i++){
		c[a[i]]++;
		if(c[a[i]] == 2){
			s++;
		}
	}
	for(ll i = l; i < n; i++){
		if(s == 0){
			return i - l;
		}
		if(c[a[i]] > 1){
			c[a[i]]--;
			if(c[a[i]] < 2){
				s--;
			}
		}
	}
	if(s == 0){
		return n - l;
	}
	return n;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	ans = n - 1;
	
	for(ll i = 0; i < n; i++){
		ans = min(ans, cal(i));
	}
	
	cout << ans;
	
	return 0;
}