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

void solve(){

  int n, r;
  cin >> n >> r, --r;
  int sol = r;
  REP(i,n-1){int a; cin >> a, --a; sol -= a;}
  sol %= n;
  if (sol < 0) sol += n;
  cout << sol+1 << endl;
  
}

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  REP(i,t) solve();

  return 0;
}