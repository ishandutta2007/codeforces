// Hydro submission #6162d96d829d59d32228b6ab@1633868142417
// Problem: E. Staircases
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;
ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+
(x<<3)+(ch^48);ch=getchar();}return x*f;}
//#define mo
int n,m,i,j,k,q;
int ans,x,y;
int a[1010][1010];
int u1,u2,v1,v2;

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
	n=read();
	m=read();
	q=read();
	// for()
	// ans+=n*m-min(n,m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			ans+=(min(i-1,j-1)*4+1+(i!=j));
	// printf("%lld\n",ans);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j) a[i][j]=1;
	for(i=0;i<=n+1;++i) a[i][0]=a[i][m+1]=-1;
	for(i=0;i<=m+1;++i) a[0][i]=a[n+1][i]=-1;
	while(q--)
	{
		x=read();
		y=read();
		a[x][y]=-a[x][y];
		ans+=a[x][y];
		u1=v1=0;u2=v2=0;
		for(i=x,j=y;;)
		{
			--i;
			if(a[i][j]==-1) break;
			++u1;
			--j;
			if(a[i][j]==-1) break;
			++u1;
		}
		for(i=x,j=y;;)
		{
			--j;
			if(a[i][j]==-1) break;
			++u2;
			--i;
			if(a[i][j]==-1) break;
			++u2;
		}
		for(i=x,j=y;;)
		{
			++i;
			if(a[i][j]==-1) break;
			++v1;
			++j;
			if(a[i][j]==-1) break;
			++v1;
		}
		for(i=x,j=y;;)
		{
			++j;
			if(a[i][j]==-1) break;
			++v2;
			++i;
			if(a[i][j]==-1) break;
			++v2;
		}
		ans+=a[x][y]*(u1+v1+u2+v2+u1*v2+u2*v1);
		printf("%lld\n",ans);
	}
	return 0;
}