// Hydro submission #6144a90dfd260f753d6ac1c3@1631889678509
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct node
{
	int x,id;
}d[90010];
int n,m,i,j,k,ans,t;
int a[310][310];

bool cmp(node x,node y)
{
	if(x.x==y.x) return x.id<y.id;
	return x.x<y.x;
}

bool Cmp(node x,node y)
{
	return x.id<y.id;
}

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	t=read();
	while(t--)
	{
		ans=0;
		n=read();
		m=read();
		for(i=1;i<=n*m;++i)
			d[i].x=read(),d[i].id=i;
		sort(d+1,d+n*m+1,cmp);
		for(i=1;i<=n;++i)
			sort(d+(i-1)*m+1,d+(i-1)*m+m+1,Cmp);
		for(i=k=1;i<=n;++i)
			for(j=1;j<=m;++j,++k)
				a[i][j]=d[k].x;
		for(i=1;i<=n;++i)
			for(j=1;j<m;++j)
				for(k=j+1;k<=m;++k)
					if(a[i][k]>a[i][j]) ++ans;
		printf("%lld\n",ans);
	}
	return 0;
}