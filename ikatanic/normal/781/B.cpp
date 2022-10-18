#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int n;
  scanf("%d", &n);

  map<string, vector<int>> M;
  vector<string> fst, sec;
  REP(i, n) {
    char a[111], b[111];
    scanf("%s %s", a, b);
    string A = a, B = b;
    
    fst.push_back(A.substr(0, 3));
    sec.push_back(A.substr(0, 2) + B.substr(0, 1));
      
    M[A.substr(0, 3)].push_back(i);
  }

  vector<string> ans(n);
  set<string> used;

  for (auto& p: M) {
    if (p.second.size() > 1) {
      for (int x : p.second) {
        used.insert(sec[x]);
        ans[x] = sec[x];
      }
    }
  }

  while (true) {
    bool done = true;
    for (auto& p: M) {
      if (p.second.size() == 1) {
        int x = p.second[0];
        if (ans[x] == "" && used.count(fst[x])) {
          used.insert(sec[x]);
          ans[x] = sec[x];
          done = false;
        }
      }
    }
    if (done) break;
  }

  for (auto& p: M) {
    if (p.second.size() == 1) {
      int x = p.second[0];
      if (ans[x] == "") {
        used.insert(fst[x]);
        ans[x] = fst[x];
      }
    }
  }

  if ((int)used.size() == n) {
    puts("YES");
    REP(i, n) puts(ans[i].c_str());
  } else {
    puts("NO");
  }
     
  return 0;
}