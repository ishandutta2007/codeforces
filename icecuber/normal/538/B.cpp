#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> r;
  while (n) {
    int m = n;
    int a = 0, mul = 1;
    while (m) {
      int d = m%10;
      if (d) a += mul;
      m /= 10;
      mul *= 10;
    }
    n -= a;
    r.push_back(a);
  }
  cout << r.size() << endl;
  for (int i : r) cout << i << ' ';
  cout << endl;
}