#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=2e5+10;
int n,A[maxn];ll su[maxn];
int mp[maxn],par[maxn];pair<ll,int>dat[maxn];

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

void solve() {
  cin>>n;
  rep(i,1,n)su[i]=su[i-1]+(A[i]=read()),dat[i]={su[i-1]-A[i],i},par[i]=i;
  par[n+1]=n+1;
  sort(dat+1,dat+n+1);
  rep(i,1,n)mp[dat[i].second]=i;
  ll res=0;
  rep(i,1,n){
    int ps=mp[i];
    par[ps]=find(ps+1);
    ll lv=su[i]+A[i];
    for(int j=find(1);j<=n;j=find(j+1)){
      if(dat[j].first>lv)break;
      int r=dat[j].second;
      if(i+1<=r-1)res+=(A[i]^A[r])==su[r-1]-su[i];
    }
  }
  cout<<res<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}