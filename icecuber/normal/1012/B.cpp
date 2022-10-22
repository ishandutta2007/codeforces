#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, q;
  cin >> h >> w >> q;
  vector<int> par(w+h);
  for (int i = 0; i < w+h; i++) par[i] = i;
  function<int(int)> find = [&](int p) {
    return p == par[p] ? p : par[p] = find(par[p]);
  };
  for (int i = 0; i < q; i++) {
    int r, c;
    cin >> r >> c;
    r--, c--;
    int a = find(c+h), b = find(r);
    par[a] = b;
  }
  int comps = 0;
  for (int i = 0; i < w+h; i++) {
    if (par[i] == i) comps++;
  }
  cout << comps-1 << endl;
}