#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, h, k;
  cin >> w >> h >> k;
  int won = 0;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    if (x-1 < 5 || w-x < 5 || y-1 < 5 || h-y < 5) won = 1;
  }
  cout << (won ? "YES" : "NO") << endl;
}