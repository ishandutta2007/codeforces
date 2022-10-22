#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  sort(x, x+n);
  int j = 0, ans = 1e9;
  for (int i = 0; i < n; i++) {
    while (x[i]-x[j] > d) j++;
    ans = min(ans, n-(i-j+1));
  }
  cout << ans << endl;
}