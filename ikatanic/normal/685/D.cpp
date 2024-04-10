#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;
const int inf = 2e9;

llint ans[MAX];
int x[MAX], y[MAX];
map<int, vector<int>> M;

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n) {
    scanf("%d %d", &x[i], &y[i]);
    M[x[i]-k+1].push_back(i);
    M[x[i]+1].push_back(i);
  }

  vector<int> v(y, y + n);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  vector<pair<int, int>> S;
  for (int y: v) S.push_back({y, 0});
  S.push_back({inf, 0});
  
  for (auto& p: M) {
    for (int i: p.second) {
      bool insert = x[i]-k+1 == p.first;

      auto itl = lower_bound(S.begin(), S.end(), make_pair(y[i]-k+1, -1));
      auto itr = itl;
      int cnt = 0;
      
      for (llint l = y[i]-k+1; l <= y[i]; ++l) {
        while (itl->first < l) cnt -= (itl++)->second;
        while (itr->first < l + k) cnt += (itr++)->second;

        if (insert) {
          ans[cnt] += p.first;
          ans[cnt + 1] -= p.first;
        } else {
          ans[cnt] += p.first;
          ans[cnt - 1] -= p.first;
        }
      }

      int idx = lower_bound(v.begin(), v.end(), y[i]) - v.begin();
      if (insert) {
        S[idx].second++;
      } else {
        S[idx].second--;
      }
    }
  }
  
  REP(i, n) printf("%lld ", ans[i+1]);
  printf("\n");
  return 0;
}