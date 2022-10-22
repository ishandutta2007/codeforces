#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=2e5+10;
vector<int>g[mn];
int lev[mn],s[mn];
void gs(int x,int p,int l){
    s[x]=1;
    for(int y:g[x])if(y!=p&&lev[y]>=l){
        gs(y,x,l);
        s[x]+=s[y];
    }
}
void gc(int x,int l){
    gs(x,x,l);
    int ms=s[x];
    vesh:
    for(int y:g[x])if(s[y]<s[x]&&lev[y]>=l){
        if(s[y]*2>=ms){
            x=y;
            goto vesh;
        }
    }
    lev[x]=l;
    for(int y:g[x])if(lev[y]>=l)gc(y,l+1);
}
ll ans[mn],f[mn];
int cnt[1<<20];
string v;
vector<pii>w,ww;
void dfs1(int x,int p,int l,int c){
    c^=1<<v[x];
    w.push_back({c,x});
    ww.push_back({c,x});
    for(int y:g[x])if(y!=p&&lev[y]>=l)dfs1(y,x,l,c);
}
void dfs2(int x,int p,int l){
    for(int y:g[x])if(y!=p&&lev[y]>=l)dfs2(y,x,l);
    ans[x]+=f[x];
    if(p)f[p]+=f[x];
    f[x]=0;
}
ll hail(vector<pii>&w,int sgn,int mas){
    for(pii p:w)cnt[p.first]++;
    ll ans=0;
    for(pii p:w){
        for(int i=-1;i<20;i++){
            int mmm=(i>=0?(1<<i):0)^(1<<v[mas]);
            int tar=p.first^mmm;
            ans+=sgn*cnt[tar];
            f[p.second]+=sgn*cnt[tar];
        }
    }
    for(pii p:w)cnt[p.first]--;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>v;
    for(char&c:v)c-='a';
    v=" "+v;
    memset(lev,0x3f,sizeof(lev));
    gc(1,0);
    for(int i=1;i<=n;i++){
        w.clear();
        ll tot=0;
        for(int j:g[i])if(lev[j]>=lev[i]){
            ww.clear();
            dfs1(j,i,lev[i],0);
            tot+=hail(ww,-1,i);
        }
        tot+=hail(w,1,i);
        f[i]-=tot/2;
        for(pii p:w)if(__builtin_popcount(p.first^(1<<v[i]))<=1)f[p.second]++;
        f[i]++;
        dfs2(i,0,lev[i]);
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}