#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, last;
  cin >> n >> last;
  ll ways = 1, open = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int d = a-last;
    if (d == -1) {
      open++;
    } else if (d == 1) {
      (ways *= open--) %= mod;
    } else if (d == 0) {
      (ways *= open+1) %= mod;
    } else ways = 0;
    last = a;
  }
  if (open > 1) ways = 0;
  cout << ways << endl;
}