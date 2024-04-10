#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n*2);
  for (int i = 0; i < n*2; i++)
    cin >> a[i];
  int ans = 0;
  for (int j = 0; j < n*2; j += 2) {
    int v = a[j];
    int k = j+1;
    while (a[k] != v) k++;
    while (k > j+1) swap(a[k], a[k-1]), k--, ans++;
  }
  //for (int v : a) cout << v << ' ';
  //cout << endl;
  cout << ans << endl;
}