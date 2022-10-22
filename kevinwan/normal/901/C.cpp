#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=3e5+10;
vector<int>g[mn];
vector<int>rl[mn];
bool vis[mn],ins[mn];
vector<pii>v;
int dfs(int x,int p){
    vis[x]=ins[x]=1;
    int ret=0;
    for(int y:g[x])if(y!=p){
        if(ins[y]){
            v.push_back({x,x});
            ret=y;
        }else if(!vis[y]){
            int r=dfs(y,x);
            if(r){
                ret=r;
                v.back().first=min(v.back().first,x),v.back().second=max(v.back().second,x);
                if(ret==x){
                    rl[v.back().first].push_back(v.back().second);
                    v.pop_back();
                    ret=0;
                }
            }
        }
    }
    ins[x]=0;
    return ret;
}
multiset<int>s;
int rlim[mn];
vector<int>ded[mn];
int l[mn],r[mn],o[mn];
ll ans[mn];
struct bit{
    ll bit[mn];
    void up(int a,ll b){for(;a<mn;a+=a&-a)bit[a]+=b;}
    ll qu(int a){ll b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
    s.insert(n+1);
    for(int i=1,j=0;i<=n;i++){
        while(j<*s.begin()){
            ++j;
            for(int k:rl[j])s.insert(k);
        }
        rlim[i]=j-1;
        ded[j-1].push_back(i);
        for(int k:rl[i])s.erase(s.find(k));
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)scanf("%d%d",l+i,r+i);
    iota(o,o+mn,0);
    sort(o,o+q,[](int a,int b){return r[a]>r[b];});
    bit in=bit(),ot=bit();
    int cr=n+1;
    for(int i=1;i<=n;i++)in.up(i,rlim[i]);
    for(int i=0;i<q;i++){
        int j=o[i];
        while(cr>r[j]){
            cr--;
            for(int x:ded[cr])in.up(x,-rlim[x]),ot.up(x,1);
        }
        ans[j]=1LL*r[j]*(ot.qu(r[j])-ot.qu(l[j]-1))+(in.qu(r[j])-in.qu(l[j]-1))-1LL*(r[j]+l[j]-2)*(r[j]-l[j]+1)/2;
    }
    for(int i=0;i<q;i++)printf("%lld\n",ans[i]);
}