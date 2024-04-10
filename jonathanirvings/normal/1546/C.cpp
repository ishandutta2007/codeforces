#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    vector<int> even((N + 1) >> 1), odd(N >> 1);
    for (int i = 0; i < N; ++i) {
      if (i & 1) {
        scanf("%d", &odd[i >> 1]);
      } else {
        scanf("%d", &even[i >> 1]);
      }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    vector<int> combined(N);
    for (int i = 0; i < N; ++i) {
      combined[i] = (i & 1) ? odd[i >> 1] : even[i >> 1];
    }
    puts(is_sorted(combined.begin(), combined.end()) ? "YES" : "NO");
  }
}