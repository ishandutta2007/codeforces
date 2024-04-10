#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  if (count(s.begin(), s.end(), '0')*2 == s.size()) {
    cout << 2 << endl;
    cout << s[0] << ' ' << s.substr(1,n-1) << endl;
  } else {
    cout << 1 << endl;
    cout << s << endl;
  }
}