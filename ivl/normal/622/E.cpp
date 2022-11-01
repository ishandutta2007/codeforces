#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
vector < int > E[1000005];

vector < int > V;
void dfs(int id, int p, int d){
  if (E[id].size() == 1) V.pb(d);
  for (auto x : E[id]) if (x != p) dfs(x, id, d+1);
}

int main(){
  cin >> n;
  REP(i,n-1){
    int x, y;
    scanf("%d%d", &x, &y);
    E[x].pb(y), E[y].pb(x);
  }

  int R = 0;
  for (auto x : E[1]){
    V.clear();
    dfs(x, 1, 1);
    sort(V.begin(), V.end());
    int curr = -100, cnt = 0;
    for (auto t : V){
      if (t > curr){
	cnt -= t-curr;
	curr = t;
	if (cnt < 0) cnt = 0;
      } ++cnt;
    } R = max(R, curr+cnt-1);
  } cout << R << endl;
  
  return 0;
}