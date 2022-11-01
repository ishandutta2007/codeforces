#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,a[200005],b[200005],X[200005],Y[200005],Z[200005];
int fa[400005];
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}

#define merge(x,y) fa[find(x)]=find(y);

void solve()
{
	int i;
	scanf("%d%d",&n,&m);
	rep(i,n) fa[i]=i,fa[i+n]=i+n;
	
	rep(i,n-1)
	{
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		if(Z[i]!=-1)
		{
			if(__builtin_popcount(Z[i])&1)
			{
				merge(X[i],Y[i]+n);
				merge(X[i]+n,Y[i]);
			}
			else
			{
				merge(X[i],Y[i]);
				merge(X[i]+n,Y[i]+n);
			}
		}
	}
	
	rep(i,m)
	{
		int a,b,p;
		scanf("%d%d%d",&a,&b,&p);
		if(p)
		{
			merge(a,b+n);
			merge(a+n,b);
		}
		else
		{
			merge(a,b);
			merge(a+n,b+n);
		}
	}
	
	rep(i,n)
	{
		if(find(i)==find(i+n))
		{
			puts("NO");
			return;
		}
	}
	
	puts("YES");
	rep(i,n-1)
	{
		if(Z[i]!=-1) printf("%d %d %d\n",X[i],Y[i],Z[i]);
		else
		{
			if(find(X[i])==find(Y[i]+n))
			{
				printf("%d %d %d\n",X[i],Y[i],1);
				merge(X[i],Y[i]+n);
				merge(X[i]+n,Y[i]);
			}
			else
			{
				printf("%d %d %d\n",X[i],Y[i],0);
				merge(X[i],Y[i]);
				merge(X[i]+n,Y[i]+n);
			}
		}
	}
	
	
	rep(i,n)
	{
		if(find(i)==find(i+n))
		{
			assert(false);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}