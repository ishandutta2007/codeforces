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
typedef pair < int, int > pii;

int n, m;
ll a[100005];
ll b[100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  vector < pair < ll, bool > > v;
  REP(i,n) v.pb({a[i], 0});
  REP(i,m) v.pb({b[i], 1});
  sort(v.begin(), v.end());
  vector < ll > v2(v.size(), 3e9);
  ll ex = -3e9;
  REP(i,v.size())
    if (v[i].y) ex = v[i].x;
    else v2[i] = min(abs(v[i].x - ex), v2[i]);
  ex = 3e9;
  for (int i = (int)v.size(); i >= 0; --i)
    if (v[i].y) ex = v[i].x;
    else v2[i] = min(abs(v[i].x - ex), v2[i]);

  ll r = 0;
  REP(i,v.size()) if (!v[i].y) r = max(r, v2[i]);
  cout << r << endl;

  return 0;
}