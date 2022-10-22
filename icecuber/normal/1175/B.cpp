#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  long double ans = 0, mul = 1;
  stack<int> st;
  while (t--) {
    string s;
    cin >> s;
    if (s == "add") {
      ans += mul;
    } else if (s == "end") {
      mul /= st.top();
      st.pop();
    } else if (s == "for") {
      int v;
      cin >> v;
      if (mul > 1e10) v = 1;
      st.push(v);
      mul *= v;
    } else assert(0);
  }
  if (ans > (1ll<<32)-1)
    cout << "OVERFLOW!!!" << endl;
  else cout << ll(ans) << endl;
}