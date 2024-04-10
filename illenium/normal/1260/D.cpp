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
#define maxn 500005
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

ll m,n,k,t,a[maxn],cnt[maxn];
struct node{ll l,r,d;}p[maxn];

inline bool cmp(ll a,ll b){return a>b;}

inline bool jud(int x)
{
	for(int i=0;i<=n+1;i++) cnt[i]=0;
	for(int i=1;i<=k;i++)
	{
		if(p[i].d<=a[x]) continue;
		cnt[p[i].l]++;
		cnt[p[i].r+1]--;
	}
	ll tmp=0,tmp2=0,ans=0;
	for(int i=0;i<=n+1;i++)
	{
		tmp+=cnt[i];
		if(tmp) tmp2++;
	}
	ans=2*tmp2+n+1;
	//cout<<ans<<" "<<t<<endl;
	if(ans<=t) return true;
	return false;
}

int main()
{
	m=read(); n=read(); k=read(); t=read();
	for(int i=1;i<=m;i++) a[i]=read();
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++) p[i].l=read(),p[i].r=read(),p[i].d=read();
	int l=1,r=m,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}