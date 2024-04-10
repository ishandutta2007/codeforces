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

const int MAX = 2e5+5;

int n, x, y;
vector<int> E[MAX];
int dx[MAX];
int dy[MAX];

void dist(int id, int p, int d, int *s){
  s[id] = d;
  for (auto t : E[id])
    if (t != p)
      dist(t, id, d+1, s);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> x; y = 1;
  REP(i,n-1){int a, b; cin >> a >> b; E[a].pb(b); E[b].pb(a);}

  dist(x, x, 0, dx);
  dist(y, y, 0, dy);

  int sol = 2;
  FOR(i,1,n+1)
    if (dx[i] < dy[i])
      sol = max(sol, 2*dy[i]);

  cout << sol << endl;

  return 0;
}