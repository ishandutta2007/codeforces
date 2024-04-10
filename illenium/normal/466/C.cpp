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

ll n,a[maxn],tot;
ll sa[maxn],sb[maxn],c[maxn],ans;

inline ll lowbit(int x){return x&(-x);}

inline void update(ll x,ll v)
{
	for(int i=x;i<=n;i+=lowbit(i)) c[i]+=v;
}

inline ll query(ll x)
{
	ll res=0;
	for(int i=x;i;i-=lowbit(i)) res+=c[i];
	return res;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),sa[i]=sa[i-1]+a[i];
	for(int i=n;i>=1;i--) sb[i]=sb[i+1]+a[i];
	if(sa[n]%3!=0) {puts("0"); return 0;}
	tot=sa[n]/3;
	for(int i=1;i<=n;i++) if(sa[i]==tot) update(i+1,1);
	for(int i=n;i>=1;i--) if(sb[i]==tot) ans+=query(i-1);
	cout<<ans;
	return 0;
}