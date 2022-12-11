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

const int maxn=120;

int n;

map<int,int>mp;

int x[maxn],y[maxn],ans[maxn];
int num;

inline void Getval(int t)
{
    printf("+ %d",t); cout<<endl;
    x[++num]=read() ;y[num]=read();
}



int main()
{
    memset(ans,-1,sizeof(ans));
    n=read();
    x[0]=read();y[0]=read();
    REP(i,1,n-1)Getval(i); Getval(1);
    DREP(i,n,1)x[i]-=x[i-1],y[i]-=y[i-1];
    mp[0]=2;
    REP(i,2,n)mp[i*(i-1)/2]=i;

    ans[1]=x[n]-x[1];
    REP(i,2,n-1)if(x[i])ans[i]=mp[x[i]];
    if(ans[3]==-1)ans[3]=y[2]?1:0;
    if(ans[2]==-1)ans[2]=y[n]/(ans[3]+1)-1;
    //REP(i,1,n)cerr<<y[i]<<" ";cerr<<endl;
    
    REP(i,4,n-1)
    {
	if(ans[i]==-1)ans[i]=(y[i-1]-(ans[i-2]+1)*(ans[i-3]+1))?1:0;
    }
    ans[n]=(y[n-1]-(ans[n-2]+1)*(ans[n-3]+1))/(ans[n-2]+1);
    printf("!");REP(i,1,n)printf(" %d",ans[i]);cout<<endl;
    return 0;
}

/*1 6 2 9 2 18 5 24 5 40 8 48*/