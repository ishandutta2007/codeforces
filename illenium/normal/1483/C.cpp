#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
#define inf 1e18
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

struct node{ll l,r,mx;}t[maxn<<2];
ll n,h[maxn],b[maxn],dp[maxn];

inline void build(int now,int l,int r)
{
	t[now].l=l; t[now].r=r; t[now].mx=-inf;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(now<<1,l,mid); build(now<<1|1,mid+1,r);
}

inline ll q(int now,int l,int r)
{
	//cout<<now<<" "<<l<<" "<<r<<endl;
	if(l>r) return 0;
	if(t[now].l==l&&t[now].r==r) return t[now].mx;
	int mid=(t[now].l+t[now].r)>>1;
	if(l>=mid+1) return q(now<<1|1,l,r);
	else if(r<=mid) return q(now<<1,l,r);
	else return max(q(now<<1,l,mid),q(now<<1|1,mid+1,r));
}

inline void upd(int now,int x,ll w)
{
	t[now].mx=max(t[now].mx,w);
	if(t[now].l==x&&t[now].r==x) return;
	int mid=(t[now].l+t[now].r)>>1;
	if(x>=mid+1) upd(now<<1|1,x,w);
	else if(x<=mid) upd(now<<1,x,w);
}

int pos[1000005],stk[1000005],top;

int main()
{
	n=read(); rep(i,1,n) h[i]=read(); rep(i,1,n) b[i]=read();
	build(1,1,n); rep(i,1,n) dp[i]=-inf;
	
	for(int i=1;i<=n;i++)
	{
		while(top&&h[i]<h[stk[top]])top--;
		pos[i]=stk[top];
		stk[++top]=i;
	}
	
	//rep(i,1,n) cout<<pos[i]<<" "; puts("");
	rep(i,1,n)
	{
		int f=pos[i]; if(f) dp[i]=dp[f];
		if(f==0) dp[i]=max(max(dp[i],q(1,f+1,i-1)+b[i]),b[i]);
		else dp[i]=max(dp[i],q(1,f,i-1)+b[i]);
		upd(1,i,dp[i]);
		
		//rep(j,1,n) cout<<q(1,j,j)<<" "; puts("");
		
	}
	//rep(i,1,n) cout<<dp[i]<<" "; puts("");
	cout<<dp[n]<<endl;
	return 0;
}