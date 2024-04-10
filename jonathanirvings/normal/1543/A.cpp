#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long A, B;
    scanf("%lld %lld", &A, &B);
    if (A < B) {
      swap(A, B);
    }
    if (A == B) {
      puts("0 0");
    } else {
      long long D = A - B;
      printf("%lld %lld\n", D, min(A % D, D - A % D));
    }
  }
}