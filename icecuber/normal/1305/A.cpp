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
    vector<int> b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i : a) cout << i << ' ';
    cout << endl;
    for (int i : b) cout << i << ' ';
    cout << endl;
  }
}