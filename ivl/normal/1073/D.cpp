#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
ll t;
int a[200005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> t;
  REP(i,n) cin >> a[i];

  ll sol = 0;
  
  while (true){
    ll rnd = 0;
    int cnt = 0;
    REP(i,n) if (a[i] <= t) rnd += a[i], ++cnt;
    if (cnt == 0) break;
    sol += t/rnd * cnt;
    t %= rnd;
    REP(i,n) if (a[i] <= t) t -= a[i], ++sol;
  }

  cout << sol << endl;

  return 0;
}