#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
int n,A[3010];

vector<int>vec[3010];

void solve() {
  cin>>n;
  rep(i,1,n)vec[i].clear();
  rep(i,1,n)A[i]=read(),vec[A[i]].push_back(i);
  ll res=0;
  rep(i,1,n)rep(j,i+1,n){
    int l = lower_bound(vec[A[j]].begin(), vec[A[j]].end(), i) - vec[A[j]].begin();
    int r = upper_bound(vec[A[i]].begin(), vec[A[i]].end(), j) - vec[A[i]].begin();
    r = (((int) vec[A[i]].size()) - r);
    res += l * r;
  }
  cout<<res<<endl;
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}