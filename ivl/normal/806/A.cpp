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

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  REP(ttt,t){
    int x, y, p, q;
    cin >> x >> y >> p >> q;

    if (p == q){
      if (x == y) cout << 0 << endl;
      else cout << -1 << endl;
      continue;
    }

    if (p == 0){
      if (x == 0) cout << 0 << endl;
      else cout << -1 << endl;
      continue;
    }

    ll lambda = max(max((p+x-1) / p, (q+y-1) / q), (y-x+q-p-1)/(q-p));
    // TRACE(lambda);
    cout << lambda*q - y << endl;
  }

  return 0;
}