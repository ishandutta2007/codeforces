 #include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=998244353;
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
struct edge{
    int a,b,c,d,ind;
    bool operator<(const edge&ot)const{return c<ot.c;}
};
vector<edge>ed(mn);
vector<bool>u(mn);
vector<pii>g[mn];
int dep[mn],anc[mn][18],ma[mn][18];
void dfs(int x,int p){
    for(pii y:g[x])if(y.first!=p){
        anc[y.first][0]=x;
        ma[y.first][0]=y.second;
        dep[y.first]=dep[x]+1;
        dfs(y.first,x);
    }
}
int ans1;
inline int mama(int a,int b){
    return ed[a].c>ed[b].c?a:b;
}
void go(int&a,int b){
    for(int i=0;b;b>>=1,i++)if(b&1)ans1=mama(ans1,ma[a][i]),a=anc[a][i];
}
int hail(int a,int b){
    ans1=0;
    if(dep[a]>dep[b])go(a,dep[a]-dep[b]);
    else go(b,dep[b]-dep[a]);
    for(int i=17;i>=0;i--){
        if(anc[a][i]!=anc[b][i]){
            ans1=mama(ans1,ma[a][i]),a=anc[a][i];
            ans1=mama(ans1,ma[b][i]),b=anc[b][i];
        }
    }
    if(a!=b)ans1=mama(ans1,mama(ma[a][0],ma[b][0]));
    return ans1;
}
int main(){
    int n,m;
    ll s;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",&ed[i].c);
    for(int i=0;i<m;i++)scanf("%d",&ed[i].d);
    for(int i=0;i<m;i++)scanf("%d%d",&ed[i].a,&ed[i].b),ed[i].ind=i+1;
    scanf("%lld",&s);
    iota(p,p+mn,0);
    sort(ed.begin(),ed.begin()+m);
    ll sum=0,sm=0x3f3f3f3f3f3f3f3f,ans=0x3f3f3f3f3f3f3f3f;
    pii swa;
    for(int i=0;i<m;i++){
        if(f(ed[i].a)!=f(ed[i].b)){
            p[f(ed[i].a)]=f(ed[i].b);
            sum+=ed[i].c;
            u[i]=1;
            if(ed[i].d<sm)swa={i,i};
            sm=min(sm,(ll)ed[i].d);
            g[ed[i].a].push_back({ed[i].b,i});
            g[ed[i].b].push_back({ed[i].a,i});
        }
    }
    ans=sum-s/sm;
    dfs(1,1);
    anc[1][0]=1;
    for(int i=1;i<18;i++)for(int j=1;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1],ma[j][i]=mama(ma[j][i-1],ma[anc[j][i-1]][i-1]);
    for(int i=0;i<m;i++)if(!u[i]){
        ll hhh=hail(ed[i].a,ed[i].b);
        ll cand=sum-ed[hhh].c+ed[i].c-s/ed[i].d;
        if(cand<ans)ans=cand,swa={i,hhh};
    }
    if(swa.first!=swa.second)u[swa.first]=1,u[swa.second]=0;
    printf("%lld\n",ans);
    for(int i=0;i<m;i++)if(u[i]){
        printf("%d ",ed[i].ind);
        if(swa.first==i)printf("%lld\n",ed[i].c-1LL*s/ed[i].d);
        else printf("%d\n",ed[i].c);
    }
}