#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

int n,m,a[200005],fa[200005],l[200005],r[200005],ans;
map<int,int> cnt;

int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}

void merge(int l,int r)
{
	int i;
	for (i=fnd(l);i+1<=r;)
	{
		i=fa[i]=fnd(i+1);
	}
}

int main()
{
	int i;
	
	scanf("%d%d",&n,&m);
	
	rep(i,n)fa[i]=i;
	
	rep(i,200000)
	{
		l[i]=n+1;r[i]=0;
	}
	rep(i,n)
	{
		scanf("%d",&a[i]);
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
	}
	
	rep(i,200000) if (l[i]<=r[i])
	{
		merge(l[i],r[i]);
	}
	
	ans=n;
	rep(i,n)
	{
		int j=fnd(i),k,s=0;
		cnt.clear();
		for (k=i;k<=j;k++)
		{
			s=max(s,++cnt[a[k]]);
		}
		ans-=s;
		i=j;
	}
	
	printf("%d\n",ans);
	
	return 0;
}