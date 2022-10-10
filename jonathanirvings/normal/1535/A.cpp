#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    puts(min(C, D) < max(A, B) && min(A, B) < max(C, D) ? "YES" : "NO");
  }
}