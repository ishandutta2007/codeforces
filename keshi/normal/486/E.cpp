#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], dp[maxn], b[maxn], c[maxn], t, m;

string s;

int main(){
	fast_io;
	
	cin >> n;
	
	fill(dp, dp + maxn, inf);
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		b[i] = lower_bound(dp, dp + maxn, a[i]) - dp;
		dp[b[i]] = a[i];
	}
	
	fill(dp, dp + maxn, inf);
	
	for(ll i = n - 1; i > -1; i--){
		c[i] = lower_bound(dp, dp + maxn, -a[i]) - dp;
		t = max(t, b[i] + c[i]);
		dp[c[i]] = -a[i];
	}
	
	for(ll i = 0; i < n; i++){
		if(b[i] + c[i] == t){
			s += '3';
		}
		else{
			s += '1';
		}
	}
	
	m = -1;
	
	for(ll i = 0; i < n; i++){
		if(s[i] != '1'){
			if(b[i] > m){
				m = b[i];
			}
			else{
				s[i] = '2';
			}
		}
	}
	
	m = -1;
	
	for(ll i = n - 1; i > -1; i--){
		if(s[i] != '1'){
			if(c[i] > m){
				m = c[i];
			}
			else{
				s[i] = '2';
			}
		}
	}
	
	cout << s;
	
	return 0;
}