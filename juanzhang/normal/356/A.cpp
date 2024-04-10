#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=3e5+10;
int n,m,ans[maxn];

set<int>S;

int main(){
  cin>>n>>m;
  rep(i,1,n)S.insert(i);
  while(m--){
    int l,r,x;scanf("%d%d%d",&l,&r,&x);
    auto it=S.lower_bound(l);
    while(it!=S.end()&&*it<=r){
      if(*it!=x){
        ans[*it]=x;
        auto tp=it;
        ++it;
        S.erase(tp);
      }else ++it;
    }
  }
  rep(i,1,n)printf("%d ",ans[i]);
  return 0;
}