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
#define inf 1e18
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n;
ll f[65][65],sum[65],inff;
struct node{ll a,b;}p[65];

inline bool cmp(node a,node b)
{
	if(a.a==b.a) return a.b>b.b;
	return a.a>b.a;
}

inline bool jud(ll mid)
{
	memset(f,127,sizeof(f)); inff=f[0][0];
	f[0][0]=0;
	for(int i=1,loc;i<=n;i=loc+1)
	{
		for(loc=i;p[loc+1].a==p[i].a;loc++);
		sum[i-1]=0;
		for(int j=i;j<=loc;j++) sum[j]=sum[j-1]+p[j].b;
		for(int j=0;j<=n;j++) if(f[i-1][j]!=inff)
		{
			for(int k=max(0,(loc-i+1)-(2*j-(i-1)));k<=min(n-j,loc-i+1);k++)
                f[loc][j+k]=min(f[loc][j+k],f[i-1][j]+p[i].a*k-mid*(sum[i+k-1]-sum[i-1]));
		}
	}
	for(int i=0;i<=n;i++) if(f[n][i]<=0) return true;
	return false;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].a=read(),p[i].a*=1000;
	for(int i=1;i<=n;i++) p[i].b=read();
	sort(p+1,p+n+1,cmp);
	ll l=1,r=1e16,ans;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(jud(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}