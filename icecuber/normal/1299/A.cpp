#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> pref(n+1,~0), suf(n+1,~0), a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pref[i+1] = pref[i]&~a[i];
  }
  for (int i = n-1; i >= 0; i--) {
    suf[i] = suf[i+1]&~a[i];
  }
  int ans = -1, maxi = 0;
  for (int i = 0; i < n; i++) {
    int score = pref[i]&suf[i+1]&a[i];
    if (score > ans) {
      ans = score;
      maxi = i;
    }
  }
  cout << a[maxi] << ' ';
  for (int i = 0; i < n; i++)
    if (i != maxi) cout << a[i] << ' ';
  cout << endl;
}