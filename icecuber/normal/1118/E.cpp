#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  if (n > k*(k-1)) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < k; i++) {
    for (int j = i+1; j < k; j++) {
      cout << i+1 << ' ' << j+1 << endl;
      if (!--n) return 0;
      cout << j+1 << ' ' << i+1 << endl;
      if (!--n) return 0;
    }
  }
}