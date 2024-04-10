#include <cstdio>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
typedef long long LL;
const int N=100;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int a[N];
int f[N][N];
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n),read(m);
	char ch=' ';
	for(;ch<'a'||ch>'z';ch=getchar());
	fo(i,1,n)a[i]=ch,ch=getchar();
	sort(a+1,a+1+n);
	fo(i,0,n)fo(j,1,m)f[i][j]=1e9;
	f[0][0]=0;
	fo(i,1,n)
	{
		fo(j,1,m)
		{
			fo(k,0,i-1)if(a[i]-a[k]>1)
			{
				f[i][j]=min(f[i][j],f[k][j-1]+a[i]-'a'+1);
			}
		}
	}
	ans=1e9;
	fo(i,1,n)ans=min(ans,f[i][m]);
	if(ans<1e9)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}