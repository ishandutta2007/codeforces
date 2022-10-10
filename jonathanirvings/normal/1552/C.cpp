#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<bool> occupied(2 * N, false);
    vector<pair<int, int>> chords(K);
    for (int i = 0; i < K; ++i) {
      scanf("%d %d", &chords[i].first, &chords[i].second);
      --chords[i].first;
      --chords[i].second;
      occupied[chords[i].first] = occupied[chords[i].second] = true;
      if (chords[i].first > chords[i].second) {
        swap(chords[i].first, chords[i].second);
      }
    }
    vector<int> free_blocks;
    for (int i = 0; i < 2 * N; ++i) {
      if (!occupied[i]) {
        free_blocks.push_back(i);
      }
    }
    for (int i = 0; i < N - K; ++i) {
      chords.push_back(make_pair(free_blocks[i], free_blocks[i + N - K]));
    }
    int answer = 0;
    for (pair<int, int> x : chords) {
      for (pair<int, int> y : chords) {
        if (x.first < y.first && y.first < x.second && x.second < y.second) {
          ++answer;
        }
      }
    }
    printf("%d\n", answer);
  }
}