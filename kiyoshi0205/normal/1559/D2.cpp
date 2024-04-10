#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

struct unionfind{
  private:
  int maxN;
  vector<int> par,treesize;
  public:unionfind(int N) :maxN(N),par(N),treesize(N,1){
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  int root(int x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool unite(pair<int,int> v){
    return unite(v.first,v.second);
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  bool parcheck(pair<int,int> v){
    return parcheck(v.first,v.second);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    treesize.assign(maxN,1);
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  vector<vector<int>> groups(){
    vector<vector<int>> res(maxN);
    for(int i=0;i<maxN;++i)res[root(i)].emplace_back(i);
    // return res;
    vector<vector<int>> res2;
    for(vector<int> x:res){
      if(x.size())res2.emplace_back(x);
    }
    return res2;
  }
};

int N,M[2],ch[4];
set<int> vlis[2];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>N>>M[0]>>M[1];
  vector<unionfind> dsu(2,unionfind(N));
  for(int t=0;t<2;++t){
    while(M[t]--){
      int a,b;
      cin>>a>>b;
      dsu[t].unite(--a,--b);
    }
    for(int i=0;i<N;++i)vlis[t].emplace(dsu[t].root(i));
  }
  list<pair<int,int>> ans;
  while(vlis[0].size()>1&&vlis[1].size()>1){
    for(int t=0;t<2;++t){
      ch[t<<1]=*vlis[t].begin();
      ch[t<<1|1]=*next(vlis[t].begin());
    }
    for(auto x:ch)for(auto y:ch){
      if(dsu[0].parcheck(x,y)||dsu[1].parcheck(x,y))continue;
      ans.emplace_back(x+1,y+1);
      for(int t=0;t<2;++t){
        int A=dsu[t].root(x)^dsu[t].root(y);
        dsu[t].unite(x,y);
        vlis[t].erase(A^dsu[t].root(x));
      }
    }
  }
  cout<<ans.size()<<'\n';
  for(auto [u,v]:ans)cout<<u<<' '<<v<<'\n';
}