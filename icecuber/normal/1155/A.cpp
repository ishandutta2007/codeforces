#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    if (s[i] < s[i-1]) {
      cout << "YES" << endl;
      cout << i << ' ' << i+1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}