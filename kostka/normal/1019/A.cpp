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
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vi X[m];
  for(int i=0; i<n; i++) {
    int p, c;
    cin >> p >> c;
    X[p-1].push_back(c);
  }
  for(int i=0; i<m; i++) sort(ALL(X[i]));
  ll ret = 1e18;
  for(int i=0; i<=n; i++) {
    ll tmp = 0;
    int dod = 0;
    vi rest;
    for(int j=1; j<m; j++) {
      for(int k=0; k<SZ(X[j]); k++) {
        if(i + k < SZ(X[j])) {
          tmp += X[j][k];
          dod++;
        }
        else rest.push_back(X[j][k]);
      }
    }
    sort(ALL(rest));
    int mam = SZ(X[0]) + dod;
    for(int k=0; k<SZ(rest); k++) {
      if(mam <= i) {
        tmp += rest[k];
        mam++;
      }
    }
    if(mam <= i) continue;
    ret = min(ret, tmp);
  }
  cout << ret << "\n";
  return 0;
}