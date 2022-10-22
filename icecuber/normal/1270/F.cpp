#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a(n+1);
  for (int i = 0; i < n; i++) {
    a[i+1] = a[i]+(s[i] == '1');
  }
  vector<int> nxt(n+1);
  nxt[n] = n;
  int cur = n;
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '1') cur = i;
    nxt[i] = cur;
  }

  int B = 100;
  ll ans = 0;
  for (int k = 1; k < B; k++) {
    map<int,int> m;
    for (int i = 0; i <= n; i++) {
      ans += m[a[i]*k-i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    int j = nxt[i]+1, d = 1;
    while (j <= n && i+d*B <= n) {
      int nj = nxt[j]+1;
      int id = i%d;
      int ma1 = (nj-1-id)/d, ma2 = (max(j,i+B*d)-1-id)/d;
      ans += max(ma1-ma2, 0);
      //cout << i << ' ' << j << ' ' << d << ' ' << a[i] << ' ' << a[j] << endl;
      //assert(a[j]-a[i] == d);
      //assert(a[nj-1]-a[i] == d);
      j = nj;
      d++;
    }
  }
  cout << ans << endl;
}