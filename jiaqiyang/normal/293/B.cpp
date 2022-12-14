#include <bits/stdc++.h>

typedef long long int64;

const int N = 10 + 1;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

const int MOD = 1000000007;

int n, m, k;
int board[N][N];

std::vector<int> cx[N], cy[N];

bool verify(int x, int y) {
  int c = board[x][y];
  for (int i = 0; i < cx[c].size(); ++i) {
    if (!(cx[c][i] == x && cy[c][i] == y)) {
      if (cx[c][i] <= x && cy[c][i] <= y) return false;
      if (cx[c][i] >= x && cy[c][i] >= y) return false;
    }
  }
  return true;
}

int DFS(int x, int y) {
  if (!y) ++x, y = m;
  if (x > n) return 1;
  if (board[x][y]) return verify(x, y) ? DFS(x, y - 1) : 0;
  int cnt = 0, temp = 0, res = 0;
  for (int i = 1; i <= k; ++i) {
    if (cx[i].empty()) {
      if (cnt) {
        ++cnt;
      } else {
        cnt = 1;
        board[x][y] = i;
        cx[i].push_back(x);
        cy[i].push_back(y);
        temp = DFS(x, y - 1);
        board[x][y] = 0;
        cx[i].pop_back();
        cy[i].pop_back();
      }
    } else {
      board[x][y] = i;
      cx[i].push_back(x);
      cy[i].push_back(y);
      if (verify(x, y)) (res += DFS(x, y - 1)) %= MOD;
      board[x][y] = 0;
      cx[i].pop_back();
      cy[i].pop_back();
    }
  }
  return res + (int64)cnt * temp % MOD;
}

int main() {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> board[i][j];
      cx[board[i][j]].push_back(i);
      cy[board[i][j]].push_back(j);
    }
  }
  std::cout << ((n + m - 1 <= k) ? DFS(1, m) : 0) << std::endl;
  return 0;
}