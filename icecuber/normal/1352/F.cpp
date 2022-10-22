#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    string ans;
    if (a+b == 0) {
      for (int i = 0; i < c+1; i++)
	ans += '1';
    } else if (b+c == 0) {
      for (int i = 0; i < a+1; i++)
	ans += '0';
    } else {
      assert(b);
      for (int i = 0; i < a+1; i++)
	ans += '0';
      for (int i = 0; i < c+1; i++)
	ans += '1';
      for (int i = 0; i < b-1; i++) {
	ans += '0'+i%2;
      }
    }
    cout << ans << endl;
  }
}