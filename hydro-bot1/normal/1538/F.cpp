// Hydro submission #614b2fe1ad7fa16f5d915a13@1632323223219
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
int a,b;
int ans;

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	t=read();
	while(t--)
	{
		a=read();
		b=read();
		ans=0;
		while(b) ans+=b,b/=10;
		while(a) ans-=a,a/=10;
		printf("%lld\n",ans);
	}
	return 0;
}