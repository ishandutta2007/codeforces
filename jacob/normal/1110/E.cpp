#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int p, int q) {
  while (q) {
    p %= q;
    swap(p, q);
  }
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  if (a[0] != b[0] || a[n-1] != b[n - 1]) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> da(n - 1), db(n - 1);
  int sa = 0, sb = 0, ga = 0, gb = 0;
  for (int i = 0; i < n - 1; ++i) {
    da[i] = abs(a[i] - a[i + 1]);
    db[i] = abs(b[i] - b[i + 1]);
    //sa += abs(a[i] - a[i + 1]);
    //sb += abs(b[i] - b[i + 1]);
    //ga = gcd(ga, abs(a[i] - a[i + 1]));
    //gb = gcd(gb, abs(a[i] - a[i + 1]));
  }
  sort(da.begin(), da.end());
  sort(db.begin(), db.end());
  if (da == db) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}