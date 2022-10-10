#include <bits/stdc++.h>
using namespace std;

int distance(pair<int, int> A, pair<int, int> B) {
  return abs(A.first - B.first) + abs(A.second - B.second);
}

bool middle(pair<int, int> A, pair<int, int> B, pair<int, int> F) {
  if (A.first != B.first && A.second != B.second) {
    return false;
  }
  return distance(A, B) == distance(A, F) + distance(F, B);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    pair<int, int> A, B, F;
    scanf("%d %d %d %d %d %d",
          &A.first, &A.second, &B.first, &B.second, &F.first, &F.second);
    printf("%d\n", distance(A, B) + (middle(A, B, F) ? 2 : 0));
  }
}