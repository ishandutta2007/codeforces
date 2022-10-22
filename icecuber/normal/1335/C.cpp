#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int,int> cnt;
    int ma = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ma = max(ma, ++cnt[a]);
    }
    int x = min(ma,(int)cnt.size());
    if (x == ma && x == cnt.size()) x--;
    cout << x << endl;
  }
}