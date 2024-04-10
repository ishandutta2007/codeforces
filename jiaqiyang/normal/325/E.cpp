#include <bits/stdc++.h>

const int N = 100000 + 10;

int n;

std::vector<int> adj[N], ans;

void DFS(int cur) {
  int orig = cur;
  cur %= n / 2;
  while (!adj[cur].empty()) {
    int next = adj[cur].back();
    adj[cur].pop_back();
    DFS(next);
  }
  ans.push_back(orig);
}

int main() {
  scanf("%d", &n);
  if (n & 1) {
    puts("-1");
  } else {
    for (int i = 0; i * 2 < n; ++i) {
      adj[i].push_back(2 * i);
      adj[i].push_back(2 * i + 1);
    }
    DFS(0);
    for (std::vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) printf("%d ", *it);
    putchar('\n');
  }
  return 0;
}