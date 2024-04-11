//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MAXN = 507;
vi G[MAXN];
int odw[MAXN];
int pre[MAXN];
vector <pii> pos;
pii blocked = {-1, -1};

bool dfs(int v, int prz = -1) {
  odw[v] = 1;
  pre[v] = prz;
  for(auto w : G[v]) {
    if(blocked.x == v and blocked.y == w) continue;
    if(odw[w] == 1) {
      if(blocked.x == -1) {
        int f = v;
        pos.emplace_back(v, w);
        while(f != w) {
          pos.emplace_back(pre[f], f);
          f = pre[f];
        }
      }
      return true;
    } else if(odw[w] == 0 and dfs(w,v)) return true;
  }
  odw[v] = 2;
  return false;
}

int n;

bool check(pii x) {
  for(int i=1; i<=n; i++) odw[i] = false;
  for(int i=1; i<=n; i++) pre[i] = 0;
  blocked = x;
  for(int i=1; i<=n; i++) if(!odw[i]) if(dfs(i)) return false;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }
  for(int i=1; i<=n; i++) if(!odw[i]) if(dfs(i)) break;
  if(pos.empty()) {
    cout << "YES\n";
    return 0;
  }
  for(auto e : pos) {
    if(check(e)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}