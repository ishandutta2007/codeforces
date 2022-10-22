#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int L, v, x, y;
    cin >> L >> v >> x >> y;
    cout << L/v-y/v+(x-1)/v << endl;
  }
}