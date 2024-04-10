#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
int a[nax], b[nax];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string big, small;
  cin >> big >> small;
  int ans = 0;
  int j = 0;
  for (int i = 0; i < small.size(); i++) {
    while (big[j] != small[i]) j++;
    a[i] = j++;
  }
  ans = max(ans, (int)big.size()-j);
  j = (int)big.size()-1;
  for (int i = (int)small.size()-1; i >= 0; i--) {
    while (big[j] != small[i]) j--;
    b[i] = j--;
  }
  ans = max(ans, j+1);
  for (int i = 0; i+1 < small.size(); i++) {
    ans = max(ans, b[i+1]-a[i]-1);
  }
  cout << ans << endl;
}