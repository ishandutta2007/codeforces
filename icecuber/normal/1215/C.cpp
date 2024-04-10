#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string a, b;
  cin >> n >> a >> b;
  vector<int> ab, ba;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'a' && b[i] == 'b')
      ab.push_back(i);
    if (a[i] == 'b' && b[i] == 'a')
      ba.push_back(i);
  }
  if (ab.size()+ba.size()&1) {
    cout << -1 << endl;
    return 0;
  }
  cout << ab.size()/2+ba.size()/2+ab.size()%2*2 << '\n';
  while (ab.size() > 1) {
    int x = ab.back();
    ab.pop_back();
    int y = ab.back();
    ab.pop_back();
    cout << x+1 << ' ' << y+1 << '\n';
  }
  while (ba.size() > 1) {
    int x = ba.back();
    ba.pop_back();
    int y = ba.back();
    ba.pop_back();
    cout << x+1 << ' ' << y+1 << '\n';
  }
  if (ab.size()) {
    int x = ab[0], y = ba[0];
    cout << x+1 << ' ' << x+1 << '\n';
    cout << x+1 << ' ' << y+1 << '\n';
  }
}