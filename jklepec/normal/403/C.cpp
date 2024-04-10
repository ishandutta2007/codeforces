#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e3 + 5;

int e[MAXN][MAXN];

stack<int> s;

bool bio[MAXN];
int n;

void dfs(int x) {
  if(bio[x]) {
    return;
  }
  bio[x] = true;
  REP(i, n) {
    if(e[x][i]) dfs(i);
  }

  s.push(x);
}

int uk;

void redfs(int x) {
  if(bio[x]) return;
  uk ++;
  bio[x] = true;
  REP(i, n) {
    if(e[i][x]) redfs(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  REP(i, n) REP(j, n) cin >> e[i][j];

  REP(i, n) {
    dfs(i);
  }

  memset(bio, 0, sizeof bio);
  redfs(s.top());

  if(uk == n) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}