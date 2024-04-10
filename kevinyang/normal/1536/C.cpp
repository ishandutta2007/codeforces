#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int>psa(n+1);// for d
		vector<int>psa2(n+1);// for k
		vector<vector<int>>factors(n+1);
		for(int i = 1; i<=n; i++){
			for(int j = i; j<=n; j+=i){
				factors[j].push_back(i);
			}
		}
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1];
			if(s[i-1]=='D')psa[i]++;
			psa2[i] = psa2[i-1];
			if(s[i-1]=='K')psa2[i]++;
		}
		map<pair<int,int>,int>hm;
		vector<int>dp(n+1,1); dp[0] = 0;
		for(int i = 1; i<=n; i++){
			int ans = 1;
			int x = psa[i]; int y = psa2[i];
			int g = gcd(x,y);
			assert(g);
			x/=g;
			y/=g;
			if(y==0)x = 1;
			if(x==0)y = 1;
			dp[i] = dp[hm[{x,y}]]+1;
			hm[{x,y}] = i;
		}
		for(int i = 1; i<=n; i++){
			cout << dp[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}