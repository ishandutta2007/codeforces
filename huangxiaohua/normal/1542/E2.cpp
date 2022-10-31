#include <stdio.h>
int i,j,k,n,t,nxd,m=150000;
long long res[505],f[300500],g[300500],M;

int main(){
	scanf("%d%lld",&n,&M);f[m]=1;
	for(i=1;i<n;i++){
		nxd+=i;
		for(j=-nxd+m-i-1;j<=nxd+m+i+1;j++){g[j]=(g[j-1]+f[j])%M;}
		for(j=-nxd+m-1;j<nxd+m;j++){
			f[j+1]=(f[j]+g[j+i+1]+(M-g[j])*2+g[j-i-1])%M;
			if(j>m&&j<=i+m){res[i+1]=(res[i+1]+(g[nxd+m]-g[j]+M)%M*(i+1+m-j))%M;}
		}
	}
	for(i=1;i<=n-1;i++){res[i+1]=(res[i+1]+res[i]*(i+1))%M;}
	printf("%lld",res[n]);
}