//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

int n;
vi a;
const int INF = 1e9;

int check(ll aprev, int r) {
  int ile = 0;
  for(int i=1; i<n; i++) {
    ll anex = aprev + r;
    aprev = anex;
    if(anex == a[i]) continue;
    if(abs(a[i] - anex) <= 1) ile++;
    else return INF;

  }
  return ile;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n;
  a.resize(n);
  for(int i=0; i<n; i++) cin >> a[i];
  if(n <= 2) {
    cout << 0 << "\n";
    return 0;
  }
  int res = INF;
  for(int e1 = -1; e1 <= 1; e1++) {
    for(int e2 = -1; e2 <= 1; e2++) {
      int diff = (a[1] + e2) - (a[0] + e1);
      int e = check(a[0] + e1, diff);
      res = min(res, e + (e1 == 0 ? 0 : 1));
    }
  }
  if(res == INF) res = -1;
  cout << res << "\n";
  return 0;
}