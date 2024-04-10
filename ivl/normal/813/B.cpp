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

vector<ll> pots(ll x){
  double tmp = 1;
  ll xx = 1;
  vector<ll> sol;
  while (true){
    if (tmp > 2e18) break;
    sol.pb(xx);
    tmp *= (double)x;
    xx *= x;
  } return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  ll x, y, l, r;
  cin >> x >> y >> l >> r;

  vector<ll> all = {l-1, r+1};
  vector<ll> pa = pots(x), pb = pots(y);
  for (auto xx : pa)
    for (auto yy : pb)
      if (l <= xx+yy && xx+yy <= r)
	all.pb(xx+yy);

  sort(all.begin(), all.end());

  ll sol = 0;
  REP(i,all.size()-1) sol = max(sol, all[i+1]-all[i]-1);
  cout << sol << endl;

  return 0;
}