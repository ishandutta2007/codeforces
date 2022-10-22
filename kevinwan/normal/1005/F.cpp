#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=1e9+rng()%((ll)1e9);
int n,m,k;
pii ed[mn];
vector<pii>g[mn];
vector<int>ans;
bool pr[mn];
string hailvesh;
int mo;
bool vis[mn];
int dis[mn];
queue<int>q;
vector<int>gg[mn];
int num;
void kill(){
    printf("%d\n%s",num,hailvesh.c_str());
    exit(0);
}
void solve(int lev,int i){
    if(i==gg[lev].size())lev++,i=0;
    if(ans.size()==n-1){
        for(int i=0;i<m;i++)pr[i]=0;
        for(int x:ans)pr[x]=1;
        for(int i=0;i<m;i++)hailvesh.push_back('0'+pr[i]);
        hailvesh.push_back('\n');
        num++;
        if(!(--k))kill();
    }
    else{
        for(pii p:g[gg[lev][i]])if(dis[p.first]==lev-1){
            ans.push_back(p.second);
            solve(lev,i+1);
            ans.pop_back();
        }
    }
}
void bfs(){
    q.push(1);
    vis[1]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        for(pii y:g[x])if(!vis[y.first])vis[y.first]=1,dis[y.first]=dis[x]+1,q.push(y.first),ans.push_back(y.second);
    }
    mo=0;
    for(int i=1;i<=n;i++)mo=max(mo,dis[i]);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        ed[i]={a,b};
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    bfs();
    while(ans.size())ans.pop_back();
    for(int i=1;i<=n;i++){
        gg[dis[i]].push_back(i);
    }
    solve(1,0);
    kill();
}