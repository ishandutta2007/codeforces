#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int t[3];
	t[0] = a, t[1] = b, t[2] = c;
  sort(t, t + 3);
  a = t[0], b = t[1], c = t[2];
  if (c - a >= d + d) {
    printf("%d", max(0, d - min(c - b, b - a)));
  } else {
    if (b - a >= d) {
      printf("%d", max(0, d - (c - b)));
    } else if (c - b >= d) {
      printf("%d", max(0, d - (b - a)));
    } else {
      printf("%d", (d - (b - a)) + (d - (c - b)));
    }
  }
  return 0;
}