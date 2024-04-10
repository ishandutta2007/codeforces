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

  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }
  v.push_back(0);
  v.push_back(1000000000);

  sort(v.begin(), v.end());

  vector<int> p(N + 1);

  int hor_cnt = 0;
  for (int i = 0; i < M; ++i) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    x1--;

    int a = lower_bound(v.begin(), v.end(), x1) - v.begin();
    int b = lower_bound(v.begin(), v.end(), x2 + 1) - 1 - v.begin();

    if (a == 0) {
      p[b]--;
      hor_cnt++;
    }
  }

  int best = 1000000000;
  for (int i = 0; i + 1 < (int)v.size(); ++i) {
    hor_cnt += p[i];
    best = min(best, hor_cnt + i);
  }

  cout << best << "\n";
  return 0;
}