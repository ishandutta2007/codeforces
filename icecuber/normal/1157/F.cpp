#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  int ans = 1, ansa = 0, start = 0;
  for (int i = 1; i < n; i++) {
    if (i > 1 && a[i-2] < a[i]-1) start = i-1;
    if (a[i-1] < a[i]-1) start = i;
    if (i-start+1 > ans) {
      ans = i-start+1;
      ansa = start;
    }
  }
  cout << ans << endl;
  for (int i = ansa; i < ansa+ans; i += 2)
    cout << a[i] << ' ';
  for (int i = ansa+ans-1-ans%2; i > ansa; i -= 2)
    cout << a[i] << ' ';
  cout << endl;
}