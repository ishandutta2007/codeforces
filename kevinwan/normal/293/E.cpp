#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
vector<int>g[mn],w[mn];
int lll,ww;
int s[mn],lev[mn];
void gs(int x,int p,int l){
    s[x]=1;
    for(int y:g[x])if(y!=p&&lev[y]>l){
            gs(y,x,l);
            s[x]+=s[y];
        }
}
void gc(int x,int l){
    gs(x,0,l);
    int ss=s[x];
    vesh:
    for(int y:g[x]){
        if(s[y]*2>ss&&s[y]<s[x]&&lev[y]>l){
            x=y;
            goto vesh;
        }
    }
    lev[x]=l;
    for(int y:g[x])if(lev[y]>l)gc(y,l+1);
}
ll ans;
vector<pii>v;
void dfs(int x,int p,int l,int cl,int cw){
    v.push_back({cl,cw});
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y!=p&&lev[y]>l){
            dfs(y,x,l,cl+1,cw+w[x][i]);
        }
    }
}
int bit[mn];
void upd(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(a=max(a,0);a;a-=a&-a)b+=bit[a];return b;}
ll hail(vector<pii>&v){
    sort(v.begin(),v.end(),[](pii a,pii b){return a.second<b.second;});
    int i,j;
    ll ans=0;
    for(i=v.size()-1,j=0;i>=0;i--){
        while(j<v.size()&&v[i].second+v[j].second<=ww){
            upd(v[j++].first,1);
        }
        ans+=qu(lll-v[i].first);
    }
    for(j--;j>=0;j--)upd(v[j].first,-1);
    return ans;
}
void eval(int x){
    vector<pii>vv;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(lev[y]>lev[x]){
            dfs(y,x,lev[x],1,w[x][i]);
            ans-=hail(v);
            for(pii p:v)vv.push_back(p);
            v.clear();
        }
    }
    ans+=hail(vv);
    for(pii p:vv)if(p.first<=lll&&p.second<=ww)ans+=2;
}
int main(){
    int n;
    scanf("%d%d%d",&n,&lll,&ww);
    for(int i=2;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(i);
        w[a].push_back(b);
        g[i].push_back(a);
        w[i].push_back(b);
    }
    memset(lev,0x3f,sizeof(lev));
    gc(1,0);
    for(int i=1;i<=n;i++){
        eval(i);
    }
    printf("%lld",ans/2);
}