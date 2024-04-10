#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    int answer = 0;
    for (int i = 1;; i += 2) {
      ++answer;
      if (N <= i) {
        break;
      } else {
        N -= i;
      }
    }
    printf("%d\n", answer);
  }
}