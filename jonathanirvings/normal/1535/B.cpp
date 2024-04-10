#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    int answer = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (A[i] % 2 == 0 || A[j] % 2 == 0 || __gcd(A[i], A[j]) > 1) {
          ++answer;
        }
      }
    }
    printf("%d\n", answer);
  }
}