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
  //ios_base::sync_with_stdio(false);

  pii a, b;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cout << max(abs(a.x-b.x), abs(a.y-b.y)) << endl;
  
  return 0;
}