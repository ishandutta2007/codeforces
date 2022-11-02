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
const double eps = 1e-13;
const double PI = acos(-1);
//////////////////////////////
const LL INFF = 1e18;
const int INF = 1e9;
const int mod = 1e9+7;
const int MAX = 5e5+7;
LL val[7];
int num[7], st[7][107], lsum[7][107];
int t1[7], t2[7];
int cnt[7];
LL ans = 0;
void go(int p, LL cur, int typ){
  if(p == 7){
    LL v = cur;
    rep1(i, 1, 5) if(cnt[i]) v += val[i];
    int res = 0;
    rep1(i, 1, 5) res += (cnt[i] % 2);
    if(typ == 66 || typ == 36 || typ == 24) return ;
    if(res <= 2){
      ans = max(ans, v);
    }
    return ;
  }

  rep(i, num[p]+1){
    cnt[ t1[p] ] += i;
    cnt[ t2[p] ] += i;
    int ntyp = typ;
    if(i) ntyp |= 1<<p;
    go(p+1, cur + lsum[p][i], ntyp);
    cnt[ t1[p] ] -= i;
    cnt[ t2[p] ] -= i;
  }
  return ;
}
int main(void){
  t1[1] = 1, t2[1] = 2;
  t1[2] = 1, t2[2] = 3;
  t1[3] = 1, t2[3] = 4;
  t1[4] = 2, t2[4] = 3;
  t1[5] = 2, t2[5] = 4;
  t1[6] = 3, t2[6] = 4;
  DRI(n);
  rep1(i, 1, n+1){
    DRIII(c1, v, c2);
    if(c1 == c2) val[c1] += v;
    else{
      if(c1 > c2) swap(c1, c2);
      if( c1 == 1 && c2 == 2 ) st[1][++num[1]] = v;
      if( c1 == 1 && c2 == 3 ) st[2][++num[2]] = v;
      if( c1 == 1 && c2 == 4 ) st[3][++num[3]] = v;
      if( c1 == 2 && c2 == 3 ) st[4][++num[4]] = v;
      if( c1 == 2 && c2 == 4 ) st[5][++num[5]] = v;
      if( c1 == 3 && c2 == 4 ) st[6][++num[6]] = v;
    }
  }
  rep1(i, 1, 7){
    sort(st[i] + 1, st[i] + num[i] + 1, greater<int>());
    rep1(j, 1, num[i]+1) lsum[i][j] = lsum[i][j-1] + st[i][j];
  }
  go(1, 0, 0); 
  rep1(i, 1, 5) ans = max(ans, val[i]);
  printf("%lld\n", ans);
  return 0;
}