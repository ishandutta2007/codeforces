/**************************/
/*It is made by decoration*/
/*gzzkal   gzzkal   gzzkal*/
/*It is made by decoration*/
/**************************/
#include <bits/stdc++.h>
using namespace std;
int tong[1000],x0[1000],qaq[1000];
int main()
{
	int x1=0x3f3f3f3f,x2=-1,y1=0x3f3f3f3f,y2=-1;
	int n;
	cin>>n;
	for(int i=1;i<=4*n+1;i++)
	{
		scanf("%d%d",&x0[i],&qaq[i]);
	}
	for(int i=1;i<=4*n+1;i++)
	{
		tong[x0[i]]++;
		if(tong[x0[i]]>=2)
		{
			x1=min(x1,x0[i]);
			x2=max(x2,x0[i]);
		}
	}
	memset(tong,0,sizeof(tong));
	for(int i=1;i<=4*n+1;i++)
	{
		tong[qaq[i]]++;
		if(tong[qaq[i]]>=2)
		{
			y1=min(y1,qaq[i]);
			y2=max(y2,qaq[i]);
		}
	}
	for(int i=1;i<=4*n+1;i++)
	{
		if(x0[i]==x1||x0[i]==x2)
		{
			if(qaq[i]<=y2&&qaq[i]>=y1)
			{
				continue;
			}
		}
		if(qaq[i]==y1||qaq[i]==y2)
		{
			if(x0[i]>=x1&&x0[i]<=x2)
			{
				continue;
			}
		}
		printf("%d %d",x0[i],qaq[i]);
		return 0;
	}
}