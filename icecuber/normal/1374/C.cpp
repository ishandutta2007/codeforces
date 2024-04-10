#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int balance = 0, mi = 0;
    for (char c : s) {
      balance += (c == '(')*2-1;
      mi = min(mi, balance);
    }
    assert(!balance);
    cout << -mi << endl;
  }
}