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
const int MAX = 1e6+7;
int n, a[MAX];
void init(){
  scanf("%d", &n);
  rep1(i, 1, n+1) scanf("%d", a + i);
  return ;
}
int mnl[MAX], mnr[MAX];
int mxnl[MAX], mxnr[MAX];
void build(){
  stack<PII>st; st.push(MP(0, 0));
  rep1(i, 1, n+1){
    while(!st.empty()){
      int v = st.top().F;
      if(v <= a[i]){
        mnl[i] = st.top().S + 1;
        break;
      }
      else st.pop();
    }
    st.push(MP(a[i], i));
  }
  while(!st.empty()) st.pop();
  st.push(MP(0, n+1));
  per1(i, n, 1){
    while(!st.empty()){
      int v = st.top().F;
      if(v < a[i]){
        mnr[i] = st.top().S - 1;
        break;
      }
      else st.pop();
    }
    st.push(MP(a[i], i));
  }
  while(!st.empty()) st.pop(); 
  st.push(MP(INF, 0));
  rep1(i, 1, n+1){
    while(!st.empty()){
      int v = st.top().F;
      if(v >= a[i]){
        mxnl[i] = st.top().S + 1;
        break;
      }
      else st.pop();
    }
    st.push(MP(a[i], i));
  }
  while(!st.empty()) st.pop();
  st.push(MP(INF, n+1));
  per1(i, n, 1){
    while(!st.empty()){
      int v = st.top().F;
      if(v > a[i]){
        mxnr[i] = st.top().S - 1;
        break;
      }
      else st.pop();
    }
    st.push(MP(a[i], i));
  }
}
void sol(){
  LL ans = 0;
  rep1(i, 1, n+1){
    LL l = i - mxnl[i] + 1;
    LL r = mxnr[i] - i + 1;
    ans += (l*r-1)*a[i];
  }
  rep1(i, 1, n+1){
    LL l = i - mnl[i] + 1;
    LL r = mnr[i] - i + 1;
    ans -= (l*r-1)*a[i];
  }
  printf("%lld\n", ans);
}
int main(void){
  init();
  build();
  sol();
  return 0;
}