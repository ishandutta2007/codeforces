

#include <cstdio>
#include <algorithm>
using namespace std;

int sm, h;

int dp[2][200005];

int main(){
    int r, g;
    scanf("%d %d",&r,&g);
    sm = r + g;
    for(int i=900; i>=0; i--){
    	int p = sm - i * (i+1) / 2;
    	for(int j=0; j<=g; j++){
    		dp[i%2][j] = 0;
    		if(p > j + i) dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j] + 1);
    		if(j > i) dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j-i-1] + 1);
    	}
    }
    int h = dp[0][g];
    fill(dp[h%2], dp[h%2] + g + 1, 1);
    for(int i=h-1; i>=0; i--){
    	int p = sm - i * (i+1) / 2;
    	for(int j=0; j<=g; j++){
    		dp[i%2][j] = 0;
    		if(p > j + i) dp[i%2][j] += dp[(i+1)%2][j];
    		if(j > i) dp[i%2][j] += dp[(i+1)%2][j-i-1];
    		dp[i%2][j] %= 1000000007;
    	}
    }
    printf("%d",dp[0][g]);
}