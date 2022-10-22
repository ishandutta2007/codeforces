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
    int ma = 0;
    for (int k = 0; k < 7; k++) {
      vector<int> part[2];
      for (int i = 0; i < n; i++)
	part[i>>k&1].push_back(i);
      if (part[0].empty() || part[1].empty()) continue;
      cout << part[0].size() << ' ' << part[1].size();
      for (int i : part[0]) cout << ' ' << i+1;
      for (int i : part[1]) cout << ' ' << i+1;
      cout << endl;
      int ans;
      cin >> ans;
      ma = max(ma, ans);
    }
    cout << -1 << ' ' << ma << endl;
  }
}