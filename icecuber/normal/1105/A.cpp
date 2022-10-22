#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll bestt = 0, bestcost = 1e9;
  for (int t = 1; t <= 100; t++) {
    ll cost = 0;
    for (int i = 0; i < n; i++)
      cost += max(abs(a[i]-t)-1,0);
    if (cost < bestcost) {
      bestcost = cost;
      bestt = t;
    }
  }
  cout << bestt << ' ' << bestcost << endl;
}