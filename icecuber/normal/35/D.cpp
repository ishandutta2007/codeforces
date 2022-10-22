#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, x;
  cin >> n >> x;
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    ll v;
    cin >> v;
    a.push_back(v*(n-i));
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (x >= a[i]) x -= a[i], ans++;
  cout << ans << endl;
}