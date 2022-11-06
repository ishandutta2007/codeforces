#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	bitset< 2005 >dp;
	dp[0] = 1;
	int n,m;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		x%=m;
		if(x==0)x=m;
		dp = (dp|(dp<<x));
		dp = (dp|(dp>>m));
	}
	if(dp[m])cout << "YES\n";
	else cout << "NO\n";
	return 0;
}