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

ll q, a, b, k, dp[MAXN], ps[MAXN];


int main(){
	fast_io;
	
	cin >> q >> k;
	
	dp[0] = 1;
	ps[0] = 1;
	for(int i = 1; i < MAXN; i++){
		dp[i] = dp[i - 1];
		if(k <= i){
			dp[i] = (dp[i] + dp[i - k]) % MOD;
		}
		ps[i] = (ps[i - 1] + dp[i]) % MOD;
	}
	
	while(q--){
		cin >> a >> b;
		cout << (ps[b] - ps[a - 1] + MOD) % MOD << endl;
	}
	
	return 0;
}