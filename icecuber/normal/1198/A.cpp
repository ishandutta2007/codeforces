#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, I;
  cin >> n >> I;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  ll ans = n-1;
  int j = 0;
  int uniques = 0;
  int maxuniques = 0;
  for (int l = 0; 1<<l <= n*2; l++) {
    if (l*n > 8*I) break;
    maxuniques = 1<<l;
  }
  for (int i = 0; i < n; i++) {
    if (!i || a[i] != a[i-1]) uniques++;
    else assert(0);
    while (i+1 < n && a[i] == a[i+1]) i++;
    while (j < i && uniques > maxuniques) {
      if (j+1 < n && a[j+1] != a[j]) uniques--;
      j++;
    }
    //cout << i << ' ' << j << ' ' << uniques << ' ' << l*n << ' ' << I*8 << endl;
    ans = min(ans, n-1-i+j);
  }
  cout << ans << endl;
}