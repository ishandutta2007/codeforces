#include <stdio.h>
#define MAX 16384
int x[20][20],a;
void func(int s, int t, int k)
{
	if(s>a) return;
	if(x[s][t]+k<=MAX)
	{
		x[s][t]+=k;
		return;
	}
	else
	{
		func(s+1,t,(k+x[s][t]-MAX)/2);
		func(s+1,t+1,(k+x[s][t]-MAX)/2);
		x[s][t] = MAX;
	}
}
int main()
{
	int b,count=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) func(1,1,MAX);
	for(int i=1;i<=a;i++) for(int j=1;j<=i;j++) if(x[i][j]==MAX) count++;
	printf("%d",count);
}