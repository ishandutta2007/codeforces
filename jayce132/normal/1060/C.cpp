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

const int maxn=2e3+20;

int n,m,a[maxn],b[maxn];
int la[maxn],lb[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)a[i]=read()+a[i-1];
	REP(i,1,m)b[i]=read()+b[i-1];
	memset(la,63,sizeof(la)); memset(lb,63,sizeof(lb));
	REP(len,1,n)
	{
		REP(l,1,n-len+1)
		{
			int r=l+len-1;
			chkmin(la[len],a[r]-a[l-1]);
			
		}
	}
	REP(len,1,m)
	{
		REP(l,1,m-len+1)
		{
			int r=l+len-1;
			chkmin(lb[len],b[r]-b[l-1]);
			
		}
	}
	int x,ans=0;
	cin>>x;
	REP(i,1,n)REP(j,1,m)if((ll)la[i]*lb[j]<=x)chkmax(ans,i*j);
	printf("%d\n",ans);
}

int main()
{
	init();
	return 0;
}