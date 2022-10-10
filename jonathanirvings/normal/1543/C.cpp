#include <bits/stdc++.h>
using namespace std;

typedef double Double;

constexpr Double kEps = 1e-7;

Double expected(Double C, Double M, Double P, Double V) {
  Double res = 0;
  int cnt = (C > kEps) + (M > kEps) + (P > kEps);
  if (C > kEps) {
    res += C * (1 + expected(max(Double(0), C - V),
                             M <= kEps ? 0.0 : (M + min(C, V) / Double(cnt - 1)),
                             P + min(C, V) / (cnt - 1), V));
  }
  if (M > kEps) {
    res += M * (1 + expected(C <= kEps ? 0.0 : (C + min(M, V) / Double(cnt - 1)),
                             max(Double(0), M - V),
                             P + min(M, V) / (cnt - 1), V));
  }
  res += P * 1;
  return res;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    Double C, M, P, V;
    scanf("%lf %lf %lf %lf", &C, &M, &P, &V);
    printf("%.9lf\n", expected(C, M, P, V));
    // scanf("%Lf %Lf %Lf %Lf", &C, &M, &P, &V);
    // printf("%.9Lf\n", expected(C, M, P, V));
  }
}