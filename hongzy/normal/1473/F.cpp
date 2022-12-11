#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

const int N = 3000 + 10;
const int INF = 2147483640;

int n, a[3005], b[3005];
typedef long long ll;

namespace Net {

int n, m, s, t;

struct Edge { int v, c, f, nxt; } e[N * 100];
int hd[N], p;

void add(int u, int v, int c) {
    e[p] = (Edge) {v, c, 0, hd[u]}; hd[u] = p ++;
    e[p] = (Edge) {u, 0, 0, hd[v]}; hd[v] = p ++;
}

queue<int> q;
int d[N], cur[N];
bool bfs() {
    fill(d + 1, d + n + 1, -1);
    q.push(s); d[s] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = hd[u]; ~ i; i = e[i].nxt) {
         int v = e[i].v; 
            if(d[v] == -1 && e[i].c > e[i].f) {
                d[v] = d[u] + 1; q.push(v);
            }
        }
    }
    return ~ d[t];
}

ll dfs(int u, int a) {
    if(u == t || a == 0) return a;
    ll ans = 0, f;
    for(int &i = cur[u]; ~ i; i = e[i].nxt) {
      int v = e[i].v;
        if(d[u] + 1 == d[v] && e[i].c > e[i].f && (f = dfs(v, min(a, e[i].c - e[i].f))) > 0) {
            ans += f; e[i].f += f; e[i ^ 1].f -= f;
            if((a -= f) == 0) break ;
        }
    }
    return ans;
}

ll dinic() {
    ll ans = 0;
    while(bfs()) {
        copy(hd + 1, hd + n + 1, cur + 1);
        ans += dfs(s, INF);
    }
    return ans;
}
void clr() {
   fill(hd + 1, hd + N, -1); p = 0;
}

}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d", a + i);
   rep(i, 1, n) scanf("%d", b + i);
   Net::s = n + 1; Net::t = Net::n = n + 2;  Net::clr();
   ll s = 0;
   vector<int> last(101);
   rep(i, 1, n) {
      rep(j, 1, a[i]) if(a[i] % j == 0 && last[j]) {
         Net::add(i, last[j], INF);
      }
      if(b[i] >= 0) {
         Net::add(n + 1, i, b[i]);
         s += b[i];
      } else {
         Net::add(i, n + 2, - b[i]);
      }
      last[a[i]] = i;
   }
   printf("%lld\n", s - Net::dinic());
   return 0;
}