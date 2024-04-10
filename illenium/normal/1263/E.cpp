#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

char s[maxn],c[maxn];
struct node{int l,r,len,w,mx,mn;}t[maxn<<2];
int amn,amx,aval;

inline void pd(int now)
{
	if(t[now].l!=t[now].r)
	{
		t[now<<1].w+=t[now].w;
		t[now<<1|1].w+=t[now].w;
	}
	t[now].mx+=t[now].w; t[now].mn+=t[now].w; t[now].w=0;
}

inline void upd(int now)
{
	t[now].mn=min(t[now<<1].mn,t[now<<1|1].mn);
	t[now].mx=max(t[now<<1].mx,t[now<<1|1].mx);
}

inline void build(int now,int l,int r)
{
	t[now].l=l; t[now].r=r; t[now].len=r-l+1;
	if(l==r) return; int mid=(l+r)>>1;
	build(now<<1,l,mid),build(now<<1|1,mid+1,r);
}

inline void add(int now,int l,int r,int x)
{
	if(t[now].w!=0) pd(now);
	if(t[now].l==l&&t[now].r==r){t[now].w+=x; pd(now); return;}
	int mid=(t[now].l+t[now].r)>>1;
	if(l>=mid+1) add(now<<1|1,l,r,x),pd(now<<1);
	else if(r<=mid) add(now<<1,l,r,x),pd(now<<1|1);
	else add(now<<1,l,mid,x),add(now<<1|1,mid+1,r,x); upd(now);
}

int main()
{
	int n=read(),nw=1,cnt=0; scanf("%s",s+1); build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='R') nw++;
		else if(s[i]=='L') nw=max(1,nw-1);
		else
		{
			if(c[nw]=='(') add(1,nw,n,-1),cnt--;
			else if(c[nw]==')') add(1,nw,n,1),cnt++;
			
			if(s[i]=='(') add(1,nw,n,1),cnt++;
			else if(s[i]==')') add(1,nw,n,-1),cnt--; c[nw]=s[i];
		}
		if(t[1].w) pd(1);
		if(t[1].mn<0||cnt!=0) printf("-1 ");
		else printf("%d ",t[1].mx);
	}
	return 0;
}