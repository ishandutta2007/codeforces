#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;bool flg=0;
  while(c<48)flg|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return flg?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n;

vi divide(vi &buk,int lev){
  if(buk.empty())return vi();
  sort(buk.begin(),buk.end()),buk.erase(unique(buk.begin(),buk.end()),buk.end());
  rep(i,0,buk.size()-1)if(!buk[i]){
    buk.erase(buk.begin()+i);break;
  }
  if(lev==-1)return buk;
  vi vA,vB;bool flg=1;
  for(int x:buk){
    if(x&1)vA.push_back((x-1)/2),vB.push_back((x+1)/2),flg=0;
    else vA.push_back(x/2),vB.push_back(x/2);
  }
  buk.clear();
  vi rA=divide(vA,lev-1);
  vi rB=divide(vB,lev-1);
  for(int&x:rA)x<<=1;
  for(int&x:rB)x<<=1;
  if(!flg)rA.push_back(1),rB.push_back(-1);
  return rA.size()<rB.size()?rA:rB;
}

void solve() {
  cin>>n;vi vec;
  rep(i,1,n)vec.push_back(read());
  vi ans=divide(vec,17);
  printf("%d\n",(int)ans.size());for(int x:ans)printf("%d ",x);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}