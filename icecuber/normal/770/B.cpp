#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string a;
  cin >> a;
  auto sum = [](string a) {
    ll r = 0;
    for (char c : a) r += c-'0';
    return r;
  };
  pair<ll,ll> ans(sum(a),stoll(a));
  for (int i = 0; i < a.size(); i++) {
    string b = a;
    if (b[i] == '0') continue;
    b[i]--;
    for (int j = i+1; j < a.size(); j++)
      b[j] = '9';
    ans = max(ans, make_pair(sum(b),stoll(b)));
  }
  cout << ans.second << endl;
}