#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d", &B[i]);
    }
    vector<pair<int, int>> answer;
    while (true) {
      int i, j;
      for (i = 0; i < N && A[i] <= B[i]; ++i) {}
      for (j = 0; j < N && A[j] >= B[j]; ++j) {}
      if (i < N && j < N) {
        answer.push_back(make_pair(i, j));
        --A[i];
        ++A[j];
      } else {
        break;
      }
    }
    if (A == B) {
      printf("%d\n", answer.size());
      for (pair<int, int> ij : answer) {
        printf("%d %d\n", ij.first + 1, ij.second + 1);
      }
    } else {
      puts("-1");
    }
  }
}