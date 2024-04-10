#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    vector<int> B = A;
    sort(B.begin(), B.end());
    map<int, int> position;
    for (int i = 0; i < N; ++i) {
      position[B[i]] = i;
    }
    for (int i = 0; i < N - 1; ++i) {
      if (position[A[i + 1]] != position[A[i]] + 1) {
        --K;
      }
    }
    puts(K > 0 ? "Yes" : "No");
  }
}