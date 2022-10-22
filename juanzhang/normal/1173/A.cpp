#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int a, b, c;

int main() {
  scanf("%d %d %d", &a, &b, &c);
  if (a < b) {
    puts(a + c >= b ? "?" : "-");
  } else if (a > b) {
    puts(a <= b + c ? "?" : "+");
  } else {
    puts(c ? "?" : "0");
  }
  return 0;
}