#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<bitset>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 505
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,l,r,pos,ans[N],mark[N];
std::bitset<N*N/2>f[N];
void clear()
{
	pos=0;
	for(int i=0;i<=n;i++) f[i].reset();
	for(int i=1;i<=n;i++) mark[i]=0;
}
void work(int x,int y,int lim)
{
	if(!x) return;
	// dbg1(x),dbg2(y);
	for(int i=min(lim,y);i;i--)
		if(f[x-1][y-i]) return mark[i]=1,work(x-1,y-i,i-1);
	// mark[to[x][y]]=1,work(x-1,y-to[x][y]);
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d%d%d",&n,&l,&r,&m),f[0][0]=1;
		for(int i=1,Sum=0;i<=n;i++)
		{
			Sum+=i;
			for(int j=i;j;j--) f[j]|=f[j-1]<<i;
				// for(int k=min(Sum,m);k>=i;k--)
					// if(f[j-1][k-i]&&!f[j][k]) f[j][k]=1,to[j][k]=i;
		}
		if(!f[r-l+1][m]) {puts("-1");continue;}
		work(r-l+1,m,n);
		for(int i=1;i<=n&&pos<l-1;i++) if(!mark[i]) ans[++pos]=i;
		for(int i=1;i<=n&&pos<r;i++) if(mark[i]) ans[++pos]=i;
		for(int i=n;i&&pos<n;i--) if(!mark[i]) ans[++pos]=i;
		for(int i=1;i<=n;i++) printf("%d%c",ans[i],i<n?' ':'\n');
	}
	return 0;
}