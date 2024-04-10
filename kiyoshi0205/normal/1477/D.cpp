#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}
bool vis[500001];
vector<int> tree[500001];
int p[500001],q[500001];
//Matching of the tree
void dfs(int now,int par,vector<vector<int>>& color){
  for(auto& next:tree[now]){
    if(next!=par)dfs(next,now,color);
  }
  if(par==-1)par=tree[now][0];
  if(color[now].empty())color[par].emplace_back(now);
  tree[now].clear();
}
void solve(){
  int N,M,cnt=1;
  cin>>N>>M;
  fill(p,p+N,-1);fill(q,q+N,-1);
  vector<vector<int>> g(N);
  while(M--){
    int u,v;
    cin>>u>>v;
    --u;--v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  //make spanning forest of the complement graph
  for(int u=0;u<N;++u){
    if(vis[u]){
      vis[u]=false;
      continue;
    }
    int K=g[u].size()+1;
    if(K==N){
      p[u]=q[u]=cnt++;
      continue;
    }
    vector<bool> mex(K,true);
    if(u<K)mex[u]=false;
    for(auto& v:g[u]){
      if(v<K)mex[v]=false;
    }
    int v=0;
    while(!mex[v])++v;
    if(u<v)vis[v]=true;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }

  vector<vector<int>> child(N);
  for(int i=0;i<N;++i){
    if(!tree[i].empty())dfs(i,-1,child);
  }
  for(int i=0;i<N;++i){
    int K=child[i].size();
    if(K==0)continue;
    p[i]=cnt;
    for(int j=0;j<K;++j){
      p[child[i][j]]=cnt+j+1;
      q[child[i][j]]=cnt+j;
    }
    q[i]=cnt+K;
    cnt+=K+1;
  }

  for(int i=0;i<N;++i)cout<<p[i]<<" \n"[i==N-1];
  for(int i=0;i<N;++i)cout<<q[i]<<" \n"[i==N-1];
}

int main(){
  startupcpp();
  int T;cin>>T;while(T--){
    solve();
  }
}