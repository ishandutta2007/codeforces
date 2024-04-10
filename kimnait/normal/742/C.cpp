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
const int MAX = 1e5+7;
int ck[MAX];
int a[MAX];
inline LL gcd(LL v1, LL v2){
  while(v1){
    LL tmp = v2 % v1;
    v2 = v1;
    v1 = tmp;
  }
  return v2;
}
int main(void){
  DRI(n);
  LL ans = 1;
  rep1(i, 1, n+1) scanf("%d", a + i);
  rep1(i, 1, n+1) if(!ck[i]){
    int p = a[i]; LL cnt = 0;
    while(!ck[p]){
      ck[p] = 1;
      cnt++;
      p = a[p];
    }
    if(p != a[i] || !ck[i]){
      puts("-1"); return 0;
    }
    if(cnt % 2 == 0) ans = cnt/2*ans/gcd(cnt/2, ans);
    else ans = cnt*ans/gcd(cnt, ans);
  }
  printf("%lld\n", ans);
  return 0;
}