#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15e4 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, d, a[MAXN], b[MAXN], t[MAXN], l[MAXN], r[MAXN], dp[MAXN];

deque<ll> deq;


int main(){
	fast_io;
	
	cin >> n >> m >> d;
	
	for(ll i = 1; i <= m; i++){
		cin >> a[i] >> b[i] >> t[i];
	}
	
	for(ll i = 1; i <= m; i++){
		deq.clear();
		for(ll j = n; j > 0; j--){
			while(!deq.empty() && dp[deq.back()] <= dp[j]){
				deq.pop_back();
			}
			if(!deq.empty() && deq.front() - j > d * (t[i] - t[i - 1])){
				deq.pop_front();
			}
			deq.pb(j);
			r[j] = dp[deq.front()];
		}
		deq.clear();
		for(ll j = 1; j <= n; j++){
			while(!deq.empty() && dp[deq.back()] <= dp[j]){
				deq.pop_back();
			}
			if(!deq.empty() && j - deq.front() > d * (t[i] - t[i - 1])){
				deq.pop_front();
			}
			deq.pb(j);
			l[j] = dp[deq.front()];
		}
		for(ll j = 1; j <= n; j++){
			dp[j] = max(r[j], l[j]) + b[i] - abs(a[i] - j);
		}
	}
	
	cout << *max_element(dp + 1, dp + n + 1);
	
	return 0;
}