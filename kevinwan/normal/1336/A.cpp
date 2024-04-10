#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=1e9+7;
vector<int>g[mn];
int par[mn],dep[mn],siz[mn],ch[mn];
struct comp{
    bool operator()(int a,int b){
        return dep[a]-siz[a]>dep[b]-siz[b];
    }
};
multiset<int,comp>s;
void dfs(int x,int p){
    siz[x]=1;
    for(int y:g[x])if(y!=p){
        dep[y]=dep[x]+1;
        par[y]=x;
        dfs(y,x);
        siz[x]+=siz[y];
        ch[x]++;
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    ll ans=0;
    for(int i=1;i<=n;i++)if(ch[i]==0)s.insert(i);
    while(k--){
        int x=*s.begin();
        s.erase(s.begin());
        ans+=dep[x]-siz[x]+1;
        ch[par[x]]--;
        if(ch[par[x]]==0)s.insert(par[x]);
    }
    printf("%lld",ans);
}