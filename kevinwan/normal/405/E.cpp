#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e5+10;
vector<int>g[mn];
bool vis[mn],ins[mn];
pii dfs(int x,int par){
    vis[x]=ins[x]=1;
    vector<int>v;
    vector<pii>ex;
    for(int y:g[x]){
        if(y==par)continue;
        if(ins[y]||!vis[y]) {
            pii p={-1,-1};
            if(!vis[y])p=dfs(y,x);
            if (p.first == -1)v.push_back(y);
            else ex.push_back(p);
        }
    }
    for(pii p:ex){
        printf("%d %d %d\n",x,p.first,p.second);
    }
    for(int i=0;i+1<v.size();i+=2)printf("%d %d %d\n",v[i],x,v[i+1]);
    ins[x]=0;
    if(v.size()&1)return {x,v.back()};
    else return {-1,-1};
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
    if(m&1)printf("No solution");
    else assert(dfs(1,1).first==-1);
}