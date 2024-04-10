#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 305;
int l[N], c[N];
const int INF = 1e9;

map<int, int> dp, dp2;

int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++) sd(l[i]);
	for(int i = 1; i <= n; i++) sd(c[i]);	
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		dp2 = dp;

		for(auto it : dp2){
			int num = it.F, cst = it.S + c[i];
			int g = __gcd(num, l[i]);
			if(dp.find(g) == dp.end())
				dp[g] = cst;
			else dp[g] = min(dp[g], cst);
		}	
	}
	int ans = dp[1];
	if(ans == 0) ans = -1;
	printf("%d\n", ans);
}