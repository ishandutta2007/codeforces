#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;

vector<pair<int, int>> E[MAX];
int deg[MAX];
bool alive[MAX];
int alive_cnt;
int N, M, K;

void kill(int x, int t) {
  if (alive[x] && deg[x] < K) {
    alive[x] = false;
    alive_cnt--;
    for (auto& p : E[x]) {
      if (p.second < t) {
        deg[p.first]--;
        kill(p.first, t);
      }
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> K;

  vector<pair<int, int>> friends(M);

  REP(i, M) {
    cin >> friends[i].first >> friends[i].second;
    --friends[i].first;
    --friends[i].second;
    E[friends[i].first].push_back({friends[i].second, i});
    E[friends[i].second].push_back({friends[i].first, i});
    deg[friends[i].first]++;
    deg[friends[i].second]++;
  }

  vector<int> ans(M);
  alive_cnt = N;
  REP(i, N) alive[i] = true;

  REP(i, N) kill(i, M);

  for (int i = M - 1; i >= 0; --i) {
    ans[i] = alive_cnt;

    int x = friends[i].first;
    int y = friends[i].second;

    if (alive[x] && alive[y]) {
      deg[x]--, deg[y]--;
      kill(x, i);
      kill(y, i);
    }
  }

  REP(i, M) cout << ans[i] << "\n";
  return 0;
}