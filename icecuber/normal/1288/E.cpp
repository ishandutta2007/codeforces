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
  int n, q;
  cin >> n >> q;
  os_map<int,int> pos;
  vector<int> t(n), mi(n), ma(n);
  for (int i = 0; i < n; i++) {
    t[i] = mi[i] = ma[i] = i;
    pos[t[i]] = i;
  }
  for (int k = -1; k >= -q; k--) {
    int i;
    cin >> i;
    i--;
    ma[i] = max(ma[i], (int)pos.order_of_key(t[i]));
    mi[i] = 0;
    pos.erase(t[i]);
    t[i] = k;
    pos[t[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    ma[i] = max(ma[i], (int)pos.order_of_key(t[i]));
    cout << mi[i]+1 << ' ' << ma[i]+1 << '\n';
  }
}