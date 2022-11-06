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
    set<int> s, s1;
    vector<int> a(n);
    int am = 0;
    vector<int> pos1;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	am += a[i];
    	if(a[i] == 1) {
    		pos1.push_back(i);
    	}
    }
    const int inf = 1000000000;
    vector<vector<int>> dp(n + 1, vector<int>(am + 1, inf));
   	dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j <= am; j++) {
    		if(dp[i][j] == inf) {
    			continue;
    		}
    		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    		if(j != am && a[i] == 0) {
    			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(pos1[j] - i));
    		}
    	}
    }
    cout << dp[n][am];

}