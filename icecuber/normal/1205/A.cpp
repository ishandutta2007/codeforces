#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n%2 == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    if (i%2 == 0) {
      ans[i] = i*2;
      ans[i+n] = i*2+1;
    } else {
      ans[i] = i*2+1;
      ans[i+n] = i*2;
    }
  }
  for (int i = 0; i < n*2; i++)
    cout << ans[i]+1 << ' ';
  cout << endl;
}