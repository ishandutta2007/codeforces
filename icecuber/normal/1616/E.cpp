#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using os_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T, class S>
using os_map = tree<T, S, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    string sorted = a;
    sort(sorted.begin(), sorted.end());
    if (sorted >= b) {
      cout << -1 << endl;
      continue;
    }

    ll ans = (ll)n*n;
    ll used = 0;
    os_set<int> added;

    vector<queue<int>> q(26);
    for (int i = 0; i < n; i++) {
      q[a[i]-'a'].push(i);
    }
    for (int cur = 0; cur < n; cur++) {
      for (int c = 0; c < b[cur]-'a'; c++) {
        if (q[c].empty()) continue;
        int i = q[c].front();
        int cost = i - added.order_of_key(i);
        ans = min(ans, used+cost);
      }
      {
        int c = b[cur]-'a';
        if (q[c].empty()) break;
        int i = q[c].front();
        int cost = i - added.order_of_key(i);
        used += cost;
        q[c].pop();
        added.insert(i);
      }
    }
    cout << ans << endl;
  }
}