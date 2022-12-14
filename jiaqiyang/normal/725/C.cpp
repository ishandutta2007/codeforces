#include <cstdio>
#include <vector>

const int N = 100 + 10;

struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y): x(_x), y(_y) {}
};

char s[N], ans[2][N];

int main() {
  scanf(" %s", s);
  for (int i = 0; i < 26; ++i) if (s[i] == s[i + 1]) return puts("Impossible"), 0;
  for (int i = 0; i <= 26; ++i) {
    for (int j = i + 1; j <= 26; ++j) {
      if (s[i] != s[j]) continue;
      int t = j - i - 1;
      int y = t / 2, x = t % 2;
      ans[0][y] = s[i];
      std::vector<Point> p;
      for (int k = y - 1; k >= 0; --k) p.push_back(Point(0, k));
      for (int k = 0; p.size() < t; ++k) p.push_back(Point(1, k));
      for (int k = i + 1; k < j; ++k) ans[p[k - i - 1].x][p[k - i - 1].y] = s[k];
      p.clear();
      for (int k = y + 1; k < 13; ++k) p.push_back(Point(0, k));
      for (int k = 12; !ans[1][k]; --k) p.push_back(Point(1, k));
      for (int k = j + 1, q = 0; q < p.size(); ++q, ++k) ans[p[q].x][p[q].y] = s[k % 27];
      puts(ans[0]);
      puts(ans[1]);
      return 0;
    }
  }
  return 0;
}