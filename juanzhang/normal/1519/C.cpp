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
const int maxn=2e5+10;
int n;vi vec[maxn];vector<ll>sum[maxn];

int bl[maxn];ll ans[maxn],ano[maxn];
void solve(){
  cin>>n;ll su=0;
  rep(i,1,n)vec[i].clear(),ans[i]=0,ano[i]=0,sum[i].clear();
  rep(i,1,n)bl[i]=read();
  rep(i,1,n){
    int x=read();su+=x;
    vec[bl[i]].push_back(x);
  }
  rep(i,1,n)sort(vec[i].begin(),vec[i].end());
  rep(i,1,n){
    ll tp=0;
    for(int x:vec[i])sum[i].push_back(tp+=x);
    rep(j,1,vec[i].size()){
      ans[j]+=vec[i].size()%j==0?0:sum[i][vec[i].size()%j-1];
    }
    ano[vec[i].size()+1]+=tp;
  }
  rep(i,1,n)printf("%lld%c",su-(ans[i]+(ano[i]+=ano[i-1])),"\n "[i<n]);
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}