#include <iostream>
#define ll long long
using namespace std;

#define MOD 1000000007
#define MAXN 4010
int n;
ll c[MAXN+2][MAXN+2];
ll dp[MAXN+2][MAXN+2];

void getc(){
	for(int i = 0;i <= MAXN;i++)
		c[i][0] = c[i][i] = 1;
	for(int i = 2;i <= MAXN;i++)
		for(int j = 1;j < i;j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
}
void getdp(){	//dp[n][m]nm
	for(int i = 1;i <= n;i++)
        dp[i][1] = dp[i][i] = (ll)1;
    for(int i = 2;i <= n;i++)
        for(int j = 2;j < i;j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * j) % MOD;
}
int main(){
	getc();
	
	scanf("%d",&n);
	getdp();
	
	ll ans = (ll)1;
    for(int i = 1;i < n;i++)
        for(int j = 1;j <= i;j++){
        	//cout << dp[i][j] << " " << c[n][i] << endl;
            ans += dp[i][j]*c[n][i] % MOD;
			if(ans >= MOD) ans -= MOD;
		}

    cout << ans << endl;
}