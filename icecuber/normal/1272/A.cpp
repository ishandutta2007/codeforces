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
    int ans = abs(a-b)+abs(b-c)+abs(c-a);
    for (int i = -1; i < 2; i++)
      for (int j = -1; j < 2; j++)
	for (int k = -1; k < 2; k++) {
	  int A = a+i, B = b+j, C = c+k;
	  ans = min(ans, abs(A-B)+abs(B-C)+abs(C-A));
	}
    cout << ans << endl;
  }
}