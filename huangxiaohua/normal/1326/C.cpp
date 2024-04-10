#include<bits/stdc++.h>
using namespace std;
#define p 998244353
long long n,m,l,r,res=1,k,i;

int main(){
	scanf("%lld%lld",&m,&n);
	printf("%lld ",(m+m+1-n)*n/2);
	for(i=1;i<=m;i++){
		scanf("%d",&k);
		if(k>=m-n+1){
			if(l==0){l=i;continue;}
			else{r=i;res*=(r-l);res%=p;l=r;continue; }
		}
	}
	printf("%lld",res);
}