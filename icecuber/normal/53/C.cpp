#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i%2) cout << n-i/2 << ' ';
    else cout << i/2+1 << endl;
  }
  cout << endl;
}