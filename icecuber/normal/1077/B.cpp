#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i >= 2 && a[i] && !a[i-1] && a[i-2])
      a[i]--, ans++;
  }
  cout << ans << endl;
}