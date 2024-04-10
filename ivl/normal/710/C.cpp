#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector < int > v[2];
  FOR(i,1,n*n+1) v[i%2].pb(i);

  REP(i,n){
    REP(j,n){
      cout << v[(abs(i-n/2) + abs(j-n/2)) <= n/2].back() << " ";
      v[(abs(i-n/2) + abs(j-n/2)) <= n/2].pop_back();
    } cout << endl;
  }
  
  return 0;
}