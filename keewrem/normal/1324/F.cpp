#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
int const MAXN=200100;
int N;
bool white[MAXN];
vector<int> tree[MAXN];
int w[MAXN], b[MAXN];
int ans[MAXN];
void dfs(int node, int parent){
 for(auto x:tree[node]){
  if(x!=parent){
   dfs(x,node);
   if(w[x]>b[x]){
    w[node]+=w[x];
    b[node]+=b[x];
   }
  }
 }
 if(white[node])
  w[node]++;
 else b[node]++;
 ans[node]=w[node]-b[node];
}
bool ok(int i){
 return w[i]>b[i];
}
void res(int node, int parent){
 for(auto x:tree[node])
  if(x!=parent){
   if(ok(x))
    ans[x]=max(ans[x],ans[node]);
   else ans[x]=max(ans[x],ans[x]+ans[node]);
   res(x,node);
  }
}
int main(){
 cin.tie(0),cin.sync_with_stdio(0),cout.tie(0),cout.sync_with_stdio(0);
 cin>>N;
 for(int i=1;i<=N;i++){
  int tmp;
  cin>>tmp;
  if(tmp==1)
   white[i]=true;
 }
 for(int i=1;i<N;i++){
  int aa, bb;
  cin>>aa>>bb;
  tree[aa].push_back(bb);
  tree[bb].push_back(aa);
 }
 dfs(1,0);
 res(1,0);
 for(int i=1;i<=N;i++)
  cout<<ans[i]<<" ";
}