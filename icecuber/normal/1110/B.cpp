#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int prev;
  cin >> prev;
  for (int i = 0; i < n-1; i++) {
    int x;
    cin >> x;
    d[i] = x-prev-1;
    prev = x;
  }
  sort(d, d+n-1);
  int ans = n;
  for (int i = 0; i < n-k; i++)
    ans += d[i];
  cout << ans << endl;
}