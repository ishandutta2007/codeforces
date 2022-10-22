#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
vector<int>g[mn];
int dep[mn];
void dfs(int x,int p){
    for(int y:g[x])if(y!=p){
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n,a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dep[a]=0;
        dfs(a,0);
        int dab=dep[b];
        if(da>=dab){
            printf("Alice\n");
            continue;
        }
        int mo=0;
        for(int i=1;i<=n;i++)if(dep[i]>dep[mo])mo=i;
        dep[mo]=0;
        dfs(mo,0);
        int d=0;
        for(int i=1;i<=n;i++)d=max(d,dep[i]);
        db=min(db,d);
        if(db>da*2)printf("Bob\n");
        else printf("Alice\n");
    }

}