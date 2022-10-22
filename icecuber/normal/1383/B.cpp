#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int win = 0;
    for (int i = 29; i >= 0; i--) {
      int cnt = 0;
      for (int v : a) cnt += (v>>i&1);
      if (cnt%2) {
	win = (cnt/2%2 == 0 || n%2 == 0 ? 1 : -1);
	break;
      }
    }
    if (win == 0) cout << "DRAW" << endl;
    else if (win == 1) cout << "WIN" << endl;
    else cout << "LOSE" << endl;
  }
}