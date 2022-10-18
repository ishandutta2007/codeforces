#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int N, S;
  scanf("%d %d", &N, &S);

  vector<pair<int, int>> v;
  llint score = 0;
  llint sum = 0;
  REP(i, N) {
    int s, a, b;
    scanf("%d %d %d", &s, &a, &b);
    sum += s;
    score += s * 1LL * a;
    v.push_back({b - a, s});
  }

  if (sum % S > 0) {
    int rem = S - (sum % S);
    v.push_back({0, rem});
    sum += rem;
  }
  
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  llint best = 0;

  llint cur_cnt = 0;
  llint cur_score = 0;
  REP(i, (int)v.size()) {
    llint have = v[i].second;
    
    if (cur_cnt % S > 0) {
      llint need = S - (cur_cnt % S);
      if (need > have) {
        cur_cnt += have;
        cur_score += have * v[i].first;
        continue;
      }

      have -= need;
      cur_cnt += need;
      cur_score += need * v[i].first;
      best = max(best, cur_score);
    }

    assert(cur_cnt % S == 0);
    
    llint k = have / S;
    best = max(best, cur_score + k * S * v[i].first);
    
    cur_cnt += have;
    cur_score += have * v[i].first;
  }
  
  score += best;
  printf("%lld\n", score);
  return 0;
}