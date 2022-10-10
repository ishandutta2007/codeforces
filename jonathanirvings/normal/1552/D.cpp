#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

bool dfs(int x, int sum, bool taken) {
  if (x == A.size()) {
    return sum == 0 && taken;
  }
  return dfs(x + 1, sum + A[x], true)
      || dfs(x + 1, sum, taken)
      || dfs(x + 1, sum - A[x], true);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    A = vector<int>(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    puts(dfs(0, 0, false) ? "YES" : "NO");
  }
}