#include <stdio.h>
#define MIN -1234567890

int a;
int x[100010];
int check[100010][110];

int func(int s, int t)
{
	if(s>a) return -t;
	if(check[s][t+31]!=MIN) return check[s][t+31];
	
	t = t>x[s]?t:x[s];
	
	int s1, s2;
	s1 = func(s+1,t) + x[s];
	s2 = x[s] - t;
	return check[s][t+31] = s1>s2?s1:s2;
}

int main()
{
	scanf("%d",&a);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=70;j++) check[i][j] = MIN;
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = MIN;
	for(int i=1;i<=a;i++) ans = ans>func(i,x[i])?ans:func(i,x[i]);
	printf("%d",ans);
}