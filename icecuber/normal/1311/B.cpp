#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), p(m);
    for (int&v : a) cin >> v;
    for (int&v : p) cin >> v, v--;
    vector<int> s = a;
    sort(s.begin(), s.end());

    for (int it = 0; it < 1000; it++) {
      for (int i : p) if (a[i+1] < a[i]) swap(a[i],a[i+1]);
    }
    cout << (s == a ? "YES" : "NO") << endl;
  }
}