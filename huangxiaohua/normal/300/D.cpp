#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 7340033

int i,j,k,n,m,t;
ll f[32][1050],f2[32][1050];
int main(){
	f[0][0]=f2[0][0]=1;
	for(i=1;i<=30;i++){
		f[i][0]=1;
		for(j=0;j<=1000;j++){
			for(k=0;k<=j;k++){
				f[i][j+1]+=f2[i-1][j-k]*f2[i-1][k]%M;
			}f[i][j+1]%=M;
		}
		for(j=0;j<=1000;j++){
			for(k=0;k<=j;k++){
				f2[i][j]+=f[i][j-k]*f[i][k]%M;
			}f2[i][j]%=M;
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&k,&m);n=0;
		while(k&1&&k>1){k>>=1;n++;}
		printf("%lld\n",f[n][m]);
	}
}