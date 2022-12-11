#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=2e5+20;

int a[maxn];

int mn[maxn],cmn[maxn];
int num[maxn];

inline void update(int x,int d)
{
    num[x]++;
    if(d<mn[x])cmn[x]=mn[x],mn[x]=d;
    else if(d<cmn[x])cmn[x]=d;
}

int main()
{
    int n=read();
    REP(i,1,2e5)mn[i]=cmn[i]=100000;
    REP(i,1,n)
    {
	int x=read();
	for(int j=2;j*j<=x;j++)
	{
	    int s=0;
	    while(!(x%j))x/=j,s++;
	    update(j,s);
	}
	if(x>1)update(x,1);
    }
    ll ans=1;
    REP(i,1,2e5)
    {
	if(num[i]==n-1)
	{
	    REP(j,1,mn[i])ans=ans*i;
	    
	}else if(num[i]==n)
	{
	    REP(j,1,cmn[i])ans=ans*i;
	}
    }
    printf("%lld\n",ans);
    return 0;
}