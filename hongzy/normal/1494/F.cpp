#include <bits/stdc++.h>
#define pb push_back
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 3005;
struct Edge {
  int v, nxt;
} e[N * 2];
int n, m, ec, hd[N], cur[N], deg[N];
bool ban[N], vis[N];
void add(int u, int v) {
  e[ec] = {v, hd[u]}; hd[u] = ec ++; deg[v] ++;
}
vector<int> res;
void eular(int u) {
  for(int &i = cur[u]; ~i; ) {
    if(ban[i / 2] || vis[i / 2]) {
      i = e[i].nxt; continue ;
    }
    vis[i / 2] = 1;
    int v = e[i].v;
    i = e[i].nxt;
    eular(v);
    res.pb(v);
  }
}
bool check(int s) {
  int c = 0;
  rep(i, 1, n) {
    c += deg[i] & 1;
    if(c > 2) break ;
  }
  if(c > 2 || c == 1) return 0;
  if(c == 2 && !(deg[s] & 1)) return 0;
  res.clear();
  fill(vis, vis + ec / 2 + 1, 0);
  copy(hd + 1, hd + n + 1, cur + 1);
  eular(s);
  // LOG("chk %d(%d)!\n", s, m);
  // for(int v : res) LOG("%d,", v);
  // LOG("\n");
  if(res.size() != m) return 0;
  res.pb(s);
  return 1;
}
void print(int s) {
  vector<int> ans = res;
  ans.pb(-1);
  for(int i = hd[s]; ~i; i = e[i].nxt)
    if(ban[i / 2]) {
      ans.pb(e[i].v);
      ans.pb(s);
    }
  printf("%lu\n", ans.size());
  for(int v : ans) printf("%d ", v);
  putchar('\n');
}
int main() {
  scanf("%d%d", &n, &m);
  fill(hd + 1, hd + n + 1, -1);
  int x, y;
  rep(i, 1, m) {
    scanf("%d%d", &x, &y);
    add(x, y); add(y, x);
  }
  rep(s, 1, n) {
    for(int i = hd[s]; ~i; i = e[i].nxt) {
      int u = e[i].v;
      if(deg[u] & 1) {
        ban[i / 2] = 1; deg[u] --; deg[s] --; m --;
      }
    }
    if(check(s)) {
      print(s);
      return 0;
    }
    for(int i = hd[s]; ~i; i = e[i].nxt) {
      int u = e[i].v;
      if(ban[i / 2]) {
        ban[i / 2] = 0; deg[u] ++; deg[s] ++; m ++;
      } else {
        ban[i / 2] = 1; deg[u] --; deg[s] --; m --;
      }
      if(check(s)) {
        print(s);
        return 0;
      }
      if(ban[i / 2]) {
        ban[i / 2] = 0; deg[u] ++; deg[s] ++; m ++;
      } else {
        ban[i / 2] = 1; deg[u] --; deg[s] --; m --;
      }
    }
    for(int i = hd[s]; ~i; i = e[i].nxt) if(ban[i / 2]) {
      deg[e[i].v] ++; deg[s] ++; ban[i / 2] = 0; m ++;
    }
  }
  puts("0");
  return 0;
}