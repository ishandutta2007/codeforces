#include <cstdio>
#include <algorithm>
using namespace std;

int n;
bool vis[1000005];
int dp[1000005];

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		vis[t] = 1;
	}
	n = 1e6;
	for(int i=1; i<=n; i++){
		if(!vis[i]) continue;
		dp[i] = max(dp[i], 1);
		for(int j=i*2; j<=n; j+=i){
			if(vis[j]) dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	printf("%d",*max_element(dp,dp+n+1));
}