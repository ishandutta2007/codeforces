#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int,int> m, a;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]] = i;
  }
  int turn = 1;
  while (a.size()) {
    int besti = m.rbegin()->second;
    vector<int> to_remove;
    to_remove.push_back(besti);
    auto it = a.find(besti);
    for (int i = 0; i < k; i++) {
      ++it;
      if (it == a.end()) break;
      to_remove.push_back(it->first);
    }
    it = a.find(besti);
    for (int i = 0; i < k; i++) {
      if (it == a.begin()) break;
      --it;
      to_remove.push_back(it->first);
    }
    for (int i : to_remove) {
      m.erase(a[i]);
      a.erase(i);
      ans[i] = turn;
    }
    turn = 3-turn;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i];
  cout << endl;
}