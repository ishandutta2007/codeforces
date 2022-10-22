#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for(string&s : a) cin >> s;
  for(string&s : b) cin >> s;
  int q;
  cin >> q;
  while (q--) {
    int y;
    cin >> y;
    y--;
    cout << a[y%n] << b[y%m] << '\n';
  }
}