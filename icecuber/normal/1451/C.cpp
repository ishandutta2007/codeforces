#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ok = 1;
    for (int i = 0; i < n && ok; i++) {
      while (a[i] < b[i]) {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        if ((j-i)%k) { ok = 0; break; }
        for (int l = i; l < j; l++)
          a[l]++;
      }
    }
    ok &= a==b;
    cout << (ok ? "Yes" : "No") << endl;
  }
}