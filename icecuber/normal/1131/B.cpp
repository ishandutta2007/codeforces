#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int pa = 0, pb = 0, ans = 1;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == pa && b == pb) continue;
    int l = max(pa,pb)+(pa==pb), r = min(a,b)-(a==b);
    if (l <= r)
      ans += r+1-l;
    if (a == b) ans++;
    pa = a, pb = b;
  }
  cout << ans << endl;
}