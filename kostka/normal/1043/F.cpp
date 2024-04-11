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

const int MAXA = 300007;
int dzi[MAXA];
ll dp[MAXA];
const ll MOD = 1234567891;

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vi A(n);
  for(int i=0; i<n; i++) cin >> A[i];
  int g = 0;
  for(int i=0; i<n; i++) g = __gcd(g, A[i]);
  if(g != 1) {
    cout << -1 << "\n";
    return 0;
  }
  for(auto a : A) dp[a] = dzi[a] = 1;
  for(int i=1; i<MAXA; i++) {
    for(int j=2*i; j<MAXA; j+=i) dzi[i] += dzi[j];
  }
  for(int _=1; _<=10; _++) {
    if(dp[1]) {
      cout << _ << "\n";
      return 0;
    }
    for(int i=1; i<MAXA; i++) {
      if(!dzi[i]) continue;
      for(int j=2*i; j<MAXA; j+=i) {
        dp[i] += dp[j];
        if(dp[i] >= MOD) dp[i] -= MOD;
      }
      dp[i] *= dzi[i];
      dp[i] %= MOD;
    }
    for(int i=MAXA-1; i>=1; i--) {
      for(int j=2*i; j<MAXA; j+=i) {
        dp[i] -= dp[j];
        if(dp[i] < 0) dp[i] += MOD;
      }
    }
  }
  assert(false);
  return 0;
}