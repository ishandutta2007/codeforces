#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int c[300005];

int output[300005];

int main(){

  cin >> n >> k;
  REP(i,n) cin >> c[i];

  set<int> S;
  REP(i,n) S.insert(i+k);

  set<pii> Sp;
  REP(i,n) Sp.insert({-c[i], i});

  for (auto p : Sp){
    int i = p.y;
    auto it = S.lower_bound(i);
    output[i] = *it;
    S.erase(it);
  }

  ll sol = 0;
  REP(i,n) sol += (ll)c[i] * (output[i]-i);

  cout << sol << endl;
  REP(i,n) cout << output[i]+1 << " "; cout << endl;

  return 0;
}