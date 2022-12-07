#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<int> d;
vector<vector<pair<int, int>>> edges;
vector<int> answer;
vector<char> used;

int dfs(int x) {
  used[x] = 1;
  int sons = 0;
  if (d[x] == 1) sons = 1;
  for (auto edge : edges[x]) {
    int& y = edge.first;
    if (!used[y]) {
      int current = dfs(y);
      if (current == 1) {
        answer.emplace_back(edge.second);
      }
      sons += current;
    }
  }
  return sons & 1;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  d.resize(n);
  edges.resize(n);
  used.resize(n);
  int cnt_odd = 0;
  int who_negative = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
    if (d[i] == -1) {
      who_negative = i;
    } else if (d[i] == 1) {
      cnt_odd += 1;
    }
  }
  if (cnt_odd % 2 == 1) {
    if (who_negative == -1) {
      puts("-1");
      return 0;
    }
    d[who_negative] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[a - 1].emplace_back(b - 1, i + 1);
    edges[b - 1].emplace_back(a - 1, i + 1);
  }
  dfs(0);

  printf("%d\n", answer.size());
  for (int x : answer) {
    printf("%d\n", x);
  }

  return 0;
}