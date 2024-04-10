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

const int MAXN = 2e5+5;

int n;
ll c;

ll s[2*MAXN];
ll pref[2*MAXN];

ll sum(int lo, int hi){
  assert(lo <= hi);
  return pref[2*hi+1] - pref[2*lo];
}

ll _monic[MAXN];
ll *monic = _monic+1;

ll f(int id){return -(monic[id-1] - sum(0, n-1) + sum(id, n-1));}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> c;
  REP(i,2*n-1) cin >> s[i];

  pref[0] = 0;
  REP(i,2*n-1) pref[i+1] = pref[i]+s[i];

  monic[-1] = 0;

  int low = 0;
  set<pair<ll, int>> S;
  REP(i,n){
    S.insert({f(i), i});
    for (; low <= i && sum(low, i) >= c; ++low)
      S.erase({f(low), low});
    if (low) monic[i] = monic[low-2] + min(c, sum(low-1, i));
    else monic[i] = min(c, sum(0, i));
    if (!S.empty()){
      int x = S.begin()->y;
      monic[i] = max(monic[i], monic[x-1] + min(c, sum(x, i)));
    }
  }

  cout << monic[n-1] << endl;

  return 0;
}