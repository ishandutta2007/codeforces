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

struct node{ll l,r;}p[maxn];
ll n,s,ans;

inline bool cmp1(node x,node y)
{
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}

inline bool cmp2(node x,node y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}

inline bool jud(ll x)
{
	ll tmp=0,cnt=(n/2+1);
	for(int i=n;i>=1;i--)
	{
		if(p[i].r>=x&&cnt)
		{
			tmp+=max(p[i].l,x);
			cnt--;
		}
		else tmp+=p[i].l;
	}
	if(cnt==0&&tmp<=s) return true;
	return false;
}

int main()
{
	ll T=read();
	while(T--)
	{
		n=read(); s=read(); ans=0;
		for(int i=1;i<=n;i++) p[i].l=read(),p[i].r=read();
		ll l=0,r=1e15,mid=0;
		sort(p+1,p+n+1,cmp2);
		r=p[(n/2)+1].r;
		sort(p+1,p+n+1,cmp1);
		l=p[(n/2)+1].l;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(jud(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}