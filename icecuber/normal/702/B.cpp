#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  map<int,ll> cnt;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  ll ans = 0;
  for (auto p : cnt) {
    int a = p.first;
    int b = 1;
    while (b <= a) b *= 2;
    int r = b-a;
    //cout << a << ' ' << r << endl;
    if (a==r)
      ans += cnt[a]*(cnt[r]-1)/2;
    else
      ans += cnt[a]*cnt[r];

  }
  cout << ans << endl;
}