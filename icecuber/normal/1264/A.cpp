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
    int last = -1;
    vector<int> streak = {};
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      if (p == last) streak.back()++;
      else {
	streak.push_back(1);
      }
      last = p;
    }
    ll x = 1, golds = streak[0], silvers = 0, bronzes = 0;
    while (x < streak.size() && silvers <= golds) {
      silvers += streak[x++];
    }
    while (x < streak.size() && (golds+silvers+bronzes+streak[x])*2 <= n) {
      bronzes += streak[x++];
    }
    if (silvers <= golds || bronzes <= golds || (golds+silvers+bronzes)*2 > n) {
      cout << "0 0 0" << endl;
    } else {
      cout << golds << ' ' << silvers << ' ' << bronzes << endl;
    }
  }
}