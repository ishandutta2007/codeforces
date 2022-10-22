#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  string ans;
  int depth = 0;
  for (char c : s) {
    ans += (depth%2 == (c==')'))+'0';
    depth += (c=='(')-(c==')');
  }
  cout << ans << endl;
}