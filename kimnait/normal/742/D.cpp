#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
using namespace std;
#define MS0(I) memset(I, 0, sizeof(I));
#define MS1(I) memset(I, -1, sizeof(I));
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, s, n) for(int i = (s); i < (n); ++i)
#define per1(i, a, b) for(int i = a; i >= b; --i)
#define DRI(A) int A; scanf("%d", &A);
#define DRII(A, B) int A, B; scanf("%d %d", &A, &B);
#define DRIII(A, B, C) int A, B, C; scanf("%d %d %d", &A, &B, &C);
#define DRL(A) long long A; scanf("%lld", &A);
#define DRLL(A, B) long long A, B; scanf("%lld %lld", &A, &B);
#define DRLLL(A, B, C) long long A, B, C; scanf("%lld %lld %lld", &A, &B, &C);
#define SZ(X) ((int)X.size() )
#define MP make_pair 
#define pb push_back
#define F first
#define S second
#define ALL(I) (I).begin(), (I).end()
typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII; 
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;
const double eps = 1e-9;
const double PI = acos(-1);
const LL INFF = 1e18;
const int INF = 1e9+1;
const int mod = 1e9+7;
const int MAX = 1e4+7;
int siz[MAX], gp[MAX];
vector<int>mem[MAX];
int fd(int v){
  return gp[v] == v ? v : gp[v] = fd(gp[v]);
}
void uni(int u, int v){
  u = fd(u); v = fd(v);
  if(u == v) return ;
  if(siz[u] > siz[v]) swap(u, v);
  for(int x : mem[u]) mem[v].pb(x);
  siz[v] += siz[u];
  gp[u] = v;
  return ;
}
int w[MAX];
LL b[MAX];
vector<int>al;
LL dp[MAX];
LL dp2[MAX];
int main(void){
  DRIII(n, m, k);
  rep1(i, 1, n+1){
    siz[i] = 1; gp[i] = i;
    mem[i].pb(i);
  }
  rep1(i, 1, n+1) scanf("%d", w + i);
  rep1(i, 1, n+1) scanf("%lld", b + i);
  rep1(i, 1, m+1){
    DRII(u, v);
    uni(u, v);
  }
  rep1(i, 1, n+1) al.pb(fd(i));
  sort(ALL(al));
  al.resize(unique(ALL(al)) - al.begin() );
  for(int v : al){
    MS0(dp2);
    int cv = 0; LL cb = 0;
    for(int u : mem[v]){
      cv += w[u];
      cb += b[u];
      rep1(i, w[u], k+1){
        if(i != w[u] && !dp[i-w[u]]) continue;
        dp2[i] = max(dp2[i], dp[i-w[u]] + b[u]);
      }
    }
    rep1(i, cv, k+1){
      if(i != cv && !dp[i-cv]) continue;
      dp2[i] = max(dp2[i], dp[i-cv] + cb);
    }
    rep(i, k+1) dp[i] = max(dp[i], dp2[i]);
  }
  LL ans = 0;
  rep(i, k+1) ans = max(ans, dp[i]);
  printf("%lld\n", ans);
  return 0;
}