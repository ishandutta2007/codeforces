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
typedef pair<int, int> pii;

const int oo = 1e9;
const ll ool = (ll)oo * oo;

int n, l;
ll c[33];

ll eval(int x){
  ll sol = 0;
  for (int i = 0; x; x /= 2, ++i)
    if (x&1)
      sol += c[i];
  return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> l;
  REP(i,n) cin >> c[i];
  for (int i = n-1; i > 0; --i)
    c[i-1] = min(c[i-1], c[i]);
  FOR(i,n,31) c[i] = ool;
  REP(i,30) c[i+1] = min(c[i+1], 2*c[i]);

  ll sol = ool;
  while (true){
    sol = min(sol, eval(l));
    if (__builtin_popcount(l) == 1) break;
    l += l & -l;
  }

  cout << sol << endl;

  return 0;
}