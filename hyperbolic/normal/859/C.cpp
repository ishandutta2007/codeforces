#include <stdio.h>
int a;
int check[60][3];
int x[60],y[60];
int func(int s, int t)
{
	if(s>a) return 0;
	if(check[s][t]) return check[s][t];
	int s1 = func(s+1,t);
	int s2 = y[s]-func(s+1,1-t);
	return check[s][t] = s1>s2?s1:s2;
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=1;i--) y[i]=y[i+1]+x[i];
	printf("%d %d",y[1]-func(1,0),func(1,0));
}