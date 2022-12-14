#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

typedef long long i64;

const int N = 50 + 10;

int n, q;
std::vector<std::string> adj[N];

i64 f[N][N];

i64 dfs(int a, int len) {
  if (len == 1) return 1;
  i64 &res = f[a][len];
  if (res) return res;
  for (int i = 0; i < adj[a].size(); ++i) res += dfs(adj[a][i][0] - 'a', len - 1);
  return res;
}

int main() {
  std::cin >> n >> q;
  for (int i = 1; i <= q; ++i) {
    std::string a;
    char b;
    std::cin >> a >> b;
    adj[b - 'a'].push_back(a);
  }
  printf("%I64d\n", dfs(0, n));
  return 0;
}