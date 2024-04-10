#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using os_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


struct Rat {
  ll p, q;
};

bool operator<(Rat a, Rat b) {
  if (a.q < 0) a.p *= -1, a.q *= -1;
  if (b.q < 0) b.p *= -1, b.q *= -1;
  return a.p*b.q < b.p*a.q;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll w;
  cin >> n >> w;
  vector<pair<Rat,Rat>> a;
  for (int i = 0; i < n; i++) {
    ll x, v;
    cin >> x >> v;
    a.push_back({{w+v,x},{w-v,x}});
  }
  sort(a.begin(), a.end());
  os_set<pair<Rat,int>> ost;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += ost.order_of_key({a[i].second, 1e9});
    ost.insert({a[i].second, i});
  }
  cout << ans << endl;
}