#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sqr(int n) {
  int s = sqrt(n);
  return s*s == n;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n%2 == 0 && sqr(n/2) || n%4 == 0 && sqr(n/4) ? "YES" : "NO") << endl;
  }
}