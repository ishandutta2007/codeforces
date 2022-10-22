#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  string ans;
  for (int i = 0; i < w-1; i++) ans += 'L';
  for (int i = 0; i < h-1; i++) ans += 'U';
  for (int i = 0; i < h; i++) {
    if (i) ans += 'D';
    for (int j = 0; j < w-1; j++) {
      ans += i%2 == 0 ? 'R' : 'L';
    }
  }
  cout << ans.size() << endl;
  cout << ans << endl;
}