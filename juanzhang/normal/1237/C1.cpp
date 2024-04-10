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
typedef vector<int>vi;
typedef pair<int,int>pii;
int n;bool vis[500010];
struct node{
  int x,y,z,id;
}A[500010];
struct cmp1{
  bool operator()(node P,node Q)const{
    return P.x<Q.x||(P.x==Q.x&&(P.y<Q.y||(P.y==Q.y&&P.z<Q.z)));
  }
};
struct cmp2{
  bool operator()(node P,node Q)const{
    return P.y<Q.y||(P.y==Q.y&&(P.x<Q.x||(P.x==Q.x&&P.z<Q.z)));
  }
};
struct cmp3{
  bool operator()(node P,node Q)const{
    return P.z<Q.z||(P.z==Q.z&&(P.y<Q.y||(P.y==Q.y&&P.x<Q.x)));
  }
};
set<node,cmp1>S1;
set<node,cmp2>S2;
set<node,cmp3>S3;

void solve(){
  cin>>n;
  rep(i,1,n){
    int x=read(),y=read(),z=read();
    node p={x,y,z,i};
    A[i]=p;
  }
  vector<pii>ans;
  sort(A+1,A+n+1,cmp1());
  rep(i,1,n){
    if(i>1&&A[i].x==A[i-1].x&&A[i].y==A[i-1].y){
      ans.push_back({A[i].id,A[i-1].id}),vis[A[i].id]=vis[A[i-1].id]=1;i++;
    }
  }
  int tpn=0;
  rep(i,1,n)if(!vis[A[i].id])A[++tpn]=A[i];
  n=tpn;
  rep(i,1,n){
    if(i>1&&A[i].x==A[i-1].x){
      ans.push_back({A[i].id,A[i-1].id}),vis[A[i].id]=vis[A[i-1].id]=1;i++;
    }
  }
  tpn=0;
  rep(i,1,n)if(!vis[A[i].id])A[++tpn]=A[i];
  n=tpn;
  rep(i,1,n){
    i++;
    ans.push_back({A[i].id,A[i-1].id});
  }
  for(pii p:ans)printf("%d %d\n",p.first,p.second);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}