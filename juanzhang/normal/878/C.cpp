#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

int n,k;

struct node{
  int sz,mn[10],mx[10];
  bool operator<(const node&o)const{
    rep(i,0,k-1)if(mx[i]>o.mn[i])return 0;
    return 1;
  }
};
node merge(node A,node B){
  node res;res.sz=A.sz+B.sz;
  rep(i,0,k-1)res.mn[i]=min(A.mn[i],B.mn[i]),res.mx[i]=max(A.mx[i],B.mx[i]);
  return res;
}

multiset<node>S;

int main(){
  cin>>n>>k;
  rep(_,1,n){
    node cur;cur.sz=1;
    rep(i,0,k-1)cur.mn[i]=cur.mx[i]=read();
    while(1){
      auto it1=S.lower_bound(cur),it2=S.upper_bound(cur);
      if(it1!=it2){
        cur=merge(*it1,cur),S.erase(it1);
      }else break;
    }
    S.insert(cur);
    printf("%d\n",S.rbegin()->sz);
  }
  return 0;
}