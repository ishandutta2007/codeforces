#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(20);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    for (int j = 0; j < 20; j++)
      cnt[j] += (v>>j&1);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20; j++) {
      if (cnt[j]) {
	a[i] |= 1<<j;
	cnt[j]--;
      }
    }
    ans += (ll)a[i]*a[i];
  }
  cout << ans << endl;
}