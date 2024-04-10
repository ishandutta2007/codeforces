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
    set<int> s;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
      s.insert(a[i].first);
    }
    sort(a.begin(), a.end());
    int invs = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
	invs += (a[j].second > a[i].second);
      }
    }
    if (invs%2 && (int)s.size() == n) {
      cout << -1 << endl;
      continue;
    }
    if (invs%2) {
      int found = 0;
      for (int i = 0; i+1 < n; i++)
	if (a[i].first == a[i+1].first) {
	  swap(a[i], a[i+1]);
	  found = 1;
	  break;
	}
      assert(found);
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++)
      b[a[i].second] = i;
    vector<int> ans;
    auto cycle = [&](int i) {
      assert(i >= 0 && i+2 < n);
      ans.push_back(i+1);
      int tmp = b[i];
      b[i] = b[i+2];
      b[i+2] = b[i+1];
      b[i+1] = tmp;
    };
    for (int i = n-1; i >= 2; i--) {
      int j = 0;
      while (b[j] != i) j++;
      if (!j) cycle(0), j = 1;
      assert(b[j] == i);
      while (j < i) cycle(j-1), j++, assert(b[j] == i);
    }
    for (int i = 0; i < n; i++)
      assert(b[i] == i);
    assert((int)ans.size() <= n*n);
    cout << ans.size() << endl;
    for (int i : ans)
      cout << i << ' ';
    cout << endl;
  }
}