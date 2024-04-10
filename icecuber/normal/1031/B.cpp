#include <bits/stdc++.h>
using namespace std;

void fail() {
  cout << "NO" << endl;
  exit(0);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n),b(n),t(n);
  for (int i = 1; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) cin >> b[i];
  for (int t0 = 0; t0 < 4; t0++) {
    t[0] = t0;
    int ok = 1;
    for (int i = 1; i < n; i++) {
      if (b[i] > a[i]) fail();
      t[i] = t[i-1]^(a[i]-b[i]);
      if (a[i] != (t[i]|t[i-1]) || b[i] != (t[i]&t[i-1])) ok = 0;
    }
    if (ok) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++)
	cout << t[i] << ' ';
      cout << endl;
      return 0;
    }
  }
  fail();
}