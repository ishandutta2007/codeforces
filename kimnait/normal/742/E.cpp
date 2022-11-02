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
const int MAX = 2e5+7;
int a[MAX], b[MAX], n;
vector<int>edge[MAX];
void init(){
  scanf("%d", &n); 
  rep1(i, 1, n+1) scanf("%d %d", a + i, b + i);
  return ;
}
int c[MAX];
int ck[MAX];
void dfs(int u, int t){
  c[u] = t; ck[u] = 1;
  for(int v : edge[u])
    if(!ck[v]) dfs(v, 3-t);
  return ;
}
void sol(){
  for(int i = 1; i <= 2*n; i += 2){
    edge[i].pb(i+1);
    edge[i+1].pb(i);
  }
  rep1(i, 1, n+1){
    edge[a[i]].pb(b[i]);
    edge[b[i]].pb(a[i]);
  }
  rep1(i, 1, 2*n+1) if(!ck[i]) dfs(i, 1);
  rep1(i, 1, n+1) printf("%d %d\n", c[a[i]], c[b[i]]);
  
  return ;
}
int main(void){
  init();
  sol();
  return 0;
}