#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  sort(a, a+n);
  int j = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && a[j] <= a[i]*2) j++;
    ans += j-1-i;
  }
  cout << ans << endl;
}