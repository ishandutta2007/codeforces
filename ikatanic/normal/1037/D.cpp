#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

vector<int> E[MAX];

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N - 1) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    E[A].push_back(B);
    E[B].push_back(A);
  }

  vector<int> order(N);
  vector<int> pos(N);
  REP(i, N) {
    cin >> order[i];
    --order[i];
    pos[order[i]] = i;
  }

  REP(i, N) {
    sort(E[i].begin(), E[i].end(),
         [&](const int x, const int y) { return pos[x] < pos[y]; });
  }

  vector<int> real_order;

  queue<int> Q;
  Q.push(0);
  vector<bool> visited(N, false);
  visited[0] = true;

  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    real_order.push_back(x);

    for (int y : E[x]) {
      if (!visited[y]) {
        Q.push(y);
        visited[y] = true;
      }
    }
  }

  if (real_order == order) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}