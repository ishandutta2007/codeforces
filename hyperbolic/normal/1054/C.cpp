#include <stdio.h>
#include <queue>

struct str{
	int x0;
	int y0;
};
bool operator<(str a, str b)
{
	if(a.y0==b.y0) return a.x0<b.x0;
	return a.y0>b.y0;
}
std::priority_queue<str> Q;

int ans[100010];
int x[100010],y[100010];
int x2[100010],y2[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]>=i)
		{
			printf("NO");
			return 0;
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(y[i]>=(a-i+1))
		{
			printf("NO");
			return 0;
		}
	}
	for(int i=1;i<=a;i++) Q.push({i,x[i]+y[i]});
	
	int C = -1;
	int p = a+1;
	while(!Q.empty())
	{
		int x0 = Q.top().x0;
		int y0 = Q.top().y0;
		Q.pop();
		
		if(y0>C)
		{
			C = y0;
			p--;
		}
		ans[x0] = p;
	}
	for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) if(ans[i]<ans[j]) y2[i]++;
	for(int i=1;i<=a;i++) for(int j=i-1;j>=1;j--) if(ans[i]<ans[j]) x2[i]++;
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=x2[i])
		{
			printf("NO");
			return 0;
		}
		if(y[i]!=y2[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}