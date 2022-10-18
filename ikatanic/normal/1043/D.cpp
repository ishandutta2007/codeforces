#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, M;

  cin >> N >> M;

  vector<vector<int>> a(M, vector<int>(N));
  vector<int> p(N);
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> a[i][j];
      --a[i][j];
      if (i == 0) p[a[i][j]] = j;
    }
  }

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      a[i][j] = p[a[i][j]];
    }
  }

  vector<int> best(N, 0);
  for (int i = 0; i < M; ++i) {
    int first = -1;
    for (int j = 0; j < N; ++j) {
      if (j == 0 || a[i][j] != a[i][j-1] + 1) {
        first = a[i][j];
      }
      best[a[i][j]] = max(best[a[i][j]], first);
    }
  }

  llint ret = 0;
  for (int i = 0; i < N; ++i) {
    ret += i - best[i] + 1;
  }

  cout << ret << "\n";
  return 0;
}