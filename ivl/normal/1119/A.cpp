#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define x first
#define y second
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

int solve(vector<int> v){
  REP(i,v.size()) if (v[i] != v.back()) return i;
  assert(false);
}

int main(){

  int n;
  cin >> n;
  vector<int> c(n);
  REP(i,n) cin >> c[i];

  int bla = solve(c);
  reverse(c.begin(), c.end());
  int truc = solve(c);

  if (bla < truc) cout << n-1-bla << endl;
  else cout << n-1-truc << endl;

  return 0;
}