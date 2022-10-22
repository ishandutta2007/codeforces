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

#define int long long

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int n;
struct node{
  int t,x;
}A[maxn];

void solve(){
  cin>>n;
  rep(i,1,n){
    A[i].t=read(),A[i].x=read();
  }
  A[++n]={(int)4e9,(int)4e9};
  int res=0;
  int ti=0,cur=0,mt=0;
  rep(i,1,n){
    int l=cur,r;
    if(abs(cur-mt)<=A[i].t-ti){
      cur=mt;
      r=cur,mt=A[i].x;
    }else{
      cur=cur<mt?cur+A[i].t-ti:cur-A[i].t+ti;
      r=cur;
    }
    if(l>r)swap(l,r);
    if(i>1&&A[i-1].x>=l&&A[i-1].x<=r)res++;
    ti=A[i].t;
  }
  cout<<res<<endl;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}