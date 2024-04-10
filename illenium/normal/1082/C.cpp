#pragma GCC optimize(2)
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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <ll> p[maxn],q[maxn];
vector <ll> sum[maxn];

inline bool cmp(ll a,ll b){return a>b;}

int main()
{
	ll n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		ll s=read(),r=read();
		p[s].push_back(r);
	}
	for(int i=1;i<=k;i++) sort(p[i].begin(),p[i].end(),cmp);
	for(int i=1;i<=k;i++)
	{
		ll tmp=0;
		sum[i].push_back(0);
		for(int j=0;j<p[i].size();j++)
		{
			tmp+=p[i][j];
			sum[i].push_back(tmp);
		}
	}
	ll ms=0,ans=0;
	for(int i=1;i<=k;i++)
	{
		ll tmp=p[i].size();
		ms=max(ms,tmp);
	}
	for(int i=1;i<=k;i++) for(int j=1;j<=p[i].size();j++) q[j].push_back(i);
	for(int i=1;i<=ms;i++)
	{
		ll tmp=0;
		for(int j=0;j<q[i].size();j++)
		{
			if(p[q[i][j]].size()<i||sum[q[i][j]][i]<0) continue;
			else tmp+=sum[q[i][j]][i];
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}