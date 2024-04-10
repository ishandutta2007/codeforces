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

const int maxn=4e5+20;

map<int,int>mp;
int rk[maxn],tot;

int fa[maxn],w[maxn];

inline void Check(int x)
{
	if(mp.count(x))return;
	rk[++tot]=x; mp[x]=tot;
}

int fin(int x)
{
	if(x==fa[x])return x;
	int ff=fin(fa[x]);
	w[x]^=w[fa[x]];
	fa[x]=ff;
	return ff;
}

inline void merge(int x,int y,int W)
{
	int X,Y;
	X=fin(x); Y=fin(y);
	fa[Y]=fa[X];
	w[Y]=w[y]^w[x]^W;
}

inline void init()
{
	int t=read();
	rk[++tot]=0;mp[0]=tot;

	REP(i,1,2*t+1)fa[i]=i,w[i]=0;
	int ans=0;
	while(t--)
	{
		int op=read(),l=read()^ans,r=read()^ans;
		int x;
		if(op==1)x=read()^ans;
		if(l>r)swap(l,r); r++;

		if(op==2 && (!mp.count(r) || !mp.count(l)))ans=1,puts("-1");
		else {
			Check(l); Check(r);
			int a=mp[l],b=mp[r];
			if(op==1)
			{
				if(fin(a)!=fin(b))merge(a,b,x);
			}else
			{
				if(fin(a)==fin(b))
				{
					fin(a);fin(b);
					printf("%d\n",ans=(w[a]^w[b]));
				}else ans=1,puts("-1");
			}
			
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	init();
	return 0;
}