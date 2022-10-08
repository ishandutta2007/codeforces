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

const int MAXN = 1507;
int dp[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  int n, t, m, k;
  cin >> n >> t >> m >> k;
  vi A(n);
  set <int> SA;
  for(int i=0; i<n; i++) {
    cin >> A[i];
    SA.insert(A[i]);
  }
  vector <pii> S;
  for(int i=0; i<t; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    S.emplace_back(a, b);
  }
  vector <int> SS;
  for(auto s : SA) SS.push_back(s);
  vector <int> R(n);
  for(int i=0; i<n; i++) R[i] = i+1;
  for(auto s : S) {
    int a, b;
    tie(a, b) = s;
    for(int i=a; i<=b; i++) R[i] = min(a, R[i]);
  }
  auto check = [&](int med) {
    if(med == SZ(SS)) return true;
    vi P(n);
    for(int i=0; i<n; i++) if(A[i] <= SS[med]) P[i] = 1;
    partial_sum(P.begin(), P.end(), P.begin());
    for(int i=0; i<=n+1; i++) {
      for(int j=0; j<=m+1; j++) dp[i][j] = -1e9;
    }
    dp[0][0] = 0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<=m; j++) {
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
      }
      if(R[i] != i+1) {
        int pre = P[i] - (R[i] == 0 ? 0 : P[R[i]-1]);
        for(int j=0; j<m; j++) dp[i+1][j+1] = max(dp[i+1][j+1], dp[R[i]][j] + pre);
      }
    }
    return dp[n][m] < k;
  };
  int a = -1, b = SZ(SS);
  while(b - a > 1) {
    int med = (a+b)>>1;
    if(check(med)) a = med;
    else b = med;
  }
  if(b == SZ(SS)) cout << -1 << "\n";
  else cout << SS[b] << "\n";
  return 0;
}