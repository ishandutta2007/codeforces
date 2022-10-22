#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,a[maxn],t[maxn],cnt;
int f[maxn][25],llg[maxn];

inline int query(int x,int y)
{
	int l=llg[y-x+1];
	return max(f[x][l],f[y-(1<<l)+1][l]);
}

inline bool jud(int x)
{
	if(t[x]>=query(cnt,cnt+x-1)) return true;
	return false;
}

int main()
{
	int T=read(); llg[0]=-1;
	for(int i=1;i<=maxn-5;i++) llg[i]=llg[i>>1]+1;
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) for(int j=1;j<=17;j++) f[i][j]=0;
		for(int i=1;i<=n;i++) f[i][0]=a[i];
		for(int i=1;i<=17;i++)
		{
			for(int j=1;j+(1<<i)-1<=n;j++)
			{
				f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
			}
		}
		for(int i=1;i<=n;i++) t[i]=0;
		m=read();
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			t[y]=max(t[y],x);
		}
		for(int i=n-1;i>=1;i--) t[i]=max(t[i],t[i+1]);
		cnt=1; int ans=0,tmp=0;
		while(cnt<=n)
		{
			int l=1,r=n-cnt+1; tmp=0;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(jud(mid)) tmp=mid,l=mid+1;
				else r=mid-1;
			}
			if(tmp==0) break;
			ans++; cnt=cnt+tmp;
		}
		if(tmp==0) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}