#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string col = "ROYGBIV";
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i < 7) cout << col[i];
    else cout << col[3+(i-7)%4];
  }
  cout << endl;
}