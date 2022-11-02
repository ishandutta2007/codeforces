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
#include <unordered_set>
#include <unordered_map>
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
#define SZ(x) ((int)x.size() )
#define MP make_pair 
#define pb push_back
#define F first
#define S second
#define ALL(I) (I).begin(), (I).end()
#define ios std::ios::sync_with_stdio(false); std::cin.tie(0);
typedef const void CV;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII; 
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
const double eps = 1e-7;
//const double PI = acos(-1);
//////////////////////////////
const LL INFF = 1e18;
const int INF = 1e9;
const int mod = 1e9+7;
const int MAX = 5e5+7;
LL a[MAX];
typedef pair<LL, PII> PT;
int siz[MAX], gp[MAX];
PT al[MAX];
int fd(int v){
  return gp[v] == v ? v : gp[v] = fd(gp[v]);
}
bool uni(int u, int v){
  u = fd(u); v = fd(v);
  if(u == v) return 0;
  if(siz[u] > siz[v]) swap(u, v);
  gp[u] = v;
  siz[v] += siz[u];
  return 1;
}
LL val[MAX];
void build(){
  val[0] = 1;
  rep1(i, 1, MAX) val[i] = val[i-1]*2%mod;
  return ;
}
int main(void){
  build();
  DRIII(n, m, k);
  rep1(i, 1, n+1) scanf("%lld", a + i);
  rep1(i, 1, n+1) siz[i] = 1, gp[i] = i;
  rep1(i, 1, m+1){
    DRII(u, v);
    al[i] = MP(a[u] ^ a[v], MP(u, v));
  }
  sort(al + 1, al + m + 1);
  LL cnt = 1LL<<k, ans = 0;
  rep1(i, 1, m+1){
    int ed = i;
    cnt--;
    while(ed < m && al[ed + 1].F == al[i].F) ed++;
    int num = n;
    rep1(j, i, ed+1){
      if( uni(al[j].S.F, al[j].S.S) ) num--; 
    }
    ans = (ans + val[num]) % mod;
    rep1(j, i, ed+1){
      siz[ al[j].S.F ] = siz[ al[j].S.S ] = 1;
      gp[ al[j].S.F ] = al[j].S.F;
      gp[ al[j].S.S ] = al[j].S.S;
    }
    i = ed;
  }
  ans = (ans + (cnt % mod)*val[n]%mod) % mod;
  printf("%lld\n", ans);
  return 0;
}