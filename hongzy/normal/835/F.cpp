#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=200000+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
int n;
struct Edge{
    int to,from,cost;
}edge[maxn<<1];
int last[maxn<<1],cnt=0;
int huan[maxn],huan_cnt=0,huan_zhi[maxn],fa[maxn],cost[maxn],huan_sign[maxn];
int dfn[maxn],timee=0;
ll dis[maxn];
ll ans=0,ans1=0;
ll A[maxn],B[maxn];
//A[i] +
//B[i]+
ll C[maxn],D[maxn]; //
//ii+1 ans=max(max(B[i],D[i+1]),A[i]+C[i+1]+1-->cnt)
inline int read(){
    int a=1,b=0;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') a=-1;c=getchar();}
    while(c>='0'&&c<='9'){b=(b<<3)+(b<<1)+c-'0';c=getchar();}
    return a*b;
}
inline void print(ll x){
    if(x<0) x=-x,putchar('-');
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
inline void pre(){

}
inline void add(int x,int y,int z){
    edge[++cnt].to=y;
    edge[cnt].cost=z;
    edge[cnt].from=last[x];
    last[x]=cnt;
}
inline void input(){int xx,yy,zz;
    n=read();
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        xx=read(),yy=read(),zz=read();
        add(xx,yy,zz);
        add(yy,xx,zz);
    }
}
inline void dfs(int now){//
    dfn[now]=++timee;
    for(int i=last[now];i;i=edge[i].from)
    {
        int to=edge[i].to;
        if(to!=fa[now])
        {
            if(!dfn[to])
            {
                fa[to]=now;
                cost[to]=edge[i].cost;
                dfs(to);
            }
            else if(dfn[to]>dfn[now])
            {
                for(;to!=now;to=fa[to])
                {
                    huan_sign[to]=1;
                    huan[++huan_cnt]=to;
                    huan_zhi[huan_cnt]=cost[to];
                }
                huan_sign[now]=1;
                huan[++huan_cnt]=now;
                huan_zhi[huan_cnt]=edge[i].cost;
            }

        }
    }
}
inline void DP(int now,int father){//dis[i]i
    for(int i=last[now];i;i=edge[i].from)
    {
        int to=edge[i].to;
        if(!huan_sign[to]&&to!=father)
        {
            DP(to,now);
            ans=max((ll)dis[now]+dis[to]+edge[i].cost,ans);
            dis[now]=max(dis[now],dis[to]+edge[i].cost);
        }
    }
}
inline void solve(){
    dfs(1);
    for(int i=1;i<=huan_cnt;++i) DP(huan[i],0);
    ll sum=0,maxx=0;
    for(int i=1;i<=huan_cnt;++i)
    {
        sum+=huan_zhi[i-1];
        A[i]=max(A[i-1],dis[huan[i]]+sum);
        B[i]=max(B[i-1],sum+maxx+dis[huan[i]]);
        maxx=max(maxx,dis[huan[i]]-sum);
    }
    sum=maxx=0;
    int tmp=huan_zhi[huan_cnt];huan_zhi[huan_cnt]=0;
    for(int i=huan_cnt;i>=1;--i)
    {
        sum+=huan_zhi[i];
        C[i]=max(C[i+1],dis[huan[i]]+sum);
        D[i]=max(D[i+1],sum+maxx+dis[huan[i]]);
        maxx=max(maxx,dis[huan[i]]-sum);
    }
    ll tep;
    ans1=B[huan_cnt];
    for(int i=1;i<huan_cnt;++i)
    {
        tep=max(B[i],D[i+1]);
        tep=max(tep,A[i]+C[i+1]+tmp);
        ans1=min(tep,ans1);
    }
    ans=max(ans,ans1);
    if(ans&1) print(ans),puts("");
    else print(ans),puts("");
}
inline void output(){

}
int main(){int T;
    T=1;
    while(T--)
    {
        pre();
        input();
        solve();
        output();
    }
    return  0;
}