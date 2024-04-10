#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, s[MAXN], ans, r;
bool u[MAXN];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
	}
	
	sort(s, s + n);
	
	ans = 0;
	r = n - 1;
	
	for(ll i = (n - 1) / 2; i > -1; i--){
		if(s[i] * 2 <= s[r]){
			u[r] = 1;
			u[i] = 1;
			ans++;
			r--;
		}
		while(u[r]){
			r--;
		}
	}
	
	cout << n - ans;
	
	return 0;
}