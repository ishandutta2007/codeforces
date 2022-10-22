#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << #x << " = " << (x) << endl;

ll a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k, m;
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  reverse(a,a+n);
  ll sum = 0;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (m >= n-i-1)
      ans = max(ans, (min(m-(n-i-1), k*(i+1))+sum)*1./(i+1));
  }
  cout << setprecision(20) << ans << endl;
}