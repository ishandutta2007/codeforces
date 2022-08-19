#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long lint;
using namespace std;
const int mod = 1e9 + 7;

vector<int> graph[100005];
lint dp[100005][2];
int c[100005];
int n;

lint f(int x, int k){
	if(~dp[x][k]) return dp[x][k];
	if(k == 0 && c[x] == 1) return 0;
	if(k == 1 && c[x] == 0){
		lint dp0 = 1, dp1 = 0;
		for(auto &i : graph[x]){
			lint ndp0 = 0, ndp1 = 0;
			ndp0 = dp0 * (f(i, 0) + f(i, 1));
			ndp1 = dp0 * f(i, 1) + dp1 * (f(i,0) + f(i,1));
			dp0 = ndp0 % mod;
			dp1 = ndp1 % mod;
		}
		return dp[x][k] = dp1;
	}
	else{
		lint ret = 1;
		for(auto &i : graph[x]){
			ret *= f(i, 0) + f(i, 1);
			ret %= mod; 
		}
		return dp[x][k] = ret;
	}
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int p;
		scanf("%d",&p);
		graph[p].push_back(i);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&c[i]);
	}
	printf("%lld",f(0,1));
}