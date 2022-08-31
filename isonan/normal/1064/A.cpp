#include <cstdio>

int a,b,c,mx;
int tot;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	mx=a;
	if(mx<b)mx=b;
	if(mx<c)mx=c;
	if(a+b+c>mx*2)printf("0");
	else printf("%d\n",1+2*mx-a-b-c);
}