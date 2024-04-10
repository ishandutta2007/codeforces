#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> positions;
vector<pair<int, int>> answer;

void recurse(set<int>& to_answer) {
  if (to_answer.size() > 0) {
    int x = *(to_answer.begin());
    for (int y : to_answer) {
      if (positions[y][positions[y].size() - 2] >
          positions[x][positions[x].size() - 2]) {
        x = y;
      }
    }
    answer[x] = make_pair(positions[x][positions[x].size() - 2],
                          positions[x][positions[x].size() - 1]);
    for (int y : to_answer) {
      if (x != y) {
        while (positions[y].back() > positions[x][positions[x].size() - 2]) {
          positions[y].pop_back();
        }
      }
    }
    to_answer.erase(x);
    recurse(to_answer);
  }
}

int main() {
  scanf("%d %d", &N, &K);
  positions = vector<vector<int>>(N);
  answer = vector<pair<int, int>>(N);
  for (int i = 0; i < N * K; ++i) {
    int C;
    scanf("%d", &C);
    positions[C - 1].push_back(i);
  }
  for (int i = 0; i < N; i += K - 1) {
    vector<int> to_answer(min(K - 1, N - i));
    iota(to_answer.begin(), to_answer.end(), i);
    set<int> to_answer_set = set<int>(to_answer.begin(), to_answer.end());
    recurse(to_answer_set);
  }
  for (int i = 0; i < N; ++i) {
    printf("%d %d\n", answer[i].first + 1, answer[i].second + 1);
  }
}