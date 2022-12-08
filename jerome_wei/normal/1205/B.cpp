#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	ll t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n;
ll a[100010];
vector<int> v[64],g[100010];
bool vis[100010];
int ans=0x3f3f3f3f;
int id[100010];
vector<int> pt;
int dis[130][130],mp[130][130];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	pt.push_back(0);
	for(int i=0;i<64;i++)
	{
		for(int j=1;j<=n;j++)if((a[j]>>i)&1)v[i].push_back(j);
		if(v[i].size()>=3)
		{
			puts("3");
			return 0;
		}
		else if(v[i].size()==2)
		{
			if(!id[v[i][0]])id[v[i][0]]=pt.size(),pt.push_back(v[i][0]);
			if(!id[v[i][1]])id[v[i][1]]=pt.size(),pt.push_back(v[i][1]);
//			g[v[i][0]].push_back(v[i][1]);
//			g[v[i][1]].push_back(v[i][0]);
		}
	}
	int cnt=pt.size()-1;
	memset(dis,0x3f,sizeof(dis));
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=cnt;i++)mp[i][i]=dis[i][i]=0;
	for(int i=0;i<64;i++)
	{
		if(v[i].size()==2)
		{
			dis[id[v[i][0]]][id[v[i][1]]]=dis[id[v[i][1]]][id[v[i][0]]]=mp[id[v[i][0]]][id[v[i][1]]]=mp[id[v[i][1]]][id[v[i][0]]]=1;
		}
	}
	for(int k=1;k<=cnt;k++)
	{
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				ans=min(1ll*ans,1ll*dis[i][j]+mp[i][k]+mp[k][j]);
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans==0x3f3f3f3f)puts("-1");
	else printf("%d\n",ans);
	return 0;
}