#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[400];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n*4; i++)
      cin >> a[i];
    sort(a, a+4*n);

    int ok = 1;
    for (int i = 0; i < n*4; i += 2) {
      if (a[i] != a[i+1]) ok = 0;
    }
    ll area = a[0]*a[n*4-1];
    for (int i = 0; i < n; i++) {
      if (a[i*2]*a[n*4-1-i*2] != area) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}