#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int b = ceil(sqrt(n));
  for (int i = b-1; i >= 0; i--) {
    for (int j = 0; j < n; j += b)
      if (i+j < n) cout << i+j+1 << ' ';
  }
  cout << endl;
}