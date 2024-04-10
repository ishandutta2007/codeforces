#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fail() {
  cout << "NO" << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  int k;
  cin >> k;
  vector<pair<int,char>> path;
  int j = 0;
  for (int i = 0; i < k; i++) {
    ll v;
    cin >> v;
    int j0 = j;
    while (j < a.size() && v > 0) v -= a[j++];
    if (v) fail();
    if (j-j0 == 1) continue;

    int ma = -1, mas = 0;

    for (int l = j0; l < j; l++) {
      if (a[l] > ma) mas = 0, ma = a[l];
      if (a[l] == ma) mas++;
    }
    if (mas == j-j0) fail();

    int start = -1, dir;
    for (int l = j0; l+1 < j; l++) {
      if ((a[l] == ma) != (a[l+1] == ma)) {
	if (a[l] == ma) start = l, dir = 1;
	else start = l+1, dir = -1;
      }
    }
    assert(start != -1);
    if (dir == 1) {
      for (int l = 0; l < j-start-1; l++)
	path.emplace_back(i+1+start-j0, 'R');
      for (int l = 0; l < start-j0; l++)
	path.emplace_back(i+1+start-j0-l, 'L');
    } else {
      for (int l = 0; l < start-j0; l++)
	path.emplace_back(i+start-j0+1-l, 'L');
      for (int l = 0; l < j-start-1; l++)
	path.emplace_back(i+1, 'R');
    }
  }
  if (j != a.size()) fail();

  cout << "YES" << endl;
  for (auto [p, c] : path)
    cout << p << ' ' << c << endl;
}