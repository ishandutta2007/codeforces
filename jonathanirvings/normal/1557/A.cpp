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
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    int largest = *max_element(A.begin(), A.end());
    printf("%.9lf\n", (double)(sum - largest) / (N - 1) + largest);
  }
}