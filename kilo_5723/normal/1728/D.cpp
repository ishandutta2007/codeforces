#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2e3 + 5;
const char res[3][6] = {"Bob", "Draw", "Alice"};
int win[maxn][maxn], fir[maxn][maxn];
char s[maxn];
int chkwin(char f1, int w1, char f2) {
  if (w1) return w1;
  return (f2 < f1) - (f2 > f1);
  // if (f1 == f2) return w1;
  // return f1 > f2 ? 1 : -1;
  // return f1 != f2 ? (f2 < f1) - (f2 > f1) : w1;
}
pair<char, int> selfir(char f1, int w1, char f2, int w2) {
  pair<char, int> pr1 = {f1, w1}, pr2 = {f2, w2};
  if (w1 != w2) return w1 > w2 ? pr1 : pr2;
  return f1 < f2 ? pr1 : pr2;
  // return (f1 != f2 ? (f1 < f2) : (w1 > w2)) ? pr1 : pr2;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int n = strlen(s);
    // printf("%d\n", n);
    for (int i = 0; i < n; i++) {
      fir[i][i] = s[i];
      win[i][i] = 0;
      // putchar(fir[i][i]);
    }
    // puts("");
    for (int j = 1; j < n; j++)
      for (int i = 0; i + j < n; i++)
        if (j & 1) {
          win[i][i + j] =
              max(chkwin(fir[i][i + j - 1], -win[i][i + j - 1], s[i + j]),
                  chkwin(fir[i + 1][i + j], -win[i + 1][i + j], s[i]));
        } else {
          auto pr =
              selfir(s[i], -win[i + 1][i + j], s[i + j], -win[i][i + j - 1]);
          fir[i][i + j] = pr.first;
          win[i][i + j] = pr.second;
        }
    // for (int i = 0; i < n; i++)
    //   for (int j = i; j < n; j++) {
    //     for (int k = i; k <= j; k++) putchar(s[k]);
    //     printf(": ");
    //     if (i - j & 1)
    //       printf("%d\n", win[i][j]);
    //     else
    //       printf("%c %d\n", fir[i][j], win[i][j]);
    //   }
    puts(res[win[0][n - 1] + 1]);
  }
  return 0;
}