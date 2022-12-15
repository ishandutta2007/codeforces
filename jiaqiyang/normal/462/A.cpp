#include <cstdio>

const int N = 100 + 10;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n;
char s[N][N];

inline bool ok(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

bool check() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int cnt = 0;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (ok(x, y)) cnt += (s[x][y] == 'o');
      }
      if (cnt & 1) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf(" %s", s[i]);
  puts(check() ? "YES" : "NO");
  return 0;
}