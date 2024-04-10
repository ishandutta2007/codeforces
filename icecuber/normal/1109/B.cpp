#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int ok = 0;
  for (int i = 0; i < n/2; i++)
    if (s[i] != s[0]) ok = 1;
  if (!ok) {
    cout << "Impossible" << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    string r = s.substr(i,n-i)+s.substr(0,i);
    string rr = r;
    reverse(rr.begin(), rr.end());
    if (r == rr && r != s) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 2 << endl;
}