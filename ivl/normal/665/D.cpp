#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int erat[2000005];

int n;
int a[1005];

bool good(vector < int > v){
  REP(i,v.size()) REP(j,i) if (erat[v[i]+v[j]] != v[i]+v[j]) return false;
  return true;
}

int main(){

  FOR(i,2,2000005)
    if (erat[i] == 0)
      for (int j = i; j < 2000005; j += i)
	erat[j] = i;

  cin >> n;
  REP(i,n) cin >> a[i];
  sort(a, a+n);

  int poin = 0;
  while (poin < n && a[poin] == 1) ++poin;

  vector < int > sol(poin, 1);
  FOR(i,poin,n) if (good({1, a[i]})){sol.pb(a[i]); break;}
  if (sol.empty()) sol.pb(a[0]);

  REP(i,n) REP(j,i) if (erat[a[i]+a[j]] == a[i]+a[j]){
    if (sol.size() < 2) sol = {a[i], a[j]};
    break;
  }

  cout << sol.size() << endl;
  for (auto t : sol) cout << t << " "; cout << endl;

  return 0;
}