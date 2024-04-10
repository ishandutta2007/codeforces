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
#define maxn 1000005
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

int n,a[maxn],cnt,f[maxn],g[maxn],tot,b[maxn],cnt1[maxn],cnt2[maxn];
ll ans,c[maxn];
map <int,int> mp,mpp;

inline int lowbit(int x){return x&(-x);}

inline int update(int x,ll v)
{
	for(int i=x;i<=n;i+=lowbit(i)) c[i]+=v;
}

inline ll query(int x)
{
	ll res=0;
	for(int i=x;i;i-=lowbit(i)) res+=c[i];
	return res;
}

int main()
{
	//freopen("CF459D.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	tot=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		int k=lower_bound(b+1,b+tot+1,a[i])-b;
		cnt1[k]++; f[i]=cnt1[k];
	}
	for(int i=n;i>=1;i--)
	{
		int k=lower_bound(b+1,b+tot+1,a[i])-b;
		cnt2[k]++; g[i]=cnt2[k];
	}
	for(int i=n;i>=2;i--)
	{
		update(g[i],1);
		ans+=query(f[i-1]-1);
	}
	cout<<ans;
	return 0;
}