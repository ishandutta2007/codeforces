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

#define int ll

const int maxn=100;
const int inf=1e9;

int n;

char str[maxn];

inline int GetCol()
{
	cout<<flush;
	scanf("%s",str);
	if(str[0]=='w')return 1;
	else return 0;
}

inline void OUT(int x,int y)
{
	cout<<x<<" "<<y<<endl;
	
}

int c0,c1;

signed main()
{
	n=read();
	OUT(0,0);
	c0=GetCol();

	if(n==1)
	{
		printf("%d %d %d %d\n",1,0,0,1);
		exit(0);
	}
	
	OUT(inf,inf);
	c1=GetCol();

	if(n==2)
	{
		if(c0!=c1)
		{
			printf("%d %d %d %d\n",1,0,0,1);
		}else
		{
			printf("%d %d %d %d\n",1,0,2,1);
		}
	}
	
	if(c0==c1)
	{
		int l=1,r=inf;
		REP(i,3,n)
		{
			int mid=(l+r)>>1;
			OUT(mid,0);
			int col=GetCol();
			if(col==c0)l=mid+1;
			else r=mid-1;
		}
		printf("%lld %d %lld %d\n",l,0,l+1,1);
	}else
	{
		int l=1,r=(inf<<1)-1;
		REP(i,3,n)
		{
			int mid=(l+r)>>1;
			OUT(mid>>1,mid-(mid>>1));
			int col=GetCol();
			if(col==c0)l=mid+1;
			else r=mid-1;
		}
		int l2=l>>1;
		printf("%lld %lld %lld %lld\n",l-l2,l2,l-1-l2,l2+1);
	}
	
	return 0;
}