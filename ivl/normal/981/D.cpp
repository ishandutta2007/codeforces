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

int n, k;
ll a[55];

ll pref[55];

ll sum(int lo, int hi){return pref[hi+1] - pref[lo];}

int memo[55][55];
ll nec;

bool dp(int id, int bucket){
  if (id == n) return bucket == k;
  if (bucket == k) return false;
  int &r = memo[id][bucket];
  if (r != -1) return r;
  r = 0;
  FOR(i,id,n)
    if ((nec & sum(id, i)) == nec)
      r |= dp(i+1, bucket+1);
  return r;
}

bool check(ll filled){
  memset(memo, -1, sizeof memo);
  nec = filled;
  return dp(0, 0);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  REP(i,n) cin >> a[i];
  REP(i,n) pref[i+1] = pref[i] + a[i];

  ll sol = 0;
  for (int i = 60; i >= 0; --i)
    if (check(sol + (1LL << i)))
      sol += (1LL << i);

  cout << sol << endl;

  return 0;
}