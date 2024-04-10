#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " _ " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int a[1005];
int b[1005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];
  sort(a, a+n);
  vector < int > v;
  REP(i,n) if (i%2 == 0) v.pb(i);
  REP(i,n) if (i%2 == 1) v.pb(i);
  REP(i,n) b[v[i]] = a[i];
  REP(i,n) cout << b[i] << " "; cout << endl;
  
  return 0;
}