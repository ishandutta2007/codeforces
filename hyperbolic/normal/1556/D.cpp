#include <stdio.h>
#include <algorithm>

int getQuery(int k, int s, int t)
{
	if(k==1) printf("and %d %d\n",s,t);
	else printf("or %d %d\n",s,t);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int value[10010],ans[10010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=2;i<=a;i++)
	{
		int s = getQuery(1,1,i);
		int t = getQuery(2,1,i);
		value[i] = s+t;
	}
	int s = getQuery(1,2,3);
	int t = getQuery(2,2,3);
	int v = s+t;
	ans[1] = (value[2]+value[3]-v)/2;
	for(int i=2;i<=a;i++) ans[i] = value[i] - ans[1];
	
	std::sort(ans+1,ans+a+1);
	printf("finish %d",ans[b]);
}