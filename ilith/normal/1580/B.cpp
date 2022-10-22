#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define rgi register int
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
const int N=110;
int f[N][N][N],fac[N],C[N][N];
inline int get(int i,int j,int k){
	if(!j&&(k>i||k<1))return fac[i];
	return f[i][j][k];
}
signed main(){
	int n,m,K,P;
	scanf("%d%d%d%d",&n,&m,&K,&P),f[1][1][1]=C[0][0]=fac[0]=1;
	FOR(i,1,n){
		C[i][0]=1,fac[i]=1ll*fac[i-1]*i%P;
		FOR(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	}
	FOR(i,2,n)FOR(j,0,min(i,K))FOR(k,1,min(i-j+1,m)){
		rgi G=j-(k==1),X,Y;
		f[i][j][k]=(get(i-1,G,k-1)*2)%P;
		FOR(p,2,i-1)FOR(c,0,min(p,G))if((X=get(p-1,c,k-1))&&(Y=get(i-p,G-c,k-1))){
			f[i][j][k]=(f[i][j][k]+1ll*X*Y%P*C[i-1][p-1])%P;
		}
	}
	printf("%d",f[n][K][m]);
	return 0;
}
//