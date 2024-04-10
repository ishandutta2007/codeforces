#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> R;

bool win(int a, int b) {
  int win_marathons = 0;
  for (int i = 0; i < 5; ++i) {
    if (R[a][i] < R[b][i]) {
      ++win_marathons;
    }
  }
  return win_marathons >= 3;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    R = vector<vector<int>>(N, vector<int>(5));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 5; ++j) {
        scanf("%d", &R[i][j]);
      }
    }
    int winner = 0;
    for (int i = 1; i < N; ++i) {
      if (!win(winner, i)) {
        winner = i;
      }
    }
    for (int i = 0; i < N; ++i) {
      if (i != winner && !win(winner, i)) {
        winner = -2;
        break;
      }
    }
    printf("%d\n", winner + 1);
  }
}