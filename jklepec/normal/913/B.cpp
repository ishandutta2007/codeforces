#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2005;

vector<int> e[MAXN];

void dfs(int u, int v) {
  int uk = 0;

  if(e[v].size() == 1 && v != u)
    return;

  for(auto w: e[v]) {
    if(u != w) {
      dfs(v, w);
      if(e[w].size() == 1)
        uk ++;
    }
  }

  if(uk < 3) {
    cout << "No";
    exit(0);
  }
}

int main() {
  int n; cin >> n;

  FOR(i, 1, n) {
    int x; cin >> x;
    x --;
    e[x].push_back(i);
    e[i].push_back(x);
  }

  dfs(0, 0);

  cout << "Yes";
}