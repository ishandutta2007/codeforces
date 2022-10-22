#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> query(int l, int r) {
  cout << "? " << l+1 << ' ' << r << endl;
  int x, f;
  cin >> x;
  assert(x != -1);
  cin >> f;
  return {x,f};
}

const int nax = 2e5;
int ans[nax];

void solve(int l, int r, int px, int pf) {
  if (l >= r) return;
  if (px == -1) {
    tie(px, pf) = query(l, r);
  }
  assert(pf <= r-l);
  if (pf == r-l) {
    for (int i = l; i < r; i++) {
      ans[i] = px;
    }
    return;
  }
  auto [x, f] = query(l, l+pf);
  if (x == px) {
    int s = l+pf-f;
    for (int i = s; i < s+pf; i++) {
      ans[i] = px;
    }
    solve(l, s, -1, -1);
    solve(s+pf, r, -1, -1);
  } else {
    solve(l, l+pf, x, f);
    int s = -1;
    for (int i = l; i < l+pf; i++) {
      if (ans[i] == px) {
	s = i;
	break;
      }
    }
    if (s != -1) {
      for (int i = s; i < s+pf; i++)
	ans[i] = px;
      solve(s+pf, r, -1, -1);
    } else {
      solve(l+pf, r, px, pf);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  solve(0, n, -1, -1);
  cout << "!";
  for (int i = 0; i < n; i++)
    cout << ' ' << ans[i];
  cout << endl;
}