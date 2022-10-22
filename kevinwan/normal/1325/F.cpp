#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll mod=1e9+7;
vector<int>g[mn];
int par[mn],dep[mn];
bool ins[mn],vis[mn];
bool ans[mn];
int tar=0;
void dfs(int x,int p){
    par[x]=p;
    vis[x]=ins[x]=1;
    if(ans[p])ans[x]=0;
    for(int y:g[x])if(y!=p){
        if(ins[y]){
            if((dep[x]-dep[y])>=tar-1){
                vector<int>pr;
                for(int i=x;i!=y;i=par[i])pr.push_back(i);
                pr.push_back(y);
                printf("2\n%d\n",pr.size());
                for(int z:pr)printf("%d ",z);
                exit(0);
            }
        }
    }
    for(int y:g[x])if(y!=p&&!vis[y])dep[y]=dep[x]+1,dfs(y,x);
    ans[x]=1;
    for(int y:g[x])if(ans[y])ans[x]=0;
    ins[x]=0;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while(tar*tar<n)tar++;
    dfs(1,0);
    int num=0;
    printf("1\n");
    for(int i=1;i<=n;i++)if(ans[i])if(num<tar)printf("%d ",i),num++;
}