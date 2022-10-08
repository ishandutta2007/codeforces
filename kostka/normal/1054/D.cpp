//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  unordered_map <int, int> M;
  int st = 0;
  M[0] = 1;
  for(int i=0; i<n; i++) {
    int a;
    cin >> a;
    st ^= a;
    if(M[((1<<k)-1) ^ st] < M[st]) st ^= ((1<<k)-1);
    M[st]++;
  }
  ll ret = 1LL * n * (n+1) / 2;
  for(auto ele : M) ret -= 1LL * (ele.y) * (ele.y - 1) / 2;
  cout << ret << "\n";
  return 0;
}