#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ok = 1;
    for (int i = 0; i < n; i++) {
      int b = a[(i+1)%n];
      if (abs(a[i]-b) != 1 && abs(a[i]-b) != n-1)
	ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}