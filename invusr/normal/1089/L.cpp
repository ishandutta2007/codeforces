#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n, k;
int job[N + 1];
vector<int> idler[N + 1];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &job[i]);
  }
  for (int i = 1; i <= n; ++i) {
    int t;
    scanf("%d", &t);
    idler[job[i]].push_back(t);
  }

  priority_queue<int> q;
  int remain = k;
  for (int i = 1; i <= k; ++i) {
    if (!idler[i].empty()) {
      --remain;
      sort(idler[i].begin(), idler[i].end());
      for (int j = 0; j < idler[i].size() - 1; ++j) {
        q.push(-idler[i][j]);
      }
    }
  }
  long long answer = 0;
  while (remain--) {
    answer -= q.top();
    q.pop();
  }
  cout << answer << endl;

  return 0;
}