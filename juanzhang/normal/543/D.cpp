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
const int maxn=2e5+10,P=1e9+7;
int n;
vi E[maxn];
int dp1[maxn],dp3[maxn];

void dfs1(int u,int f){
  dp1[u]=1;
  for(int v:E[u])if(v!=f){
    dfs1(v,u);
    dp1[u]=1ll*dp1[u]*(dp1[v]+1)%P;
  }
}
void dfs2(int u,int f){
  static int pre[maxn],suf[maxn];
//  fill(pre,pre+100,1),fill(suf,suf+100,1);
//  for(int v:E[u])if(v!=f){
//    for(int w:E[u])if(w!=f){
//      if(v==w)break;
//      pre[v]=1ll*pre[v]*(dp1[w]+1)%P;
//    }
//  }
//  for(int v:E[u])if(v!=f){
//    bool flg=0;
//    for(int w:E[u])if(w!=f){
//      if(flg)suf[v]=1ll*suf[v]*(dp1[w]+1)%P;
//      if(v==w)flg=1;
//    }
//  }
  int cur=1;pre[0]=1;
  vector<int>vec;
  vec.push_back(0);
  for(int v:E[u])if(v!=f)vec.push_back(dp1[v]+1);
  suf[vec.size()]=1;
  rep(i,1,vec.size()-1){
    int x=vec[i];
    pre[i]=1ll*pre[i-1]*x%P;
  }
  per(i,vec.size()-1,1){
    int x=vec[i];
    suf[i]=1ll*suf[i+1]*x%P;
  }
  for(int v:E[u])if(v!=f){
    dp3[v]=(1ll*pre[cur-1]*suf[cur+1]%P*dp3[u]+1)%P,cur++;
  }
  for(int v:E[u])if(v!=f)dfs2(v,u);
}

void solve() {
  cin>>n;
  rep(i,2,n){
    int fa=read();E[i].push_back(fa),E[fa].push_back(i);
  }
  dfs1(1,0),dp3[1]=1,dfs2(1,0);
  rep(i,1,n)printf("%d ",(int)(1ll*dp1[i]*dp3[i]%P));
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}