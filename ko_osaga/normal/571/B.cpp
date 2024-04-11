#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long lint;
using namespace std;

lint dp[5005][5005];
int a[350005], n, k;

lint f(int pos, int lft){
	if(pos > n) return 1e18;
	if(pos == n) return (lft == k ? 0 : 1e18);
	if(lft == k) return 1e18;
	if(~dp[pos - n / k * lft][lft]) return dp[pos - n / k * lft][lft];
	return dp[pos - n / k * lft][lft] = min(f(pos + n / k + 1, lft + 1) + a[pos + n / k] - a[pos],f(pos + n / k, lft + 1) + a[pos + n / k - 1] - a[pos]);
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	memset(dp,0x3f,sizeof(dp));
	for(int i=k; i>=0; i--){
		for(int lft=k; lft>=0; lft--){
			int pos = i + lft * (n / k);
			if(pos > n) dp[i][lft] = 1e18;
			else if(pos == n) dp[i][lft] = (lft == k ? 0 : 1e18);
			else if(lft == k) dp[i][lft] = 1e18;
			else{
				dp[i][lft] = min(dp[i+1][lft+1] + a[pos + n / k] - a[pos], dp[i][lft+1] + a[pos + n / k - 1] - a[pos]);
			}
		}
	}
	printf("%lld",dp[0][0]);
}