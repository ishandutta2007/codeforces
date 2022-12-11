#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=300;

struct edge
{
	int u,v;
}e[MAXN];

int ec,n,a[MAXN],b[MAXN],c[MAXN],v[1<<3];
bool ok[MAXN];

bool solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=0;j<3;j++)
		{
			int x;
			scanf("%d",&x);
			a[i]|=x<<j;
		}
	for (int i=1;i<=n;i++)
		for (int j=0;j<3;j++)
		{
			int x;
			scanf("%d",&x);
			b[i]|=x<<j;
		}
	v[7]=1;
	ok[1]=true;
	for (;;)
	{
		bool flag=false;
		for (int i=1;i<=n;i++)
			if (!ok[i]&&v[a[i]])
			{
				e[ec++]={i,v[a[i]]};
				c[i]=1;
				flag=ok[i]=true;
				if (!v[a[i]&b[i]])
					v[a[i]&b[i]]=i;
			}
		if (flag)
			continue;
		for (int i=1;i<=n;i++)
			if (!ok[i]&&__builtin_popcount(a[i])==2)
			{
				int cnt=0;
				for (int j=0;j<3;j++)
					if ((a[i]>>j&1)&&v[1<<j])
						cnt++;
				if (cnt==2)
				{
					flag=ok[i]=true;
					for (int j=0;j<3;j++)
						if (a[i]>>j&1)
							e[ec++]={i,v[1<<j]};
					v[a[i]]=i;
					break;
				}
			}
		if (!flag)
			break;
	}
	for (int i=1;i<=n;i++)
		if (!ok[i])
			return false;
	return true;
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	if (!solve())
		puts("Impossible");
	else
	{
		puts("Possible");
		for (int i=1;i<=n;i++)
			printf("%d ",c[i]);
		puts("");
		printf("%d\n",ec);
		for (int i=0;i<ec;i++)
			printf("%d %d\n",e[i].v,e[i].u);
	}
	return 0;
}