#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for (string &s : v) {
    cin >> s;
  }
  if (k % 2 != 0) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  int i, j;
  for (int ii = 0; ii < n; ++ii) {
    for (int jj = 0; jj < m; ++jj) {
      if (v[ii][jj] == 'X') {
        i = ii;
        j = jj;
      }
    }
  }
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  vector<vector<int>> bfs(n, vector<int>(m, -1));
  bfs[i][j] = 0;
  while (!q.empty()) {
    pair<int, int> old = q.front();
    q.pop();
    int ii = old.first;
    int jj = old.second;
    if (ii > 0 && v[ii - 1][jj] == '.' && bfs[ii - 1][jj] == -1) {
      q.push(make_pair(ii - 1, jj));
      bfs[ii - 1][jj] = bfs[ii][jj] + 1;
    }
    if (ii < n - 1 && v[ii + 1][jj] == '.' && bfs[ii + 1][jj] == -1) {
      q.push(make_pair(ii + 1, jj));
      bfs[ii + 1][jj] = bfs[ii][jj] + 1;
    }
    if (jj > 0 && v[ii][jj - 1] == '.' && bfs[ii][jj - 1] == -1) {
      q.push(make_pair(ii, jj - 1));
      bfs[ii][jj - 1] = bfs[ii][jj] + 1;
    }
    if (jj < m - 1 && v[ii][jj + 1] == '.' && bfs[ii][jj + 1] == -1) {
      q.push(make_pair(ii, jj + 1));
      bfs[ii][jj + 1] = bfs[ii][jj] + 1;
    }
  }
  string answer;
  while (k-- > 0) {
    if (i < n - 1 && bfs[i + 1][j] != -1 && bfs[i + 1][j] <= k) {
      answer += 'D';
      ++i;
    } else if (j > 0 && bfs[i][j - 1] != -1 && bfs[i][j - 1] <= k) {
      answer += 'L';
      --j;
    } else if (j < m - 1 && bfs[i][j + 1] != -1 && bfs[i][j + 1] <= k) {
      answer += 'R';
      ++j;
    } else if (i > 0 && bfs[i - 1][j] != -1 && bfs[i - 1][j] <= k) {
      answer += 'U';
      --i;
    } else {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  cout << answer << endl;
  return 0;
}