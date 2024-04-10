#include<stdio.h>
typedef long long LL;
const LL mod=1000000007;
const LL inv2=(mod+1)/2;
LL inv[52];
LL C[52][52];
LL dp[52][52][2];// i nodes j matches k 0/1 root matched?
inline void Add(LL &x,LL y){
	if(y>=mod) y%=mod;
	y*=inv2;
	if(y>=mod) y%=mod;
	x+=y;
	if(x>=mod) x-=mod;
}
int N,M;
int main(){
	inv[1]=1;
	for(int i=2;i<=50;++i) inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=0;i<=50;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=mod) C[i][j]-=mod;
		}
	}
	dp[0][0][1]=1;
	dp[1][0][0]=1;
	for(int i=2;i<=50;++i){
		for(int j=0;j<i;++j){
			int k=i-1-j;
			for(int l=0;l<=j/2;++l){
				for(int m=0;m<=k/2;++m){
					for(int ii=0;ii<2;++ii) for(int jj=0;jj<2;++jj){
						int cnt=!ii||!jj;
						Add(dp[i][l+m+cnt][cnt],dp[j][l][ii]*dp[k][m][jj]%mod*i%mod*C[i-1][j]);
					}
				}
			}
		}
	}
	scanf("%d%d",&N,&M);
	printf("%d\n",int((dp[N][M][0]+dp[N][M][1])*inv[N]%mod));
	scanf("%d",&N);
	return 0;
}