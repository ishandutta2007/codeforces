#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  set<char> seen;
  for (char c : s) seen.insert(c);
  char a = *seen.begin();
  if (k > n) {
    for (int i = n; i < k; i++)
      s += a;
  } else {
    s.resize(k);
    for (int i = k-1; i >= 0; i--) {
      auto it = next(seen.find(s[i]));
      if (it == seen.end()) {
	s[i] = a;
	continue;
      }
      s[i] = *it;
      break;
    }
  }
  cout << s << endl;
}