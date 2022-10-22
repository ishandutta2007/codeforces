#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int&v : x) cin >> v;
  int ans = 0;
  set<int> s;
  int a = -1, b = -1;
  vector<int> last = {-1};
  auto Last =
    [&](int a) {
      int j = last.size()-1;
      while (j >= 0 && last[j] == a) j--;
      if (j == -1) return -1;
      else return last[j];
    };
  for (int i = 0; i < n; i++) {
    if (i && x[i] == x[i-1]) {
      ans++;
      continue;
    }

    if (last.empty() || x[i] != last.back())
      last.push_back(x[i]);

    if (x[i] == a) {
      b = Last(a);
      ans++;
      s.clear();
    } else if (x[i] == b) {
      a = Last(b);
      ans++;
      s.clear();
    } else if (s.count(x[i])) {
      ans++;
      a = x[i];
      b = Last(a);
      s.clear();
    } else {
      s.insert(x[i]);
    }
  }
  cout << n-ans << endl;
}