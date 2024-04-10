#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

struct Point
{
	int x,y;

	void read()
	{
		scanf("%d%d",&x,&y);
	}
};

void output(Point p,int x,int y)
{
	while (p.x<x)
		printf("%d %d\n",p.x++,p.y);
	while (p.x>x)
		printf("%d %d\n",p.x--,p.y);
	while (p.y<y)
		printf("%d %d\n",p.x,p.y++);
	while (p.y>y)
		printf("%d %d\n",p.x,p.y--);
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	Point a[3];
	for (int i=0;i<3;i++)
		a[i].read();
	int ans=INT_MAX;
	for (int i=0;i<=1000;i++)
		for (int j=0;j<=1000;j++)
		{
			int ret=0;
			for (int k=0;k<3;k++)
				ret+=abs(i-a[k].x)+abs(j-a[k].y);
			ans=min(ans,ret);
		}
	printf("%d\n",ans+1);
	for (int i=0;i<=1000;i++)
		for (int j=0;j<=1000;j++)
		{
			int ret=0;
			for (int k=0;k<3;k++)
				ret+=abs(i-a[k].x)+abs(j-a[k].y);
			if (ret==ans)
			{
				for (int k=0;k<3;k++)
					output(a[k],i,j);
				printf("%d %d",i,j);
				return 0;
			}
		}
	return 0;
}