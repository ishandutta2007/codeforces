#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1; i < 10; i++) {
      for (int j = 1; j <= 4; j++) {
	ans += j;
	if ((pow(10,j)-1)/9*i == x) goto finish;
      }
    }
  finish:
    cout << ans << endl;
  }
}