#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N , K , arr[30003] , dp[30003][203][2] , val[203][2][2];
void chkmax(int &a , int b){a = max(a , b);}

int main(){
	scanf("%d %d" , &N , &K);
	for(int i = 1 ; i <= N ; ++i){scanf("%d" , &arr[i]); arr[i] += arr[i - 1];}
	memset(val , -0x3f , sizeof(val)); memset(dp , -0x3f , sizeof(dp)); int ans = 0;
	for(int i = 1 , mx = 0 , mn = 0 ; i <= N ; ++i){
		dp[i][1][0] = -arr[i] + mx; dp[i][1][1] = arr[i] - mn;
		for(int k = 1 ; k < K ; ++k){
			if(k == K - 1){chkmax(ans , val[k][0][0] + arr[i]); chkmax(ans , val[k][1][0] - arr[i]);}
			else{
				chkmax(dp[i][k + 1][1] , val[k][0][1] + 2 * arr[i]);
				chkmax(dp[i][k + 1][0] , val[k][1][1] - 2 * arr[i]);
				chkmax(dp[i][k + 1][1] , dp[i - 1][k][1]);
				chkmax(dp[i][k + 1][0] , dp[i - 1][k][0]);
			}
			chkmax(dp[i][k][0] , dp[i - 1][k][0]); chkmax(dp[i][k][1] , dp[i - 1][k][1]);
			chkmax(val[k][0][0] , dp[i][k][0] - arr[i]); chkmax(val[k][0][1] , dp[i][k][0] - 2 * arr[i]);
			chkmax(val[k][1][0] , dp[i][k][1] + arr[i]); chkmax(val[k][1][1] , dp[i][k][1] + 2 * arr[i]);
		}
		mx = max(mx , arr[i]); mn = min(mn , arr[i]);
	}
	printf("%d\n" , ans);
	return 0;
}