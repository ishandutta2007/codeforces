#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
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

struct node{int l,r,id;}p[maxn];
int n,q,a[maxn],ans[maxn],v[65],pos[65];

inline bool cmp(node a,node b)
{
	if(a.r!=b.r) return a.r<b.r;
	return a.l<b.l;
}

inline void ins(int x,int p)
{
	for(int i=20;i>=0;i--)
	{
		if(x&(1ll<<i))
		{
			if(!v[i]) {v[i]=x; pos[i]=p; break;}
			if(pos[i]<p)
			{
				swap(v[i],x);
				swap(pos[i],p);
			}
			x^=v[i];
		}
	}
}

inline int qm(int l)
{
	int tmp=0;
	for(int i=20;i>=0;i--) if((tmp^v[i])>tmp&&pos[i]>=l) tmp^=v[i];
	return tmp;
}

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	q=read(); rep(i,1,q) p[i].l=read(),p[i].r=read(),p[i].id=i;
	sort(p+1,p+q+1,cmp); int nw=1;
	rep(i,1,q)
	{
		while(nw<=p[i].r) ins(a[nw],nw),nw++;
		ans[p[i].id]=qm(p[i].l);
	}
	rep(i,1,q) printf("%d\n",ans[i]);
	return 0;
}