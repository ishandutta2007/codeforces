#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> even, odd;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a%2) odd.push_back(a);
    else even.push_back(a);
  }
  sort(even.rbegin(), even.rend());
  sort(odd.rbegin(), odd.rend());
  int take = min(odd.size(), even.size());
  ll ans = 0;
  for (int i = take+1; i < odd.size(); i++)
    ans += odd[i];
  for (int i = take+1; i < even.size(); i++)
    ans += even[i];
  cout << ans << endl;
}