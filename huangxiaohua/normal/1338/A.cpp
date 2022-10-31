#include<stdio.h>
#include<math.h>
#define LL long long int
LL tmp,i,j,n,m,max,res,r;
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		max=-1145141919810;res=r=0;
		scanf("%lld",&m);
		for(j=1;j<=m;j++){
			scanf("%lld",&tmp);
			if(tmp>=max){max=tmp;}
			else{r=log2(max-tmp)+1;if(r>=res){res=r;}}
		}
		printf("%lld\n",res);
	}
}