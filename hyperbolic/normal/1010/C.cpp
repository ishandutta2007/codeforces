#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int s = b;
	for(int i=1;i<=a;i++) if((x[i]%b)!=0) s = gcd(s,x[i]%b);
	
	printf("%d\n",b/s);
	for(int i=0;i<b;i+=s) printf("%d ",i);
}