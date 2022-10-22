#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mi(int n) {
  int r = 0;
  for (int i = 0; n; i++) {
    int take = min(1<<i,n);
    n -= take;
    r += i*take;
  }
  return r;
}
int ma(int n) {
  return n*(n-1)/2;
}

int id;
void build(int n, int d, int par) {
  assert(d >= mi(n) && d <= ma(n));
  if (n == 0) {
    assert(d == 0);
    return;
  }
  d -= n-1;
  if (par != -1)
    cout << par << ' ';
  int cur = id++;
  for (int i = 0; i <= n; i++) {
    if (mi(i)+mi(n-1-i) <= d && ma(i)+ma(n-1-i) >= d) {
      int a = min(d-mi(n-1-i), ma(i));
      build(i, a, cur);
      build(n-1-i, d-a, cur);
      return;
    }
  }
  assert(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    if (mi(n) > d || ma(n) < d) {
      cout << "NO" << endl;
      continue;
    }
    id = 1;
    cout << "YES" << endl;
    build(n, d, -1);
    cout << endl;
  }
}