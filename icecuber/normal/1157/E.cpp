#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    s.insert(v);
  }
  for (int i = 0; i < n; i++) {
    int t = (n-a[i])%n;
    auto it = s.lower_bound(t);
    if (it == s.end()) it = s.begin();
    cout << (a[i]+*it)%n << ' ';
    s.erase(it);
  }
  cout << endl;
}