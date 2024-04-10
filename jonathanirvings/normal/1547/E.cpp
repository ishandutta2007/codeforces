#include <bits/stdc++.h>
using namespace std;

constexpr int kInfinity = INT_MAX >> 1;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> A(N), T(N, kInfinity);
    for (int i = 0; i < K; ++i) {
      scanf("%d", &A[i]);
      --A[i];
    }
    for (int i = 0; i < K; ++i) {
      scanf("%d", &T[A[i]]);
    }
    int l = kInfinity, r = kInfinity;
    vector<int> answer(N, kInfinity);
    for (int i = 0; i < N; ++i) {
      l = min(l, T[i] - i);
      answer[i] = min(answer[i], l + i);
    }
    for (int i = N - 1; i >= 0; --i) {
      r = min(r, T[i] + i);
      answer[i] = min(answer[i], r - i);
    }
    for (int i = 0; i < N; ++i) {
      printf("%d%c", answer[i], " \n"[i == N - 1]);
    }
  }
}