#include <stdio.h>
#define M 1000000007
#define N 25000
int i,j,k,n,m,f[50050],f2[50050],res;
void su(int &a,int b){a+=b;if(a>=M){a-=M;}}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);su(res,f[N]);
		for(j=-10000;j<=10000;j++){f2[j+N]=f[j+N];}
		for(j=-10000;j<=10000;j++){su(f[j+N],f[j+N+k]);}
		for(j=10000;j>=-10000;j--){su(f[j+N],f[j+N-k]);}
		for(j=-10000;j<=10000;j++){su(f[j+N],M-f2[j+N]);su(f[j+N],M-f2[j+N]);}
		f[k+N]++;f[-k+N]++;
	}
	su(res,f[N]);
	printf("%lld",res%M);
}