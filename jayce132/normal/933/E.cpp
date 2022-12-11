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

const int maxn=3e5+20;

int n,a[maxn];

inline void init()
{
    n=read();REP(i,1,n)a[i]=read();
}

ll dp[maxn];int pre[maxn];
int val[maxn],na[maxn];
vector<int>ans,nans;

inline void work(int x){ int t=min(na[x],na[x+1]);if(t)nans.push_back(x),na[x]-=t,na[x+1]-=t;}

inline void doing()
{
    dp[0]=0;dp[1]=a[1];pre[1]=1; dp[2]=a[2]; pre[2]=1;
    REP(i,3,n)
    {
	ll A=dp[i-3]+max(a[i],a[i-1]),B=dp[i-2]+a[i];
	if(A<B)dp[i]=A,pre[i]=2;
	else dp[i]=B,pre[i]=1;
    }
    int now=dp[n-1]<dp[n]?n-1:n;
    
    REP(i,1,n)na[i]=a[i];
    while(now>0)
    {
	int t=pre[now];
	if(t==2)
	{
	    if(na[now-1]>na[now])work(now-1),work(now-2);
	    else work(now-1),work(now);
	}else
	{
	    work(now); work(now-1);
	}
	now-=t+1;
    }
    printf("%d\n",SZ(nans));
    for(int x:nans)printf("%d\n",x);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}