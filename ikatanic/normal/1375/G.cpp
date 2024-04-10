#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

const int MAX = 200200;

vector<int> E[MAX];
int d[MAX];

void dfs(int x, int parent) {
  for (int y: E[x]) {
    if (y == parent) continue;
    d[y] = d[x] + 1;
    dfs(y, x);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1);

  int cnt = 0;
  for (int i = 0;i < n; ++i) {
    if (d[i] % 2) cnt++;
  }

  auto ans = min(cnt, n - cnt) - 1;
  cout << ans << '\n';
  return 0;
}