// Hydro submission #6129e5d1a97b7217e4d86e61@1630135761430
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

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	t=read();
	while(t--)
	{
		k=read();
		for(i=1;k>i*2-1;++i)k-=(i*2-1);
		if(k==i) printf("%lld %lld\n",i,i);
		else if(k<i) printf("%lld %lld\n",k,i);
		else printf("%lld %lld\n",i,i-(k-i));
	}
	return 0;
}