#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

constexpr ll fib[26]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418};
// change fib[i] to i
map<ll,ll> fibid;
// graph
vector<vector<ll>> g;
// size of subtree , parent
vector<ll> subsz,par;
// root of tree which size fib[i] 
set<ll> rootlis[27];
// calc subtree, parent and init rootlist
ll dfs(ll now,ll p=-1){
  par[now]=p;
  for(auto x:g[now]){
    if(x==p)continue;
    subsz[now]+=dfs(x,now);
  }
  if(fibid.count(subsz[now]))rootlis[fibid[subsz[now]]].emplace(now);
  return subsz[now];
}
int main(){
  for(ll i=0;i<26;++i)fibid[fib[i]]=i;
  ll N;
  cin>>N;
  if(!fibid.count(N)){
    puts("NO");
    return 0;
  }
  g.resize(N);
  subsz.resize(N,1);
  par.resize(N);
  for(ll i=0;i<N-1;++i){
    ll a,b;
    cin>>a>>b;
    --a;--b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(0);
  //check
  for(ll i=24;i>=0;--i){
    vector<int> aftercheck;
    for(auto x:rootlis[i]){
      assert(subsz[x]==fib[i]);
      ll now=x;
      while(par[now]!=-1){
        now=par[now];
        if(fibid.count(subsz[now]))rootlis[fibid[subsz[now]]].erase(now);
        subsz[now]-=subsz[x];
        assert(subsz[now]>0);
        if(subsz[now]==fib[i]){
          aftercheck.emplace_back(now);
        }else if(fibid.count(subsz[now]))rootlis[fibid[subsz[now]]].emplace(now);
      }
      //split tree (root x,size fib[i]),(root now,size subsz[now]) from (root now,size subsz[now]+subsz[x]);
      par[x]=-1;
    }
    for(auto x:aftercheck){
      rootlis[i].emplace(x);
      ll now=x;
      while(par[now]!=-1){
        now=par[now];
        if(fibid.count(subsz[now]))rootlis[fibid[subsz[now]]].erase(now);
        subsz[now]-=subsz[x];
        assert(subsz[now]>0&&subsz[now]!=fib[i]);
        if(fibid.count(subsz[now]))rootlis[fibid[subsz[now]]].emplace(now);
      }
      par[x]=-1;
    }
    if(rootlis[i+2].size()){
      puts("NO");
      return 0;
    }
  }
  assert(rootlis[0].size()==N&&*max_element(par.begin(),par.end())==-1);
  puts("YES");
}