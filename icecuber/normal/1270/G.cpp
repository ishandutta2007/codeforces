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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = i-a[i];
    }
    int p = 0;
    for (int i = 0; i < n; i++) p = a[p];

    int s = p;
    vector<int> path;
    do {
      path.push_back(p);
      p = a[p];
    } while (p != s);
    cout << path.size() << '\n';
    for (int i : path) cout << i+1 << ' ';
    cout << '\n';
  }
}