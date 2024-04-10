#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=3e4+10;
const ll mod=1e9+7;
struct dsu{
    int p[mn];
    dsu(){iota(p,p+mn,0);}
    int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
    bool u(int a,int b){a=f(a),b=f(b);p[a]=b;return a!=b;}
}ds[3];
struct edge{int a,b,c;};
int ans=INT_MAX,cans;
pii wa,cwa;
vector<int>g[mn];
vector<pii>gg[mn];
vector<int>val;
vector<edge>ed;
int l,r;
int scc[mn],o[mn],lo[mn];
bool ins[mn],vis[mn];
int ct,sct;
stack<int>s;
inline int go(int x,int i){return ed[i].a^ed[i].b^x;}
void dfs(int x,int le){
    o[x]=lo[x]=ct++;
    vis[x]=ins[x]=1;
    s.push(x);
    for(int i:g[x]){
        int y=ed[i].a^ed[i].b^x;
        if(i==le)continue;
        if(!vis[y])dfs(y,i),lo[x]=min(lo[x],lo[y]);
        else if(ins[y])lo[x]=min(lo[x],o[y]);
    }
    if(o[x]==lo[x]){
        while(s.top()!=x)scc[s.top()]=sct,ins[s.top()]=0,s.pop();
        scc[x]=sct++,ins[x]=0,s.pop();
    }
}
pii vesh;
bool dfs2(int x,int p){
    if(x==scc[r])return 1;
    for(pii idk:gg[x])if(idk.first!=p){
        if(dfs2(idk.first,x)){
            vesh=min(vesh,{ed[idk.second].c,idk.second});
            return 1;
        }
    }
    return 0;
}
int n,m;
pii solve(){
    ct=sct=0;
    for(int i=0;i<=n;i++)scc[i]=o[i]=lo[i]=ins[i]=vis[i]=0;
    while(s.size())s.pop();
    dfs(l,0);
    if(!vis[r])return {0,0};
    if(scc[l]==scc[r])return{INT_MAX,0};
    for(int i=0;i<sct;i++)gg[i].clear();
    for(int i=1;i<=n;i++)if(vis[i])for(int jj:g[i]){
        int j=go(i,jj);
        if(scc[i]!=scc[j])gg[scc[i]].push_back({scc[j],jj});
    }
    vesh={INT_MAX,INT_MAX};
    dfs2(scc[l],-1);
    return vesh;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&l,&r);
    ed.push_back({});
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ed.push_back({a,b,c});
        if(ds[0].u(a,b))val.push_back(i);
        else if(ds[1].u(a,b))val.push_back(i);
        else if(ds[2].u(a,b))val.push_back(i);
    }

    for(int i=-1;i<(int)val.size();i++){
        cans=i>=0?ed[val[i]].c:0;
        cwa={i>=0?val[i]:0,0};
        for(int j=0;j<val.size();j++)if(i!=j)g[ed[val[j]].a].push_back(val[j]),g[ed[val[j]].b].push_back(val[j]);
        pii p=solve();
        for(int j=1;j<=n;j++)g[j].clear();
        if(p.first==INT_MAX)continue;
        cans+=p.first,cwa.second=p.second;
        if(!cwa.first)cwa.first=cwa.second,cwa.second=0;
        if(cans<ans)ans=cans,wa=cwa;
    }
    if(ans==INT_MAX)printf("-1");
    else if(ans==0)printf("0\n0\n");
    else if(!wa.second)printf("%d\n1\n%d",ans,wa.first);
    else printf("%d\n2\n%d %d",ans,wa.first,wa.second);
}