#include<stdio.h>
#define LL long long int
static LL m,n,a,b,i,j,ab,x,y,xnum,ynum;
LL beishu(LL x,LL y){
	LL i;
	while(x!=1&y!=1){
		if((x%y==0)&(y!=1)){return y;}
		else{x=x%y;}
		if((y%x==0)&(x!=1)){return x;}
		else{y=y%x;}
	}
	return 1;
}

int main(){
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		if (b<a){x=a;a=b;b=x;}
		ab=a*b/beishu(a,b);
		for(j=1;j<=n;j++){
			scanf("%lld%lld",&x,&y);
			x--;
			xnum=0;ynum=0;
			if(x%ab==0){xnum=x-x/ab*b;}
			else{
				if(x%ab<b){
					xnum=x-x/ab*b-x%ab;
				}
				else{xnum=x-x/ab*b-b+1;}
			}
			if(y%ab==0){ynum=y-y/ab*b;}
			else{
				if(y%ab<b){
					ynum=y-y/ab*b-y%ab;
				}
				else{ynum=y-y/ab*b-b+1;}
			}
			printf("%lld ",ynum-xnum);
		}
		printf("\n");
	}
	return 0;
}