#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string mirror(string s) {
  string r = s;
  reverse(r.begin(), r.end());
  return s+r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 1;
    while (i < n && s[i] <= s[i-1]) i++;
    auto r = s.substr(0,i);
    cout << min(mirror(r), mirror(string(1,r[0]))) << endl;
  }
}