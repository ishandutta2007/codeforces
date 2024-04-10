#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100;

char bd[N], fro[N];
int tab[N];

int main() {
  int la, lb;
  scanf("%s", fro + 1);
  la = strlen(fro + 1);
  for (int i = 1; i <= la; i ++) tab[fro[i] - '0'] ++;
  scanf("%s", bd + 1);
  lb = strlen(bd + 1);
  if (la < lb) {
    for (int i = 9; i >= 0; i --)
      while (tab[i] --) printf("%d", i);
    puts("");
    return 0;
  }
  bool done = 0;
  for (int i = 1; i <= la; i ++) {
    for (int j = 9; j >= 0; j --) {
      if (!tab[j]) continue;
      if (done) {
        printf("%d", j);
        tab[j] --;
        break;
      }
      if (j > bd[i] - '0') continue;
      tab[j] --;
      bool ok = 1, ter = 0;
      int pos = i;
      if (j < bd[i] - '0') ter = 1;
      for (int k = 0; k <= 9; k ++) {
        for (int l = 1; l <= tab[k] && !ter; l ++) {
          pos ++;
          if (bd[pos] - '0' < k) ok = 0;
          if (bd[pos] - '0' > k) ter = 1;
        }
      }
      if (ok) {
        printf("%d", j);
        if (j < bd[i] - '0') done = 1;
        break;
      }
      else tab[j] ++;
    }
  }
  puts("");
  return 0;
}