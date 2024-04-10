#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using os_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  os_set<int> ost;
  int n, q;
  cin >> n >> q;
  map<int,int> id;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (!id.count(a)) id[a] = i;
    ost.insert(i);
  }
  int nxt = -1;
  while (q--) {
    int a;
    cin >> a;
    cout << ost.order_of_key(id[a])+1 << endl;
    ost.erase(id[a]);
    ost.insert(id[a] = nxt--);
  }
}