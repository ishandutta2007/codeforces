#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+10;
int a[2][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  int bads = 0;
  while (q--) {
    int r, c;
    cin >> r >> c;
    r--;
    bads -= a[r][c]*(a[!r][c-1]+a[!r][c]+a[!r][c+1]);
    a[r][c] ^= 1;
    bads += a[r][c]*(a[!r][c-1]+a[!r][c]+a[!r][c+1]);
    cout << (bads ? "No" : "Yes") << '\n';
  }
}