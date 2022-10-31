#include<stdio.h>
#include<math.h>
#define LL long long int
LL i,n,a,b,sb[50005],st,j,res;
int main(){
	for(i=1;i<=50000;i++){
		sb[i]=i*(1.5*i+0.5);
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a);
		st=sqrt(a)+10;res=0;
		for(j=st;j>=1;j--){
			while(a>=sb[j]){
				a-=sb[j];res++;
			}
		}
		printf("%lld",res);
        if(i!=n){printf("\n");}
	}
}