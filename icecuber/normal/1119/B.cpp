#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (int&i : a) cin >> i;
  int pass = 1, fail = n+1;
  while (fail-pass > 1) {
    int k = pass+fail>>1;
    vector<int> b = a;
    b.resize(k);
    sort(b.rbegin(), b.rend());
    ll need = 0;
    for (int i = 0; i < k; i += 2)
      need += b[i];
    if (need <= h) pass = k;
    else fail = k;
  }
  cout << pass << endl;
}