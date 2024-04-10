#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=2e5+10;
struct edge{int a,b,c,i;};
vector<edge>v;
vector<int>g[mn];
bool u[mn];
int p[mn];
int f(int x){return p[x]==x?x:(p[x]=f(p[x]));}
int lev[mn],s[mn];
int anc[mn][18],ac[mn][18],bac[mn][18];
int gy(int x,int i){return v[i].a^v[i].b^x;}
void gs(int x,int p,int l){
    s[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=gy(x,g[x][i]);
        if(y!=p&&lev[y]>=l){
            gs(y,x,l);
            s[x]+=s[y];
        }
    }
}
void gc(int x,int p,int l){
    gs(x,0,l);
    int ms=s[x];
    vesh:
    for(int i=0;i<g[x].size();i++){
        int y=gy(x,g[x][i]);
        if(s[y]<s[x]&&lev[y]>=l&&s[y]*2>=ms){
            x=y;
            goto vesh;
        }
    }
    memcpy(anc[x],anc[p],sizeof(anc[x]));
    anc[x][lev[x]=l]=x;
    for(int i=0;i<g[x].size();i++){
        int y=gy(x,g[x][i]);
        if(lev[y]>=l)gc(y,x,l+1);
    }
}
void dfs(int x,int p,int l){
    for(int i=0;i<g[x].size();i++){
        int y=gy(x,g[x][i]);
        if(y!=p&&lev[y]>=l){
            ac[y][l]=max(ac[x][l],v[g[x][i]].c);
            dfs(y,x,l);
        }
    }
}
int qu(int a,int b,int c){
    int l=min(lev[a],lev[b]);
    while(anc[a][l]!=anc[b][l])l--;
    bac[a][l]=min(bac[a][l],c);
    bac[b][l]=min(bac[b][l],c);
    return max(ac[a][l],ac[b][l]);
}
int ans[mn];
void hail(int x,int p,int l){
    for(int i=0;i<g[x].size();i++){
        int y=gy(x,g[x][i]);
        if(y!=p&&lev[y]>=l){
            hail(y,x,l);
            int ind=v[g[x][i]].i;
            ans[ind]=min(ans[ind],bac[y][l]);
            bac[x][l]=min(bac[x][l],bac[y][l]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c,i});
    }
    sort(v.begin(),v.end(),[](auto a,auto b){return a.c<b.c;});
    iota(p,p+mn,0);
    for(edge e:v){
        if(f(e.a)!=f(e.b)){
            u[e.i]=1;
            p[f(e.a)]=f(e.b);
            g[e.a].push_back(e.i);
            g[e.b].push_back(e.i);
        }
    }
    sort(v.begin(),v.end(),[](auto a,auto b){return a.i<b.i;});
    memset(lev,0x3f,sizeof(lev));
    gc(1,0,0);
    for(int i=1;i<=n;i++)dfs(i,0,lev[i]);
    memset(bac,0x3f,sizeof(bac));
    memset(ans,0x3f,sizeof(ans));
    for(edge e:v)if(!u[e.i]){
        int val=qu(e.a,e.b,e.c);
        ans[e.i]=val;
    }
    for(int i=1;i<=n;i++)hail(i,0,lev[i]);
    for(int i=0;i<m;i++)printf("%d ",ans[i]==0x3f3f3f3f?-1:(ans[i]-1));
}