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
int n,A[maxn],lst[maxn];

void solve() {
  cin>>n;
  rep(i,1,n){
    A[i]=read(),lst[i]=0;
  }
  int ans=0;
  lst[0]=1;
  rep(i,2,n){
    if(!lst[ans])ans++;
    int j=i;
    while(j<n&&A[j+1]>A[j])j++;
    lst[ans]--;
    lst[ans+1]+=j-i+1;
    i=j;
  }
  cout<<ans+1<<endl;
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}