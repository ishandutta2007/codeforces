#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define M 998244353
#define LL long long int
using namespace std;
int i,j,n,k,x;
LL sb[500555]={1},sum;
LL pw(int x,int y){LL i=1,j=x,k=y;while(k){i*=max((k&1)*j%M,(LL)1);i%=M;k>>=1;j=(j*j)%M;}return i;}
int main(){
	scanf("%d%d",&n,&k);
	if(k>n){puts("0");return 0;}
	if(k==n){puts("1");return 0;}
	for(i=1;i<=n;i++){
		if((n/i-1)<k-1){break;}
		x=min(k-1,n/i-k);
		for(j=1;j<=x;j++){
			sb[j]=sb[j-1]*(n/i-j)%M;
			sb[j]=sb[j]*pw(j,M-2)%M;
		}
		sum+=sb[x]%M;sum%=M;
	}
	printf("%lld",sum);
	return 0;
}