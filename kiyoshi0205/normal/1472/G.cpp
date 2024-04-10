#include<bits/stdc++.h>
using namespace std;
void solve(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> g(N);
  while(M--){
    int a,b;
    cin>>a>>b;
    g[--a].emplace_back(--b);
  }
  vector<int> checklist,dist(N,-1);
  queue<int> que;
  que.push(0);dist[0]=0;
  while(!que.empty()){
    auto now=que.front();que.pop();
    checklist.emplace_back(now);
    for(auto next:g[now]){
      if(dist[next]==-1){
        dist[next]=dist[now]+1;
        que.push(next);
      }
    }
  }
  vector<vector<int>> dfsg(N);
  vector<int> ans(N);
  for(int i=0;i<N;++i){
    ans[i]=dist[i];
    for(auto next:g[i]){
      if(dist[i]<dist[next])dfsg[i].emplace_back(next);
      else ans[i]=min(ans[i],dist[next]);
    }
  }
  reverse(checklist.begin(),checklist.end());
  for(auto now:checklist){
    for(auto next:dfsg[now]){
      ans[now]=min(ans[now],ans[next]);
    }
  }
  for(int i=0;i<N;++i){
    cout<<ans[i]<<" \n"[i==N-1];
  }
}
int main(){
  int T;
  cin>>T;
  while(T--)solve();
}