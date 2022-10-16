#include <stdio.h>
#include <set>

typedef std::multiset<int> adjlist;

#define MAX 100005
#define pb  insert

adjlist adj[MAX];
char tr[4], str[2*MAX];
int lenstr, d[MAX], ok[MAX];

void dfs(int u) {
  while(!adj[u].empty()) {
    int v = *adj[u].begin();
    adj[u].erase(adj[u].begin());
    dfs(v);
  }
  str[lenstr++] = u % 128;
}

int main() {
  int n, u, v;
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%s", tr);
    u = tr[0]*128 + tr[1];
    v = tr[1]*128 + tr[2];
    adj[u].pb(v);
    ok[u] = ok[v] = 1;
    d[u]++, d[v]--;
  }
  int src = -1, cl = 0, cm = 0;
  for(int i=0; i<MAX; ++i) {
    if(!ok[i]) continue;
    if(d[i] < -1 || d[i] > 1) {
      puts("NO");
      return 0;
    }
    if(d[i] == 1) cl++, src = i;
    if(d[i] == -1) cm++;
    if(!d[i] && src == -1) src = i;
  }
  if(cl > 1 || cm > 1) {
    puts("NO");
    return 0;
  }
  dfs(src);
  for(int i=0; i<MAX; ++i) {
    if(!adj[i].empty()) {
      puts("NO");
      return 0;
    }
  }
  printf("YES\n%c", src/128);
  while(lenstr--) printf("%c", str[lenstr]);
  puts("");
  return 0;
}