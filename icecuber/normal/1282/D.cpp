#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(string s) {
  cout << s << endl;
  int ans;
  cin >> ans;
  if (ans <= 0) exit(0);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string as, bs;
  for (int i = 0; i < 300; i++) as += "a", bs += "b";
  int na = 300-query(as);
  int nb = 300-query(bs);
  int n = na+nb;
  string ans = as.substr(0,n);
  if (!nb) {
    query(ans);
    assert(0);
  }
  int expect = nb;
  for (int i = 0; i < n; i++) {
    ans[i] = 'b';
    int q = query(ans);
    if (q < expect) {
      expect = q;
    } else {
      ans[i] = 'a';
    }
  }
  assert(0);
}