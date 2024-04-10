#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=210;
const ll mod=1e9+7;

vector<pii>g[mn];
int d[mn][mn];
bool vis[mn],pari[mn];
int val[mn];
void dfs1(int x){
    vis[x]=1;
    for(pii p:g[x]){
        if(!vis[p.first]){
            pari[p.first]=(pari[x]^1);
            dfs1(p.first);
        }
        else{
            if(pari[p.first]!=(pari[x]^1)){
                printf("NO\n");
                exit(0);
            }
        }
    }
}
void dfs2(int x){
    vis[x]=1;
    for(pii p:g[x])if(p.second){
        if(!vis[p.first]){
            val[p.first]=val[x]+p.second;
            dfs2(p.first);
        }
        else{
            if(val[p.first]!=val[x]+p.second){
                printf("NO\n");
                exit(0);
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,-c});
        if(c)d[a][b]=1,d[b][a]=-1;
        else d[a][b]=d[b][a]=1;
    }
    dfs1(1);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)if(!vis[i]){
        dfs2(i);
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    for(int i=1;i<=n;i++)if(d[i][i]<0){
        printf("NO\n");
        return 0;
    }
    int a=1,b=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(d[i][j]>d[a][b])a=i,b=j;
    }
    printf("YES\n%d\n",d[a][b]);
    for(int i=1;i<=n;i++)printf("%d ",d[a][i]);
    printf("\n");
    return 0;
}