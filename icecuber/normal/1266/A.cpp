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
    int sum = 0, zeros = 0, evens = 0;
    for (char c : s) {
      int d = c-'0';
      sum += d;
      if (!d) zeros++;
      evens += d%2 == 0;
    }
    cout << (zeros == s.size() || zeros && sum%3 == 0 && evens > 1 ? "red" : "cyan") << endl;
  }
}