#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld", &A[i]);
    }
    sort(A.begin(), A.end());
    long long ans = A[N - 1];
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
      ans -= A[i] * i - sum;
      sum += A[i];
    }
    printf("%lld\n", ans);
  }
}