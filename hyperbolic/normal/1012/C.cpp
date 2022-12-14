#include <stdio.h>
#include <queue>
int x[5010],ans[5010],a;
int check[5010][2510][3],next[5010];
int func(int s, int t, int p)
{
	if(t==0) return 0;
	if(s>a) return 1234567890;
	if(check[s][t][p]!=-1) return check[s][t][p];
	int s1,s2;
	s1 = func(s+1,t,0);
	if(p==0)
	{
		int count = 0;
		if(x[s-1]>=x[s]) count += x[s-1]-x[s]+1;
		if(x[s]<=x[s+1]) s2 = func(s+2,t-1,1)+(x[s+1]-x[s]+1+count);
		else s2 = func(s+2,t-1,0)+count;
	}
	else
	{
		int count = 0;
		if(x[s-2]-1>=x[s]) count += x[s-2]-x[s];
		if(x[s]<=x[s+1]) s2 = func(s+2,t-1,1)+(x[s+1]-x[s]+1+count);
		else s2 = func(s+2,t-1,0)+count;
	}
	return check[s][t][p] = s1<s2?s1:s2;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) for(int j=0;j<=(a+1)/2;j++) check[i][j][0] = check[i][j][1] = -1;
	for(int i=1;i<=(a+1)/2;i++) printf("%d ",func(1,i,0));
}