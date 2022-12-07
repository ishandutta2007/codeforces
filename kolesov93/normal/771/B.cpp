#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> names;
  for (char c = 'A'; c <= 'Z'; ++c) {
    for (char b = 'a'; b <= 'z'; ++b) {
      string s = "aa";
      s[0] = c; s[1] = b;
      names.push_back(s);
    }
  }

  vector<int> a(n);
  for (int i = 0; i + 1 < k; ++i) {
    a[i] = i;
  }
  for (int i = k - 1; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "YES") {
      a[i] = i;
    } else {
      a[i] = a[i - k + 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << names[a[i]];
    if (i + 1 < n) cout << " ";
  }
  cout << endl;

  return 0;
}