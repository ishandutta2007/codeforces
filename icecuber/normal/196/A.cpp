#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  string ans;
  for (char c : s) {
    while (ans.size() && ans[ans.size()-1] < c) ans.pop_back();
    ans += c;
  }
  cout << ans << endl;
}