//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int32_t(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

#define int long long

int32_t main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  ll v;
  cin >> n >> k >> v;
  vi a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  int possible[n+1][k];
  for(int i=0; i<=n; i++) for(int j=0; j<k; j++) possible[i][j] = -1;
  possible[0][0] = 0;
  for(int i=1; i<=n; i++) {
    int w = a[i-1]%k;
    for(int j=0; j<k; j++) {
      if(possible[i-1][j] != -1) {
        possible[i][j] = j;
        possible[i][(j+w)%k] = j;
      }
    }
  }
  if(possible[n][v%k] == -1) {
    cout << "NO\n";
    return 0;
  }
  int c = v%k;
  vector <int> U[2];
  ll w[2] = {0, 0};
  for(int i=n; i>0; i--) {
    // cerr << possible[i][c] << "\n";
    if(possible[i][c] != c) {
      U[0].push_back(i);
      w[0] += a[i-1];
      c = possible[i][c];
    } else {
      U[1].push_back(i);
      w[1] += a[i-1];
    }
  }
  // cerr << w[0] << " " << w[1] << "\n";
  vector <tuple <int, int, int> > com;
  // cerr << SZ(U[0]) << " " << SZ(U[1]) << "\n";
  for(int u=0; u<2; u++) {
    if(U[u].empty()) continue;
    for(int i=1; i<SZ(U[u]); i++) {
      com.emplace_back(1e9, U[u][i], U[u][0]);
    }
  }
  if(U[0].empty()) {
    U[0].push_back(U[1].back());
    U[1].pop_back();
  }
  if(U[1].empty()) {
    U[1].push_back(U[0].back());
    U[0].pop_back();
  }
  assert(w[0] % k == v % k);
  if(w[0] > v) {
    ll zaduzo = w[0] - v;
    assert(zaduzo % k == 0);
    com.emplace_back(zaduzo/k, U[0][0], U[1][0]);
  } else if(w[0] < v) {
    ll zamalo = v - w[0];
    if(zamalo > w[1]) {
      cout << "NO\n";
      return 0;
    }
    com.emplace_back(zamalo/k, U[1][0], U[0][0]);
    assert(zamalo/k*k + w[0] == v);
    assert(zamalo/k*k <= w[1]);
  }
  assert(SZ(com) <= n+5);
  cout << "YES\n";
  for(auto x : com) {
    cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
  }
  return 0;
}