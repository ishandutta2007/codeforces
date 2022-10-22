#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int d[] = {100,20,10,5,1};
  int ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < 5; i++) {
    ans += n/d[i];
    n %= d[i];
  }
  cout << ans << endl;
}