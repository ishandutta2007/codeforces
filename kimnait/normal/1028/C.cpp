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
const int MAX = 2e5+7;
pair<PII, PII>pt[MAX];
int main(void){
  DRI(n);
  rep1(i, 1, n+1) scanf("%d %d %d %d", &pt[i].F.F, &pt[i].F.S, &pt[i].S.F, &pt[i].S.S);
  sort(pt + 1, pt + n + 1);
  int bp = 1, rp = 1, tp = 1;
  vector<int>die;
  rep1(i, 2, n+1){
    if(pt[i].F.F > pt[rp].S.F){
      die.pb(rp); die.pb(i); break;
    }
    if(pt[i].F.S > pt[tp].S.S){
      die.pb(tp); die.pb(i); break;
    }
    if(pt[i].S.S < pt[bp].F.S){
      die.pb(bp); die.pb(i); break;
    }
    if(pt[i].S.F < pt[rp].S.F) rp = i;
    if(pt[i].F.S > pt[bp].F.S) bp = i;
    if(pt[i].S.S < pt[tp].S.S) tp = i;
  }
  if(die.empty()){
    printf("%d %d\n", pt[rp].S.F, pt[tp].S.S);
    return 0;
  }
  for(int pos : die){
    bool f = 1;
    bool gg = 0;
    rep1(i, 1, n+1) if(i != pos){
      if(f){
        bp = rp = tp = i;
        f = 0;
        continue;
      }
      if(pt[i].F.F > pt[rp].S.F){
        gg = 1; break;
      }
      if(pt[i].F.S > pt[tp].S.S){
        gg = 1; break;
      }
      if(pt[i].S.S < pt[bp].F.S){
        gg = 1; break;
      }
      if(pt[i].S.F < pt[rp].S.F) rp = i;
      if(pt[i].F.S > pt[bp].F.S) bp = i;
      if(pt[i].S.S < pt[tp].S.S) tp = i;
    }
    if(!gg){
      printf("%d %d\n", pt[rp].S.F, pt[tp].S.S);
      return 0;
    }
  }
  return 0;
}