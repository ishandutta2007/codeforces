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

int n;
int b[4005];

int cnt[4005];

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  REP(i,n) cin >> b[i];

  vector < int > sazm(b, b+n);
  sort(sazm.begin(), sazm.end());
  sazm.erase(unique(sazm.begin(), sazm.end()), sazm.end());
  REP(i,n) b[i] = (int)(lower_bound(sazm.begin(), sazm.end(), b[i])-sazm.begin());

  int r = 0;
  REP(i,n){
    vector < set < int > > VS;
    FOR(j,i,n)
      if (b[i] == b[j]) VS.pb({});
      else VS.back().insert(b[j]);
    memset(cnt, 0, sizeof cnt);
    REP(j,VS.size()) for (auto t : VS[j]) cnt[t] += 1 + (j != (int)VS.size()-1);
    REP(j,n+1) r = max(r, cnt[j]+1);
    r = max(r, (int)VS.size());
  } cout << r << endl;
  
  return 0;
}