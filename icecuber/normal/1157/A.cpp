#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 9;
  while (n > 9) {
    n++;
    while (n%10 == 0) n /= 10;
    ans++;
  }
  cout << ans << endl;
}