#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=4e3+100;

int n,a[maxn],all;
int b[maxn],p[maxn],q[maxn],id[maxn];

inline void init()
{ 
	n=read(); all=1<<n;
	int sum=0;
	REP(i,0,(1<<n)-1)a[i]=read(),sum^=a[i];
	if(sum)puts("Fou"),exit(0);
}

inline void doing()
{
	REP(i,0,all-1)p[i]=q[i]=id[i]=i,b[i]=0;
	REP(th,1,all-1)
	{
		int x=b[th]^a[th],i=0,j=th,t=id[p[i]^x];
		b[th]^=x; b[0]^=x;
		while(t!=i)
		{
			id[p[i]]=t; id[p[t]]=i; swap(p[i],p[t]);
			if(t==j)break;
			
			swap(q[j],q[t]);
			x=b[j]^p[j]^q[j];
			i=t;
			t=id[p[i]^x];
		}
	}
	puts("Shi");
	REP(i,0,all-1)printf("%d ",p[i]);puts("");
	REP(i,0,all-1)printf("%d ",q[i]);puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}