#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=2e5+10;
int n,m,ans[maxn];set<int>S[maxn];vector<int>vec[maxn];

struct cmp{
  bool operator()(int x,int y)const{
    return S[x].size()==S[y].size()?x<y:S[x].size()<S[y].size();
  }
};

int main(){
  cin>>n>>m;set<int,cmp>Q;
  rep(i,1,n){
    int k,x;scanf("%d",&k);while(k--){
      scanf("%d",&x),S[i].insert(x);
      vec[abs(x)].push_back(x<0?-i:i);
    }
    Q.insert(i);
  }
  while(!Q.empty()){
    int u=*Q.begin();Q.erase(u);
    if(S[u].empty())return puts("NO"),0;
    int x=*S[u].begin();S[u].clear();
    if(x>0)ans[x]=1;
    for(int v:vec[abs(x)]){
      if((v<0)==(x<0)){
        Q.erase(abs(v));
      }else if(Q.erase(abs(v))){
        S[abs(v)].erase(-x),Q.insert(abs(v));
      }
    }
  }
  puts("YES");
  rep(i,1,m)putchar(ans[i]|48);
  return 0;
}