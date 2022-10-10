#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int K, N, M;
    scanf("%d %d %d", &K, &N, &M);
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d", &B[i]);
    }
    int i = 0;
    int j = 0;
    vector<int> answer;
    while (i < N || j < M) {
      if (i < N && A[i] <= K) {
        if (A[i] == 0) {
          ++K;
        }
        answer.push_back(A[i++]);
      } else if (j < M && B[j] <= K) {
        if (B[j] == 0) {
          ++K;
        }
        answer.push_back(B[j++]);
      } else {
        answer = {-1};
        break;
      }
    }
    for (int i = 0; i < answer.size(); ++i) {
      printf("%d%c", answer[i], " \n"[i == answer.size() - 1]);
    }
  }
}