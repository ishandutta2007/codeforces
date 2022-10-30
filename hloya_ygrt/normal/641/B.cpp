#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define de double
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define sd second
#define ft first
using namespace std;

const ld eps = 1e-9;
const int N = 1e2 + 7, maxn = 200000, inf = 1e9 + 77, px[7] = {0, 0, -1, 1}, py[7] = {-1, 1, 0, 0};

pair <int, int> a[N][N];
int ans[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = mp(i, j);
    }
  }
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      x--;
      pair <int, int> tmp = a[x][0];
      for (int j = 0; j < m - 1; j++) {
        a[x][j] = a[x][j + 1];
      }
      a[x][m - 1] = tmp;
    }
    if (t == 2) {
      int x;
      scanf("%d", &x);
      x--;
      pair <int, int> tmp = a[0][x];
      for (int j = 0; j < n - 1; j++) {
        a[j][x] = a[j + 1][x];
      }
      a[n - 1][x] = tmp;
    }
    if (t == 3) {
      int x, y, num;
      scanf("%d%d%d", &x, &y, &num);
      x--;
      y--;
      ans[a[x][y].ft][a[x][y].sd] = num;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) {
        printf(" ");
      }
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
}