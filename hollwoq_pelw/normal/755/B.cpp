#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

string a[N];

char foo[N];

void get(string &s) {
  scanf("%s", foo);
  s = "";
  for (int j = 0; foo[j]; j++) {
    s += foo[j];
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n + m; i++) {
    get(a[i]);
  }
  sort(a, a + n + m);
  int common = 0;
  for (int i = 0; i < n + m - 1; i++) {
    if (a[i] == a[i + 1]) {
      common++;
    }
  }
  n -= common;
  m -= common;
  for (int it = 0; ; it++) {
    if (it % 2 == 0) {
      if (common > 0) common--; else
      if (n > 0) n--; else {
        puts("NO");
        break;
      }
    } else {
      if (common > 0) common--; else
      if (m > 0) m--; else {
        puts("YES");
        break;
      }
    }
  }
  return 0;
}