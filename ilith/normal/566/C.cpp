#include<bits/stdc++.h>
#define pbk emplace_back
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<db,int> pdi;
const int N=2e5+7;
int n,w[N],sz[N],vis[N],gr[N];
struct edge{int to,vl;edge(int TO,int VL){to=TO,vl=VL;}};
pdi ans={1e30,0};
vector<edge>a[N];
int get(int x,int su,int f){
    sz[x]=1,gr[x]=0;
    int g=0;
    for(edge k:a[x])if(k.to!=f&&!vis[k.to]){
        int h=get(k.to,su,x);
        sz[x]+=sz[k.to],gr[x]=max(sz[k.to],gr[x]);
        if(gr[h]<gr[g])g=h;
    }
    gr[x]=max(gr[x],su-sz[x]);
    if(gr[x]<gr[g])g=x;
    return g;
}
db dv[N];
void calc(int x,int d,int f,db &rs){
    dv[x]=sqrt(d)*w[x],rs+=d*sqrt(d)*w[x];
    for(edge k:a[x])if(k.to!=f){
        calc(k.to,d+k.vl,x,rs),dv[x]+=dv[k.to];
    }
};
void solve(int x,int su){
    get(x=get(x,su,0),su,0),vis[x]=1;
    pdi rs={0,x};calc(x,0,0,rs.fi);
    ans=min(ans,rs);
    for(edge k:a[x])if(!vis[k.to]&&dv[k.to]*2>dv[x]){
        return solve(k.to,sz[k.to]);
    }
}
signed main(){
    scanf("%d",&n),gr[0]=N;
    FOR(i,1,n)scanf("%d",w+i);
    FOR(i,2,n){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x].pbk(y,z),a[y].pbk(x,z);
    }
    solve(1,n);
    printf("%d %.9lf",ans.se,ans.fi);
    return 0;
}