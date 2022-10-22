#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,A[maxn],tid[maxn];

bool pd(int mid){
  ll su=0;
  rep(i,1,mid)su+=A[tid[i]];
  rep(_,mid+1,n){
    if(A[tid[_]]>su)return 0;
    su+=A[tid[_]];
  }
  return 1;
}

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read(),tid[i]=i;
  sort(tid+1,tid+n+1,[](int x,int y){
    return A[x]<A[y];
  });
  int l=1,r=n;
  while(l<r){
    int mid=(l+r)/2;
    pd(mid)?r=mid:l=mid+1;
  }
  cout<<n-l+1<<endl;
  vi vec;
  rep(i,l,n)vec.push_back(tid[i]);
  sort(vec.begin(),vec.end());
  for(int x:vec)printf("%d ",x);puts("");
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}