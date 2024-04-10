#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N , K , arr[30003] , dp[30003][203][2];
void chkmax(int &a , int b){a = max(a , b);}

int main(){
	scanf("%d %d" , &N , &K);
	for(int i = 1 ; i <= N ; ++i){scanf("%d" , &arr[i]); arr[i] += arr[i - 1];}
	memset(dp , -0x3f , sizeof(dp)); int ans = 0;
	for(int i = 1 ; i <= N ; ++i){
		int mx = -1e9 , mn = 1e9;
		for(int j = i - 1 ; ~j ; --j){
			mx = max(mx , arr[i] - arr[j]); mn = min(mn , arr[i] - arr[j]);
			for(int k = 1 ; k < K ; ++k)
				if(k == K - 1){chkmax(ans , dp[j][k][0] + mx); chkmax(ans , dp[j][k][1] - mn);}
				else{
					chkmax(dp[i][k + 1][1] , dp[j][k][0] + 2 * mx);
					chkmax(dp[i][k + 1][0] , dp[j][k][1] - 2 * mn);
					chkmax(dp[i][k + 1][1] , dp[j][k][1]);
					chkmax(dp[i][k + 1][0] , dp[j][k][0]);
				}
		}
		dp[i][1][0] = -mn; dp[i][1][1] = mx;
	}
	printf("%d\n" , ans);
	return 0;
}