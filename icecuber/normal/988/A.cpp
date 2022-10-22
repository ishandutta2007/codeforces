#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int,int> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m[a] = i+1;
  }
  if (m.size() < k) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (auto [a, i] : m) {
      k--;
      cout << i << ' ';
      if (!k) break;
    }
    cout << endl;
  }
}