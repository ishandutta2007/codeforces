#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int B = 50;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  int ans = 0;
  for (int d = -B; d <= B; d++) {
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
      ans = max(ans, ++cnt[a[i]-d*i]);
    }
  }

  for (int i = 0; i < n; i++) {
    map<int,int> cnt;
    for (int j = i+1; j-i <= int(1e5)/B && j < n; j++) {
      int d = a[j]-a[i];
      if (d%(j-i)) continue;
      d /= j-i;
      ans = max(ans, ++cnt[d]+1);
    }
  }

  cout << n-ans << endl;
}