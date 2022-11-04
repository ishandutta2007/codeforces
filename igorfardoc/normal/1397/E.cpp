#include<bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int r1, r2, r3, d;

ll usual(int n) {
	return (ll)n * r1 + r3;
}

ll unusual(int n) {
	return min((ll)r2 + r1, (ll)(n + 2) * r1);
}

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
    cin >> r1 >> r2 >> r3 >> d;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<ll> dp(n, INF);
    for(int i = n - 1; i >= 0; i--) {
    	if(i == n - 1) {
    		dp[i] = usual(a[i]);
    		dp[i] = min(dp[i], unusual(a[i]) + (ll)2 * d);
    		continue;
    	}
    	dp[i] = usual(a[i]) + dp[i + 1] + d;
    	dp[i] = min(dp[i], dp[i + 1] + unusual(a[i]) + (ll)3 * d);
    	if(i == n - 2) {
    		dp[i] = min(dp[i], unusual(a[i]) + usual(a[i + 1]) + d + d);
    		dp[i] = min(dp[i], unusual(a[i]) + unusual(a[i + 1]) + (ll)3 * d);
    		continue;
    	}
    	dp[i] = min(dp[i], unusual(a[i]) + unusual(a[i + 1]) + (ll)4 * d + dp[i + 2]);
    }
    cout << dp[0];
}