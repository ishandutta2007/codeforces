#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int k = 1e9+10;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    k = min(k, a/max(i, n-1-i));
  }
  cout << k << endl;
}