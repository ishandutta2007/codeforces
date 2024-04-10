// Hydro submission #6144a8ec4b273f753cd4ecf0@1631889645470
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
int n,m,i,j,k,t;
int a[310];

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);	
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		for(i=1;i<=m;++i) a[i]=read();
		for(i=1,k=0;i<m;++i)
			for(j=i+1;j<=m;++j)
				if(a[j]>a[i]) ++k;
		printf("%lld\n",k);
	}
	return 0;
}