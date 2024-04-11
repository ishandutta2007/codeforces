#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<char> used(n);

  vector<pair<int,int>> ans;
  queue<int> q;
  q.push(0);
  used[0] = true;
  int done = 0;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    ++done;

    while (a[x]--) {
      int who = -1;
      for (int i = 0; i < n; ++i)
        if (!used[i] && (who == -1 || a[i] > a[who])) {
          who = i;
        }
      if (who == -1) break;
      ans.emplace_back(x + 1, who + 1);
      used[who] = true;
      q.push(who);
    }
  }

  if (done != n) {
    puts("-1");
    return 0;
  }
  cout << ans.size() << endl;
  for (auto c : ans) {
    cout << c.first << " " << c.second << endl;
  }

  return 0;
}