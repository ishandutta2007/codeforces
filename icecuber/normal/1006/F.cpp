#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A[20][20];
vector<ll> va[20], vb[20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  ll k;
  cin >> h >> w >> k;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> A[i][j];
  int a = w+h-2>>1, b = w+h-1>>1;

  for (int i = 0; i < 1<<a; i++) {
    int x = 0, y = 0;
    ll v = k;
    for (int j = 0; j < a; j++) {
      if (x < w && y < h) {
	v ^= A[y][x];
      }
      x += (i>>j&1);
      y +=!(i>>j&1);
    }
    if (x < w)
      va[x].push_back(v);
  }

  for (int i = 0; i < 1<<b; i++) {
    int x = w-1, y = h-1;
    ll v = A[y][x];
    for (int j = 0; j < b; j++) {
      x -= (i>>j&1);
      y -=!(i>>j&1);
      if (x >= 0 && y >= 0) {
	v ^= A[y][x];
      }
    }
    if (x >= 0)
      vb[x].push_back(v);
  }
  ll ans = 0;
  for (int i = 0; i < w; i++) {
    sort(va[i].begin(), va[i].end());
    for (ll v : vb[i]) {
      ans +=
	upper_bound(va[i].begin(), va[i].end(), v)-
	lower_bound(va[i].begin(), va[i].end(), v);
    }
  }
  cout << ans << endl;
}