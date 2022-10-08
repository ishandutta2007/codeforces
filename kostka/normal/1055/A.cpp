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

void res(string x) {
  cout << x << "\n";
  exit(0);
}

const int MAXN = 1007;
vi G[MAXN];
bool odw[MAXN];

void dfs(int v) {
  odw[v] = true;
  for(auto w : G[v]) if(!odw[w]) dfs(w);
}

int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  k--;
  vi A(n), B(n);
  for(int i=0; i<n; i++) cin >> A[i];
  for(int i=0; i<n; i++) cin >> B[i];
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(A[i] and A[j]) G[i].push_back(j);
      if(B[i] and B[j]) G[j].push_back(i);
    }
  }
  dfs(0);
  if(odw[k]) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}