#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=100500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m;
LL ans;
LL f[N][5],g[N][5];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);	
		LL q;
		scanf("%lld",&q);
		fo(i,1,n)fo(j,1,4)f[i][j]=-1e18,g[i][j]=1e18;
		f[1][1]=g[1][1]=q;
		ans=-1e18;
		fo(i,2,n)
		{
			scanf("%lld",&q);
			f[i][1]=max(f[i-1][1],q);
			g[i][1]=min(g[i-1][1],q);
			fo(j,2,4)if(i>=j)
			{
				f[i][j]=max(f[i-1][j],max(q*f[i-1][j-1],q*g[i-1][j-1]));
				g[i][j]=min(g[i-1][j],min(q*f[i-1][j-1],q*g[i-1][j-1]));
			}
			if(i>4)
				ans=max(ans,max(f[i-1][4]*q,g[i-1][4]*q));
		}
		printf("%lld\n",ans);
	}
	return 0;
}