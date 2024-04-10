#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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
int n,bsz,A[maxn];char str[maxn];

int ct[maxn*450];bitset<maxn*450>vis;

void solve() {
  scanf("%s",str+1),n=strlen(str+1);rep(i,1,n)A[i]=str[i]-'0';
  bsz=max(1.0,sqrt(n)/2);ll res=0;
  rep(T,1,bsz){
    ll su=maxn*225;
    vis.reset();
    rep(i,1,n){
      vis[su]?++ct[su]:(vis[su]=1,ct[su]=1);
      su+=A[i]?-T+1:1;
      if(vis[su])res+=ct[su];
    }
  }
  static int st[maxn];int top=0;
  rep(i,1,n){
    if(A[i])st[++top]=i;
    int cur=0;
    per(j,top,1){
      int l=st[j-1]+1,r=st[j];cur++;
      if(cur>(db)n/bsz)break;
      chkmin(r,i-cur*bsz);if(l>r)continue;
      l=i-l+1,r=i-r+1;
      res+=l/cur-(r-1)/cur;
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