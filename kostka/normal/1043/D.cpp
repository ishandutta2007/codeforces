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
  int n, m;
  cin >> n >> m;
  vector <vi> X(m);
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      int a;
      cin >> a;
      X[i].push_back(a-1);
    }
  }
  map <int, int> M;
  for(int i=0; i<n; i++) M[X[0][i]] = i;
  vector <int> res(n, n);
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      int k = j;
      while(j+1 < n and M[X[i][j]] + 1 == M[X[i][j+1]]) j++;
      // for(int p=k; p<=j; p++) cerr << j-p+1 << " ";
      for(int p=k; p<=j; p++) res[M[X[i][p]]] = min(res[M[X[i][p]]], j-p+1);
    }
    // cerr << "\n";
  }
  ll ret = 0;
  for(auto r : res) ret += r;
  cout << ret << "\n";
  return 0;
}