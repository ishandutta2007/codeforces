#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 105;
int wina[maxn][maxn][2], winb[maxn][maxn][2];
int dfsa(int, int, int);
int dfsb(int x, int y, int b) {
  int &w = winb[x][y][b];
  if (~w) return w;
  if (!x && !y) return w = !b;
  return w = min(x ? dfsa(x - 1, y, b) : 1, y ? dfsa(x, y - 1, b) : 1);
}
int dfsa(int x, int y, int b) {
  int &w = wina[x][y][b];
  if (~w) return w;
  if (!x && !y) return w = !b;
  return w = max(x ? dfsb(x - 1, y, !b) : 0, y ? dfsb(x, y - 1, b) : 0);
}
int main() {
  memset(wina, -1, sizeof(wina));
  memset(winb, -1, sizeof(winb));
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a = 0, b = 0;
    while (n--) {
      int t;
      scanf("%d", &t);
      (t & 1 ? a : b)++;
    }
    puts(dfsa(a, b, 0) ? "Alice" : "Bob");
  }
  return 0;
}