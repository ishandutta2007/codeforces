#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005,MAXH=50;

int fa[MAXN];
double p[MAXN][MAXH];

int main()
{
	int q;
	scanf("%d",&q);
	int id=1;
	while (q--)
	{
		int op,v;
		scanf("%d%d",&op,&v);
		if (op==1)
		{
			fa[++id]=v;
			double t1=0,t2=1;
			for (int i=1,now=v;i<MAXH&&now;i++,now=fa[now])
			{
				double t=p[now][i];
				p[now][i]=1-(1-p[now][i])/(1-t1/2)*(1-t2/2);
				t1=t;
				t2=p[now][i];
			}
		}
		else
		{
			double ans=0;
			for (int i=1;i<MAXH;i++)
				ans+=p[v][i];
			printf("%.8f\n",ans);
		}
	}
	return 0;
}