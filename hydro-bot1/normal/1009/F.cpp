// Hydro submission #621cb99d691e5f399cb2c61f@1646049693486
// 
// 
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e6;
int cnt, n, siz[N], dep[N], fa[N], son[N], top[N], in[N], out[N], w[N];
vector <int> ver[N];
void dfs(int x, int f) {
  in[x] = ++cnt;  w[cnt] = x;  fa[x] = f;
  dep[x] = dep[ fa[x] ] + 1;  siz[x] = 1;  
  FORV(i, ver[x]) {
    int to = ver[x][i];
    if(to == f) continue;
    dfs(to, x); 
    if(siz[to] > siz[son[x]]) son[x] = to;
    siz[x] += siz[to];
  }
  out[x] = cnt;
}
void dfs2(int now,int x) {
  top[now] = x;  if(son[now]) dfs2(son[now], x);  FORP(to, ver[now]) {
    if(to == fa[now] || to == son[now]) continue;  dfs2(to, to);
  }
}
int ct[N], mx, id, Ans[N];
void add(int point, int x, int val) {
  ct[ dep[point] ] += val;
  if( (ct[ dep[point] ] > mx || (ct[ dep[point] ] == mx && dep[point] - dep[x] < id - dep[x]) )) {
    mx = ct[ dep[point] ];
    id = dep[point];
  }
}
void dfs3(int x,int fl) {
  FORV(i, ver[x]) {  int to = ver[x][i];
    if(to != son[x] && to != fa[x]) dfs3(to, 0);
  }
  if(son[x]) dfs3(son[x], 1);
  FORV(i, ver[x]) {  int to = ver[x][i];
    if(to != son[x] && to != fa[x]) {
      FOR(j, in[to], out[to]) add(w[j], x, 1);
    }
  }  add(x, x, 1);  Ans[x] = id;
  if(fl) return;
  FOR(i, in[x], out[x])  add(w[i], x, -1);   mx = 0;  id = 0;
}
signed main () {
  n = read();  REP(i, 1, n) {   int a = read(), b = read();  
    ver[a].emplace_back(b);  ver[b].emplace_back(a);
  }  dfs(1, 0);  dfs2(1, 1);  dfs3(1, 0);
  FOR(i, 1, n) {
    printf("%d\n", Ans[i] - dep[i]);
  }
  return 0;
}