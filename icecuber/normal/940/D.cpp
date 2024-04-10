#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  string b;
  cin >> b;
  for (char&c : b) c -= '0';
  int l = -1e9-1, r = 1e9+1;
  for (int i = 4; i < n; i++) {
    if (b[i] == 1 && b[i-1]+b[i-2]+b[i-3]+b[i-4] == 0) {
      l = max({l, a[i],a[i-1],a[i-2],a[i-3],a[i-4]});
    }
    if (b[i] == 0 && b[i-1]+b[i-2]+b[i-3]+b[i-4] == 4) {
      r = min({r, a[i],a[i-1],a[i-2],a[i-3],a[i-4]});
    }
  }
  cout << l+1 << ' ' << r-1 << endl;
}