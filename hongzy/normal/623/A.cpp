#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 510;
int G[N][N], n, m;
bool B[N];
vector<int> A, _B, C;
char s[N];
int main() {
   scanf("%d%d", &n, &m);
   int u, v;
   rep(i, 1, m) {
      scanf("%d%d", &u, &v);
      G[u][v] = G[v][u] = 1;
   }
   rep(i, 1, n) {
      B[i] = 1;
      rep(j, 1, n) if(!G[i][j] && j != i) B[i] = 0;
      if(B[i]) _B.pb(i);
   }
   bool tag = 0;
   rep(j, 1, n) if(!B[j]) {
      int a = 0, c = 0, b = 0;
      for(int v : A) if(G[j][v]) {
         a ++;
      }
      for(int v : C) if(G[j][v]) {
         c ++;
      }
      // for(int v : _B) if(G[j][v]) {
      //    b ++;
      // }
      // if(b != _B.size()) {
      //    tag = 1; break ;
      // }
      if(a == A.size() && !c) A.pb(j);
      else if(c == C.size() && !a) C.pb(j);
      else {
         tag = 1; break ;
      }
   }
   if(tag) puts("No");
   else {
      puts("Yes");
      for(int v : A) s[v] = 'a';
      for(int v : _B) s[v] = 'b';
      for(int v : C) s[v] = 'c';
      puts(s + 1);
   }
   return 0;
}