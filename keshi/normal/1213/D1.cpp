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

ll n, k, ans, a[MAXN], cost[MAXN], t[MAXN], c;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	for(ll i = 0; i < n; i++){
		c = 0;
		while(a[i]){
			if(t[a[i]] < k){
				t[a[i]]++;
				cost[a[i]] += c;
			}
			c++;
			a[i] /= 2;
		}
		if(t[a[i]] < k){
			t[a[i]]++;
			cost[a[i]] += c;
		}
	}
	
	ans = INF;
	
	for(ll i = 0; i < MAXN; i++){
		if(t[i] == k){
			ans = min(ans, cost[i]);
		}
	}
	
	cout << ans;
	
	return 0;
}