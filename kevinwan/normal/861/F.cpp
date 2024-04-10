#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e5+10;
bool vis[mn],ins[mn],don[mn];
vector<int>g[mn];
vector<int>a,b,c;
void dfs(int x,int p){
    vector<int>v;
    vis[x]=ins[x]=1;
    for(int y:g[x])if(y!=p){
        if(!vis[y]){
            dfs(y,x);
            if(!don[y])v.push_back(y);
        }
        else if(ins[y]){
            v.push_back(y);
        }
    }
    for(int i=0;i+1<v.size();i+=2)a.push_back(v[i]),b.push_back(x),c.push_back(v[i+1]);
    if(v.size()&1){
        if(p)a.push_back(v.back()),b.push_back(x),c.push_back(p),don[x]=1;
    }
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
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
    printf("%d\n",a.size());
    for(int i=0;i<a.size();i++)printf("%d %d %d\n",a[i],b[i],c[i]);
}