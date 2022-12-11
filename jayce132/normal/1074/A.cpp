#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;
const int inf=1e9;

int n,h[maxn],m;

struct node {
	int l,r,y;
};
node a[maxn];
int tot;
int R[maxn];

int main()
{
	n=read();m=read();
	REP(i,1,n)h[i]=read();h[++n]=inf;
	sort(h+1,h+n+1);
	REP(i,1,m)
	{
		int l=read(),r=read(),y=read();
		a[i]=(node){l,r,y};
		//int t=upper_bound(h+1,h+n+1,r)-h;
		//R[++tot]=t;
	}
	sort(a+1,a+m+1,[](node a,node b){ return a.y==b.y?a.l<b.l:a.y<b.y; });
	REP(i,1,m)
	{
		if(a[i].y==a[tot].y)
		{
			if(a[i].l==a[tot].r)a[tot].r=a[i].r;
		}else a[++tot]=a[i];
	}

	int tt=0;
	
	REP(i,1,tot)
	{
		if(a[i].l>1)continue;
		int t=upper_bound(h+1,h+n+1,a[i].r)-h;
		R[++tt]=t;
	}
	
	sort(R+1,R+tt+1);
	int ans=tt,mx=1;
	REP(i,1,tt)
	{
		mx=max(R[i],mx);
		if(mx<=n)ans=min(ans,tt-i+mx-1);
	}
	if(mx<=n)ans=min(ans,mx-1);
	cout<<ans<<endl;
	return 0;
}