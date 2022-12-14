#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  puts((n & 1) ? "contest" : "home");
  return 0;
}