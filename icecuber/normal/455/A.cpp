#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> c(1e5+1,0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a]++;
  }
  ll picked = 0, ok = 0;
  for (int i = 0; i <= 1e5; i++) {
    tie(ok, picked) = make_pair(picked, max(picked, ok+c[i]*i));
  }
  cout << max(picked, ok) << endl;
}