#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n;
ll m;
vector<int>g[mn],d[mn];
int lev[mn];
int s[mn];
ll abc;
ll pow(ll a,ll b=abc-1){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=m)if(b&1)ans*=a,ans%=m;
    return ans;
}
void gs(int x,int p,int l){
    s[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        if(lev[y]<l)continue;
        gs(y,x,l);
        s[x]+=s[y];
    }
}
void gc(int x,int p,int l){
    gs(x,p,l);
    int num=s[x];
    vesh:
    for(int y:g[x]){
        if(y==p)continue;
        if(lev[y]<l)continue;
        if(s[y]*2>num){
            p=x,x=y;
            goto vesh;
        }
    }
    lev[x]=l;
    for(int y:g[x])if(lev[y]>=l)gc(y,x,l+1);
}
ll ans;
vector<pll>lo[mn],hi[mn];
ll po[mn],ipo[mn];
void dfs(int x,int p,ll alo,ll ahi,int len,int l,int tar){
    lo[tar].push_back({len,alo});
    hi[tar].push_back({len,ahi});
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        if(lev[y]<l)continue;
        int w=d[x][i];
        dfs(y,x,(alo*10+w)%m,(ahi+po[len]*w)%m,len+1,l,tar);
    }
}
void veshy(int x,int l){
    vector<ll>high;
    for(int i=0;i<g[x].size();i++) {
        int y = g[x][i];
        if (lev[y] > l) {
            lo[y].clear(), hi[y].clear();
            dfs(y, x, d[x][i]%m, d[x][i]%m, 1, l,y);
            for(auto p:hi[y])high.push_back(p.second);
            for(auto p:lo[y])if(p.second%m==0)ans++;
            for(auto p:hi[y])if(p.second%m==0)ans++;
            vector<ll>hhh;
            for(auto p:hi[y])hhh.push_back(p.second);
            sort(hhh.begin(),hhh.end());
            for(auto p:lo[y]){
                ll ot=-p.second*ipo[p.first]%m;
                if(ot<0)ot+=m;
                ans-=upper_bound(hhh.begin(),hhh.end(),ot)-lower_bound(hhh.begin(),hhh.end(),ot);
            }

        }
    }
    sort(high.begin(),high.end());
    for(int y:g[x])if(lev[y]>l){
        for(auto p:lo[y]){
            ll ot=-p.second*ipo[p.first]%m;
            if(ot<0)ot+=m;
            ans+=upper_bound(high.begin(),high.end(),ot)-lower_bound(high.begin(),high.end(),ot);
        }
    }
}
int main(){
    scanf("%d%lld",&n,&m);
    abc=m;
    ll M=m;
    for(ll i=2;i*i<=M;i++){
        if(M%i==0){
            abc/=i,abc*=i-1;
            while(M%i==0){
                M/=i;
            }
        }
    }
    if(M!=1)abc/=M,abc*=M-1;
    po[0]=1;
    for(int i=1;i<=n;i++)po[i]=po[i-1]*10%m;
    for(int i=0;i<=n;i++)ipo[i]=pow(po[i]);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(b);
        g[b].push_back(a);
        d[a].push_back(c);
        d[b].push_back(c);
    }
    memset(lev,0x3f,sizeof(lev));
    gc(0,0,0);
    for(int i=0;i<n;i++){
        veshy(i,lev[i]);
    }
    printf("%lld",ans);
}