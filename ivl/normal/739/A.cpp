#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair < int, int > pii;
typedef long long ll;

int n, m;
pii in[100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,m) cin >> in[i].x >> in[i].y;

  int sol = 1e9;
  REP(i,m) sol = min(sol, in[i].y-in[i].x+1);
  cout << sol << endl;
  REP(i,n) cout << i%sol << " "; cout << endl;

  return 0;
}