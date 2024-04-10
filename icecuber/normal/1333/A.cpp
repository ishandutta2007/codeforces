#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
	cout << (i == 0 && j == 0 ? "W" : "B");
      cout << endl;
    }
  }
}