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

int t;

void check(int n, int m, int x, int y, vi& X) {
  if(not(0 < x and x <= n and 0 < y and y <= m)) return;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) X[abs(i-x) + abs(j-y)]--;
  }
  bool ok = true;
  for(int i=0; i<t; i++) {
    ok &= (X[i] == 0);
  }
  if(ok) {
    cout << n << " " << m << "\n" << x << " " << y << "\n";
    exit(0);
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) X[abs(i-x) + abs(j-y)]++;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> t;
  vi V(t+7), X;
  for(int i=0; i<t; i++) {
    int x;
    cin >> x;
    X.push_back(x);
    V[x]++;
  }
  if(V[0] != 1) {
    cout << -1 << "\n";
    return 0;
  }
  int x=1;
  while(V[x] == 4*x) x++;
  for(int i=1; i<=t; i++) {
    if(t % i == 0) {
      check(i, t/i, x, (i + t/i) - (x + *max_element(X.begin(), X.end())), V);
    }
  }
  cout << -1 << "\n";
  return 0;
}