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
const int MAX = 1e5+7;
int a[MAX];
int main(void){
  DRIII(n, x, y);
  rep1(i, 1, n+1) scanf("%d", a + i);
  int ans = 0;
    rep1(i, 1, n/2+1){
      if(a[i] == a[n-i+1]){
        if(a[i] == 2) ans += 2*min(x, y);
      }
      else if(a[i] == 0){
        if(a[n-i+1] == 1){
          puts("-1"); return 0;
        }
        else ans += x;
      }
      else if(a[i] == 1){
        if(a[n-i+1] == 0){
          puts("-1"); return 0;
        }
        else ans += y;
      }
      else{
        if(a[n-i+1] == 0) ans += x;
        else ans += y;
      }
    }
  if(n % 2){
    if(a[n/2+1] == 2) ans += min(x,y);
  }
  printf("%d\n", ans);
  return 0;
}