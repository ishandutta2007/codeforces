#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int a, b, c;
};
bool operator<(Edge a, Edge b) {return a.c < b.c;}
Edge edge[1000000];
int par[100000];
int myfind(int p) {
  return par[p] = p == par[p] ? p : myfind(par[p]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> edge[i].a >> edge[i].b >> edge[i].c;
    edge[i].a--, edge[i].b--;
  }
  for (int i = 0; i < n; i++)
    par[i] = i;
  sort(edge+1, edge+m);
  int ans = 0;
  for (int i = 1; i < m; i++) {
    if (myfind(edge[0].a) != myfind(edge[0].b))
      ans = edge[i].c;
    par[myfind(edge[i].a)] = myfind(edge[i].b);
  }
  if (myfind(edge[0].a) != myfind(edge[0].b)) ans = 1e9;
  cout << ans << endl;
}