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
  srand(time(NULL));
  DRLL(n, k);
  char com[7];
  if(n <= 1+3*k){
    while(1){
      int v = rand() % n + 1;
      printf("%d %d\n", v, v);
      fflush(stdout);
      scanf("%s", com);
      if(com[0] == 'Y') return 0;
      else if(com[0] == 'B') return 0;
    }
  }
  else{
    LL ll = 1, rr = n;
    while(1){
      while(rr - ll > 51){
        LL mid = (ll + rr) >> 1;
        printf("%lld %lld\n", ll, mid);
        fflush(stdout);
        scanf("%s", com);
        if(com[0] == 'Y'){
          if(ll == mid) return 0;
          ll = max(1LL, ll - k);
          rr = min(n, mid+k);
        }
        else if(com[0] == 'B') return 0;
        else{
          ll = max(1LL, mid + 1 - k);
          rr = min(n, rr+k);
        }
      }
      LL v = rand() % (rr - ll + 1) + ll;
      printf("%lld %lld\n", v, v);
      fflush(stdout);
      scanf("%s", com);
      if(com[0] == 'Y') return 0;
      else if(com[0] == 'B') return 0;
      ll = max(1LL, ll - k);
      rr = min(n, rr + k);
    }
  }
  return 0;

}