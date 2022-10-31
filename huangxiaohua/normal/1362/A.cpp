#include<bits/stdc++.h>
using namespace std;
#define LL long long int
 
LL i,j,k,n,a,b,t,res;
  
int main(){
    scanf("%lld",&n);
    while(n--){
    	scanf("%lld%lld",&a,&b);res=0;j=0;
    	if(a%b!=0&&b%a!=0){puts("-1");continue;}
	if(a==b){puts("0");continue;}
	t=a/b;res=0;j=0;
	if(t%2==0&&t>0){
		while(t>=8&&t%8==0){res++;t/=8;}
		if(t!=1){j=1;}
		while(t%2==0){t/=2;}
		if(t!=1){goto aaa;}
		printf("%lld\n",res+j);continue;
	}
	t=b/a;res=0;j=0;
	if(t%2==0&&t>0){
		while(t>=8&&t%8==0){res++;t/=8;}
		if(t!=1){j=1;}
		while(t%2==0){t/=2;}
		if(t!=1){goto aaa;}
		printf("%lld\n",res+j);continue;
	}
	aaa:puts("-1");
	}
}