#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const db eps=1e-9;
const int maxn=2e5+10;
int n,q;

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

struct node{
  db val,pro;
  node():val(0.0),pro(1.0){}
  node(db _v,db _p):val(min(1e9,_v)),pro(_p){}
}T[maxn<<2];
node merge(node A,node B){
  return{A.val+A.pro*B.val,A.pro*B.pro};
}
void ins(int k,int l,int r,int x,db p){
  if(l==r)return T[k].val=T[k].pro=p,void();
  x<=mid?ins(lson,x,p):ins(rson,x,p),T[k]=merge(T[k<<1],T[k<<1|1]);
}
node query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return T[k];
  node res;
  if(ql<=mid)res=query(lson,ql,qr);
  if(qr>mid)res=merge(res,query(rson,ql,qr));
  return res;
}

#undef mid
#undef lson
#undef rson

void solve(){
  cin>>n>>q;
  rep(i,1,n){
    int x=read(),y=read();ins(1,1,n,i,(db)(y-x)/x);
  }
  while(q--){
    int op=read();
    if(op==1){
      int id=read(),x=read(),y=read();ins(1,1,n,id,(db)(y-x)/x);
    }else{
      int l=read(),r=read();node res=query(1,1,n,l,r);db as=1/(res.val+1);
      printf("%.9lf\n",as);
    }
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}