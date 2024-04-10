// Hydro submission #626429fd9f31360077dcd68b@1650731518301
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(int i=j; i<=k; ++i)
#define ROF(i,j,k) for(int i=j; i>=k; --i)
inline int read (void) {
  int x = 0, f = 1, ch = getchar();
  while(!isdigit(ch)) { if(ch == '-') f = -f; ch = getchar(); }
  while(isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}
const int maxn = 5005;
vector <pair <int, int> > v[maxn];
bool flag[maxn], ins[maxn];
int _ans, ans[maxn];
void dfs (int x) {
  flag[x] = 1; ins[x] = 1;
  for(auto&it:v[x])
    if(flag[it.first]) {
      if(ins[it.first]) ans[it.second] = _ans = 1;
    } else dfs (it.first);
  ins[x] = 0;
}
int main (void) {
  int n = read(), m = read();
  FOR(i,1,m) {
    int x = read(), y = read();
    v[x].push_back(make_pair(y, i));
  }
  FOR(i,1,n) if(!flag[i]) dfs (i);
  printf("%d\n", _ans + 1);
  FOR(i,1,m) printf("%d ", ans[i] + 1);
  return 0;
}