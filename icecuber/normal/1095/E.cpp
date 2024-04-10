#include <bits/stdc++.h>
using namespace std;

int good[1000000];
int main() {
  ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  int acc = 0, ok = 1;
  for (int i = 0; i < n; i++) {
    if (acc < 0) ok = 0;
    acc += (s[i] == '(')-(s[i] == ')');
    good[i] = ok;
  }
  ok = 1;
  acc = 0;
  for (int i = n-1; i >= 0; i--) {
    if (acc < 0) ok = 0;
    acc += (s[i] == ')')-(s[i] == '(');
    good[i] &= ok;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (good[i] && acc-2*((s[i] == ')')-(s[i] == '(')) == 0) ans++;
  }
  cout << ans << endl;
}