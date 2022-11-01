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

bool pal(string s){
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = (int)s.size();
  int sol = 0;
  REP(i,n) FOR(j,i,n)
    if (!pal(s.substr(i, j-i+1)))
      sol = max(sol, j-i+1);

  cout << sol << endl;

  return 0;
}