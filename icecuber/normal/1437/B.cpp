#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int eqs = 0;
    for (int i = 1; i < n; i++) {
      eqs += s[i] == s[i-1];
    }
    cout << (eqs+1)/2 << endl;
  }
}