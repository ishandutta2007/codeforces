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
int main(void){
  vector<int>out;
  DRII(n, k);
  int m = 1 + 2*k;
  int ans = 0;
  if(m >= n){
    out.pb( min(1 + k, n) );
    ans = 1;
  }
  else if(n % m == 0){
    int pos = 1;
    rep(i, n / m){
      pos += k;
      out.pb(pos);
      pos += k + 1;
    }
    ans = n / m;
  }
  else{
    bool ok = 0;
    int st = 1;
    while(!ok){
      int pos = k+1+st;
      out.pb(st);
      rep(i, n / m - 1){
        pos += k;
        out.pb(pos);
        pos += k + 1;
      }
      int pp = min(n, pos + k);
      if(pp + k < n){
        out.clear();
        st++;
      }
      else{
        out.pb(pp);
        ok = 1;
      }
    }
    ans = n / m + 1;
  }
  printf("%d\n", ans);
  for(int v : out) printf("%d ", v);
  puts("");
  return 0;

}