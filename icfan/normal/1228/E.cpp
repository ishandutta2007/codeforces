#include <cstdio>
#define Maxn 250
#define Mod 1000000007
int n,k;
int dp[Maxn+5][Maxn+5],c[Maxn+5][Maxn+5],bin[Maxn+5],bin2[Maxn+5];
void add(int &x,int y){
	x+=y;
	if(x>=Mod){
		x-=Mod;
	}
}
int mins(int x){
	if(x<0){
		x+=Mod;
	}
	return x;
}
void init(){
	for(int i=0;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
		}
	}
	bin[0]=1;
	for(int i=1;i<=n;i++){
		bin[i]=(1ll*bin[i-1]*k%Mod);
	}
	bin2[0]=1;
	for(int i=1;i<=n;i++){
		bin2[i]=(1ll*bin2[i-1]*(k-1)%Mod);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	init();
	dp[0][n]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			add(dp[i][j],1ll*dp[i-1][j]*bin2[j]%Mod*(mins(bin[n-j]-bin2[n-j]))%Mod);
			for(int p=1;p<=n-j;p++){
				add(dp[i][j],1ll*c[j+p][p]*dp[i-1][j+p]%Mod*bin[n-j-p]%Mod*bin2[j]%Mod);
			}
		}
	}
	printf("%d\n",dp[n][0]);
	return 0;
}