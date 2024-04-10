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
typedef pair < int, int > pii;

map < string, int > M = {
  {"monday", 0},
  {"tuesday", 1},
  {"wednesday", 2},
  {"thursday", 3},
  {"friday", 4},
  {"saturday", 5},
  {"sunday", 6}
};

int main(){
  ios_base::sync_with_stdio(false);

  string a, b;
  cin >> a >> b;
  assert(M.count(a));
  assert(M.count(b));
  int aa = M[a], bb = M[b];
  int d = (bb-aa+7)%7;

  vector < int > v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  REP(i,v.size()) if (v[i]%7 == d){cout << "YES\n"; return 0;}
  cout << "NO\n";
  
  return 0;
}