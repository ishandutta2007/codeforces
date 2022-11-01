#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int main(){

  int n;
  cin >> n;
  vector < int > m(n), r(n);
  REP(i,n) cin >> m[i];
  REP(i,n) cin >> r[i];

  const int Limit = 1e7;
  int cnt = 0;
  REP(d,Limit){
    int bl = 0;
    REP(i,n) if (d%m[i] == r[i]) bl = 1;
    cnt += bl;
  } cout << (double)cnt/Limit << endl;
  
  return 0;
}