#line 1 "codeforces-workspace/contest/1450/a/a.cpp"
/*
 * @file template.cpp
 * @brief Template
 */

#include <bits/extc++.h>

int main() {
  using namespace std;
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    sort(begin(s), end(s));
    cout << s << endl;
  }
}