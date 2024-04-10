#include<stdio.h>
#include<math.h>
#define LL long long int
LL min(LL x,LL y){
	if(x>y){return y;}
	return x;
}
int main(){
	LL a,b,x,y,i,j,t;
	scanf("%lld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		if(b>=2*a){printf("%lld\n",abs(x)*a+abs(y)*a);continue;}
		if(x*y<=0){printf("%lld\n",abs(x)*a+abs(y)*a);continue;}
		x=abs(x);y=abs(y);printf("%lld\n",(x+y-2*min(x,y))*a+min(x,y)*b);
	}
	
}