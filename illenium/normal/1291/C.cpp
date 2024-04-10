#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9+7
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,k,x,y,q;
int a[100005],f[100005][20],llg[100005];

int query(int x,int y)
{
	int l=llg[y-x+1];
	return min(f[x][l],f[y-(1<<l)+1][l]);
}

int main()
{
	int T=read();
	llg[0]=-1;
	for(int i=1;i<=n;i++) llg[i]=llg[i>>1]+1;
	while(T--)
	{
		n=read(); m=read(); k=read(); q=0; int len=m-k-1;
		for(int i=1;i<=n;i++) a[i]=read();
		if(m<=k+1)
		{
			int ans=0;
			for(int i=1;i<=m;i++) ans=max(ans,a[i]);
			for(int i=1;i<=m;i++) ans=max(ans,a[n-i+1]);
			cout<<ans<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++) f[i][0]=a[i];
			for(int i=1;i<=16;i++)
			{
				for(int j=1;j+(1<<i)-1<=n;j++)
				{
					f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
				}
			}
			for(int i=1;i<=q;i++)
			{
				scanf("%d%d",&x,&y);
				printf("%d\n",query(x,y));
			}
			
			int ans=0;
			for(int i=0;i<=k;i++)
			{
				int l=i+1,r=n-(k-i),tmp=inf; //cout<<l<<" "<<r<<endl;
				for(int j=0;j<=len;j++)
				{
					int p1=a[l+j]; int res=len-j;
					int p2=a[r-res];
					//cout<<l+j<<" "<<r-res<<" "<<p1<<" "<<p2<<endl;
					tmp=min(tmp,max(p1,p2));
				}
				ans=max(ans,tmp);
				
			}
			cout<<ans<<endl;
		}
		
	}
	
	return 0;
}