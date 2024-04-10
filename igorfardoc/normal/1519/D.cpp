#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int len = 1; len <= n; len++) {
    	for(int i = 0; i < n - len + 1; i++) {
    		int r = i + len - 1;
    		if(len == 1) {
    			dp[i][r] = (ll)a[i] * b[i]; 
    			continue;
    		}
    		if(len == 2) {
    			dp[i][r] = (ll)a[i] * b[i + 1] + (ll)a[i + 1] * b[i];
    			continue;
    		}
    		dp[i][r] = (ll)a[i] * b[r] + (ll)a[r] * b[i] + dp[i + 1][r - 1];
    	}
    }
    ll res = -1;
    ll fir = 0;
    for(int i = 0; i < n; i++) {
    	ll sec = 0;
    	for(int j = n - 1; j >= i; j--) {
    		res = max(res, fir + sec + dp[i][j]);
    		sec += (ll)a[j] * b[j];
    	}
    	fir += (ll)a[i] * b[i];
    }
    res = max(res, fir);
    cout << res;
}