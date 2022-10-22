#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l[100000], r[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  sort(l, l+n);
  sort(r, r+n);
  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += max(l[i], r[i])+1;
  cout << ans << endl;
}