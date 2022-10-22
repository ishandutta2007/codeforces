#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int acc = 0, ans = 0;
  for (char c : s) {
    int v = (c=='(')-(c==')');
    if (acc+v >= 0)
      acc += v, ans++;
  }
  cout << ans-acc << endl;
}