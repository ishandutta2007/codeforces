#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

bool is[maxn];
int pri[maxn],cnt,id[maxn],pos[maxn];

inline void pre()
{
	for(int i=2;i<=maxn-5;i++)
	{
		if(!is[i]) pri[++cnt]=i,pos[i]=cnt;
		for(int j=1;j<=cnt;j++)
		{
			int k=pri[j]*i; if(k>maxn-5) break; is[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}

int n,q,a[maxn],l[maxn],g[22][maxn];
vector <int> v[maxn];

int main()
{
	pre(); n=read(); q=read(); rep(i,1,n) a[i]=read();
	rep(i,1,n)
	{
		for(int j=1;pri[j]*pri[j]<=a[i]&&j<=cnt;j++)
		{
			if(a[i]%pri[j]==0)
			{
				v[j].pb(i);
				while(a[i]%pri[j]==0) a[i]/=pri[j];
			}
		}
		if(a[i]!=1) v[pos[a[i]]].pb(i);
	}
	
	
	rep(i,1,cnt) if(v[i].size()) rep(j,1,v[i].size()-1) l[v[i][j]]=max(l[v[i][j]],v[i][j-1]);
	rep(i,1,n) l[i]=max(l[i],l[i-1]);
	
	rep(i,1,n) g[0][i]=l[i];
	rep(i,1,20) rep(j,1,n) g[i][j]=g[i-1][g[i-1][j]];
	
	while(q--)
	{
		int l=read(),r=read(),ans=0,nw=r;
		per(i,20,0) if(g[i][nw]>=l) nw=g[i][nw],ans+=(1<<i);
		printf("%d\n",ans+1);
	}
	return 0;
}