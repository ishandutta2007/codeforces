#include<stdio.h>
long long int i,m,n,k,j,tmp;
int main(){
	scanf("%lld",&m);
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&n,&k);
		if(n%2==0){
			printf("%lld\n",n+k*2);continue;
		}
		else{
			for(j=3;j<=n;j+=2){
				if(n%j==0){
					tmp=j;break;
				}
			}
			printf("%lld\n",n+k*2-2+tmp);
		}
	}
}