#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=1e5+10;
ll bit[2][mn];
void up(int a,int b,ll c){for(;b<mn;b+=b&-b)bit[a][b]+=c;}
ll qu(int a,int b){ll c=0;for(;b;b-=b&-b)c+=bit[a][b];return c;}
vector<int>g[mn];
int o[mn],s[mn],dep[mn];
int anc[mn][17];
int ct=0;
void dfs(int x,int p){
    anc[x][0]=p;
    o[x]=++ct;
    s[x]=1;
    for(int y:g[x])if(y!=p){
        dep[y]=dep[x]+1;
        dfs(y,x);
        s[x]+=s[y];
    }
}
int rt=1;
inline bool bina(int a,int b){return o[a]<=o[b]&&o[b]<o[a]+s[a];}
int fabr(int x){
    for(int i=16;i>=0;i--)if(!bina(anc[x][i],rt))x=anc[x][i];
    if(!bina(x,rt))x=anc[x][0];
    return x;
}
int go(int a,int b){
    for(int i=0;b;b>>=1,i++)if(b&1)a=anc[a][i];
    return a;
}
int lca(int a,int b){
    if(dep[a]>dep[b])a=go(a,dep[a]-dep[b]);
    else b=go(b,dep[b]-dep[a]);
    if(a==b)return a;
    for(int i=16;i>=0;i--){
        if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    }
    return anc[a][0];
}
int slca(int a,int b){
    int aa=fabr(a),bb=fabr(b);
    if(aa!=bb)return bina(aa,bb)?bb:aa;
    return lca(a,b);
}
void upd(int l,int r,ll v){
    assert(l>=1);
    up(1,l,v);
    up(0,l,-v*(l-1));
    up(1,r+1,-v);
    up(0,r+1,v*(r));
}
ll que(int l,int r){
    assert(l>=0);
    return r*qu(1,r)+qu(0,r)-(l-1)*qu(1,l-1)-qu(0,l-1);
}
ll val[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    for(int i=1;i<17;i++)for(int j=1;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    for(int i=1;i<=n;i++)up(0,o[i],val[i]);
    while(m--){
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>a;
            rt=a;
        }
        else if(a==2){
            cin>>a>>b>>c;
            a=slca(a,b);
            if(bina(a,rt)){
                upd(1,n,c);
                if(a!=rt){
                    b=go(rt,dep[rt]-dep[a]-1);
                    upd(o[b],o[b]+s[b]-1,-c);
                }
            }
            else upd(o[a],o[a]+s[a]-1,c);
        }
        else{
            cin>>a;
            ll ans;
            if(bina(a,rt)){
                ans=que(1,n);
                if(a!=rt){
                    b=go(rt,dep[rt]-dep[a]-1);
                    ans-=que(o[b],o[b]+s[b]-1);
                }
            }
            else ans=que(o[a],o[a]+s[a]-1);
            printf("%lld\n",ans);
        }
    }
}