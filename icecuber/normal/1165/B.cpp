#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  int k = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] < k) continue;
    k++;
  }
  cout << k-1 << endl;
}