#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n;
  cin >> s;
  int acc = 0, mi = 0;
  for (int i = 0; i < n; i++) {
    acc += (s[i] == '(')-(s[i] == ')');
    mi = min(mi, acc);
  }
  if (acc || mi < -1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}