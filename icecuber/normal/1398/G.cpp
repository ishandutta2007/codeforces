


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
bitset<nax> pos, diff;

vector<int> mem[(int)1e6];
vector<int> fac(int n) {
  if (!mem[n].size()) {
    for (int i = 1; i*i <= n; i++) {
      if (n%i == 0) mem[n].push_back(i), mem[n].push_back(n/i);
    }
  }
  return mem[n];
}

int main() {
  //for (int i = 1; i < 5e5; i++)
  //  fac(i);
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  //n = x = y = nax;
  for (int i = 0; i < n+1; i++) {
    int a;
    //a = i;
    cin >> a;
    pos[a] = 1;
  }
  for (int j = 0; j <= x; j++) {
    if (pos[0])
      diff |= pos;
    pos >>= 1;
  }

  //return 0;
  int q;
  cin >> q;
  while (q--) {
    int l;
    cin >> l;
    l /= 2;
    int ans = -1;
    for (int div : fac(l)) {
      if (div-y < nax && div > y && diff[div-y]) ans = max(ans, div*2);
    }
    cout << ans << ' ';
  }
  cout << endl;
}