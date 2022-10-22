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
int n,m;db k;
map<string,int>mp;

void solve() {
  cin>>n>>m>>k;
  string str;
  rep(i,1,n){
    int x;
    cin>>str>>x;
    int t=k*x+1e-10;
    if(t>=100)mp[str]=t;
  }
  rep(i,1,m){
    cin>>str;
    if(mp.find(str)==mp.end())mp.insert({str,0});
  }
  printf("%d\n",(int)mp.size());
  for(auto p:mp)cout<<p.first<<' '<<p.second<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}