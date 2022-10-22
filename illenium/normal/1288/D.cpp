#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
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

int a[maxn][10],ed,n,m,f1,f2;
int vis[maxn];

inline bool jud(int x)
{
	int sta[maxn];
	for(int i=1;i<=n;i++) sta[i]=0;
	for(int i=0;i<=ed;i++) vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) if(a[i][j]>=x) sta[i]|=(1<<(j-1));
		//cout<<sta[i]<<" "<<i<<endl;
		vis[sta[i]]=i;
		//cout<<sta[i]<<" "<<i<<" "<<vis[sta[i]]<<endl;
	}
	//for(int i=0;i<=ed;i++) cout<<sta[i]<<" "; cout<<endl;
	//for(int i=0;i<=ed;i++) cout<<vis[i]<<" "; cout<<endl;
	for(int i=0;i<=ed;i++)
	{
		for(int j=0;j<=ed;j++)
		{
			if((i|j)==ed&&vis[i]&&vis[j])
			{
				f1=vis[i]; f2=vis[j];
				return true;
			}
		}
	}
	return false;
}

int main()
{
	n=read(),m=read(); ed=(1<<m)-1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=read();
	int l=0,r=1e9,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<f1<<" "<<f2<<endl;
	return 0;
}