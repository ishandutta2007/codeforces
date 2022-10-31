// Hydro submission #6219dce69c14aaf0e915c9d6@1645862118981
// 
// 
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
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
const int N = 6e5;
int n, m, fa[N], a[N], ans[N];
vector <int> ver[N];
vector < pair<int,int> > pt[N];
char ch[N];
int siz[N], top[N], son[N], dep[N], in[N], out[N], cnt, w[N];
void dfs1(int x) {
  in[x] = ++cnt;  w[cnt] = x;
  dep[x] = dep[ fa[x] ] + 1;  siz[x] = 1;
  FORV(i, ver[x]) {
    int to = ver[x][i];
    dfs1(to); 
    if(siz[to] > siz[son[x]]) son[x] = to;
    siz[x] += siz[to];
  }
  out[x] = cnt;
}
void dfs2(int now,int x) {
  top[now] = x;
  if(son[now]) dfs2(son[now], x);
  FORV(i, ver[now]) {
    int to = ver[now][i];
    if(to == son[now] || to == fa[now]) continue;
    dfs2(to, to);  
  }
}
int ct[N][27], num;
void add(int d, int x) {  ct[d][x]++;  }
void del(int d, int x) {  ct[d][x]--;  }
void dfs3(int x,int fl) {
  FORV(i, ver[x]) {
    int to = ver[x][i];
    if(to == son[x]) continue;
    dfs3(to, 0);
  }
  if( son[x] ) dfs3(son[x], 1);
  FORV(i, ver[x]) {
    int to = ver[x][i];
    if(to == son[x]) continue;
    FOR(j, in[to], out[to]) {
      int now = w[j];
      add(dep[now], a[now]);
    }
  }
  add(dep[x], a[x]);
  FORV(i, pt[x]) {
    int d = pt[x][i].first, id = pt[x][i].second;
    int tot = 0;
    FOR(j, 1, 26) {  
      tot += ( ct[d][j] % 2 ==  1 );
    }
    ans[id] = ( tot <= 1 );
  }
  if( fl ) return;
  FOR(i, in[x], out[x]) {
    int now = w[i];
    del(dep[now], a[now]);
  }
}
signed main () {
  n = read(), m = read();
  FOR(i, 2, n) { fa[i] = read();  ver[fa[i]].emplace_back(i); }
  scanf("%s", ch + 1);
  FOR(i, 1, n) {  a[i] = ch[i] - 'a' + 1;  }
  FOR(i, 1, m) {  int u = read(), h = read();  pt[u].emplace_back( make_pair(h, i) );  }
  dep[1] = 1;
  dfs1(1);  dfs2(1, 1);
  dfs3(1, 0);
  FOR(i, 1, m) {  printf( "%s\n", ans[i] ? "Yes" : "No" ); }
  return 0;
}