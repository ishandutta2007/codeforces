#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  scanf("%d", &n);
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    s1 += x;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    s2 += x;
  }
  puts(s1 >= s2 ? "Yes" : "No");
  return 0;
}