#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 9*8*7*5;

int mem[1000][m];
int k[1000];
vector<int> node[1000];
int visited[1000][m];

int cycle(int p, int c) {
  set<int> seen;
  int p0 = p, c0 = c;
  do {
    seen.insert(p);
    c = (c+k[p])%m;
    p = node[p][c%node[p].size()];
  } while (p != p0 || c != c0);

  return seen.size();
}

int dfs(int p, int c) {
  int&memo = mem[p][c];
  if (memo) {
    return memo;
  }
  if (visited[p][c]++) {
    return cycle(p, c);
  }
  int x = (c+k[p])%m;
  //cerr << p+1 << ' ' << (c > m/2 ? c-m : c) << endl;
  memo = dfs(node[p][x%node[p].size()], x);
  visited[p][c] = 0;
  return memo;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    k[i] = (k[i]%m+m)%m;
  }

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int e;
      cin >> e;
      node[i].push_back(e-1);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y = (y%m+m)%m;
    cout << dfs(x,y) << '\n';
  }
}