#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int p[100005];

vector<int> E[100005];

bool cnt[100005];

void dfs(int id, int dep){
  cnt[dep] = !cnt[dep];
  for (auto t : E[id]) dfs(t, dep+1);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  FOR(i,2,n+1) cin >> p[i];

  FOR(i,2,n+1) E[p[i]].pb(i);

  dfs(1, 0);

  int sol = 0;
  for (auto t : cnt) sol += t;
  cout << sol << endl;

  return 0;
}