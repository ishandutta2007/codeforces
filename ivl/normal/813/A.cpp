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

  int n; cin >> n;
  int sum = 0; REP(i,n){int a; cin >> a; sum += a;}
  int m; cin >> m;
  REP(i,m){int l, r; cin >> l >> r; if (r >= sum){cout << max(l, sum) << endl; return 0;}}
  cout << -1 << endl;

  return 0;
}