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

void fin(int x){
  cout << x << endl;
  exit(0);
}

int n, a, b, t;
string s;

int pref[1<<19];

int val(int x, int y){
  int r = 0;
  r += x+y;
  r += pref[x]*b;
  r += b*(pref[n]-pref[n-y]);
  r += a*(x+y-1);
  r += a*min(x-1,y);
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> a >> b >> t;
  cin >> s;

  int cnt = 0;
  for (auto c : s) if (c == 'w') ++cnt;
  if (n + cnt*b + (n-1)*a <= t) fin(n);

  REP(i,n) if (s[i] == 'w') pref[i+1] = 1;
  FOR(i,1,1<<19) pref[i] += pref[i-1];

  int r = 0;
  int p1 = n, p2 = 0;
  while (p1){
    if (val(p1, p2) > t){--p1; continue;}
    while (val(p1, p2) <= t) ++p2;
    r = max(r, p1+p2-1);
    --p1;
  } fin(r);
  
  return 0;
}