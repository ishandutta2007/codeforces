#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> v[205];
int a[maxn],n,ans;

inline int lb(int col,int x)
{
	int l=0,r=v[col].size()-1,tmp=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(v[col][mid]<x) l=mid+1,tmp=mid;
		else r=mid-1;
	}
	return tmp;
}

int main()
{
	int T=read();
	while(T--)
	{
		rep(i,1,200) v[i].clear();
		n=read(); ans=0; rep(i,1,n) a[i]=read(),v[a[i]].pb(i);
		rep(i,1,200) ans=max(ans,(int)v[i].size());
		for(int col=1;col<=200;col++)
		{
			for(int i=0,j=v[col].size()-1;i<v[col].size();i++,j--)
			{
				int l=v[col][i],r=v[col][j]; if(l>=r) break;
				for(int j=1;j<=200;j++)
				{
					if(v[j].size()==0||j==col) continue;
					int L=lb(j,l)+1,R=lb(j,r);
					ans=max(ans,max(0,R-L+1)+2*(i+1));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}