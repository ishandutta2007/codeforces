#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string r;
    for (char c : s) {
      if (r.size() && c == 'B') r.pop_back();
      else r += c;
    }
    cout << r.size() << endl;
  }
}