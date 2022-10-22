#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  if (w == 1 && h == 1) {
    cout << 0 << endl;
  } else if (w == 1) {
    for (int i = 2; i <= h+1; i++)
      cout << i << endl;
    cout << endl;
  } else {
    for (int i = 1; i <= h; i++) {
      for (int j = h+1; j <= w+h; j++) {
	cout << i*j << ' ';
      }
      cout << endl;
    }
  }
}