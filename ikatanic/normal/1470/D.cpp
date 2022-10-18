#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      E[a].push_back(b);
      E[b].push_back(a);
    }

    queue<int> Q;
    vector<bool> visited(n, false);
    vector<bool> teacher(n, false);

    teacher[0] = true;
    visited[0] = true;
    vector<int> teachers;
    teachers.push_back(0);
    int visited_cnt = 1;
    for (int y : E[0]) {
      Q.push(y);
      visited[y] = true;
    }

    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();

      visited_cnt++;

      for (int y : E[x]) {
        if (!visited[y]) {
          visited[y] = true;
          teacher[y] = true;
          teachers.push_back(y);
          visited_cnt++;
          for (int k : E[y]) {
            if (!visited[k]) {
              visited[k] = true;
              teacher[k] = false;
              Q.push(k);
            }
          }
        }
      }
    }

    if (visited_cnt == n) {
      cout << "YES\n";
      cout << teachers.size() << '\n';
      for (int x : teachers) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}