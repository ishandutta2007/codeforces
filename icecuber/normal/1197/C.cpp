#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int last;
  cin >> last;
  vector<int> d;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    d.push_back(a-last);
    last = a;
  }
  sort(d.rbegin(), d.rend());
  int ans = 0;
  for (int i = k-1; i < n-1; i++)
    ans += d[i];
  cout << ans << endl;
}