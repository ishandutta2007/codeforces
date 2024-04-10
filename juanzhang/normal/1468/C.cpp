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
typedef vector<int> vi;
typedef pair<int,int> pii;
int q,val[505050];
bool vis[505050];

set<pii>S;

void solve(){
  cin>>q;
  int tmp=1,ct=0;
  rep(i,1,q){
    int op=read();
    if(op==1){
      int x=read();
      val[++ct]=x;
      S.insert({-x,ct});
    }else if(op==2){
      while(!val[tmp]||vis[tmp])tmp++;
      printf("%d ",tmp);
      vis[tmp]=1,tmp++;
    }else{
      int j=-1;
      while(1){
        j=S.begin()->second;
        if(!vis[j])break;
        S.erase(S.begin());
      }
      printf("%d ",j);
      vis[j]=1;
    }
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}