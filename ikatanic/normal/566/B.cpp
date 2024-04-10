#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 30300;

struct Replication {
  int a, b, c, id;
  friend bool operator < (const Replication& a, const Replication& b) {
    return a.id < b.id;
  }
};

multiset<Replication> S[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, 4*n) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a, --b, --c;
    S[b].insert({a, b, c, i});
    S[c].insert({a, b, c, i});
  }
  
  vector<int> ans;
  REP(i, n) 
    while (S[i].size()) {
      Replication r = {i, -1, -1, -1};
      while (!S[r.a].empty()) {
        r = *S[r.a].begin();
        S[r.b].erase(S[r.b].find(r));
        S[r.c].erase(S[r.c].find(r));
        ans.push_back(r.id);
      }
    }
  
  reverse(ans.begin(), ans.end());
  puts("YES");
  for (int x: ans) printf("%d ", x+1);
  printf("\n");
  return 0;
}