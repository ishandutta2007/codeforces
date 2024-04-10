#include <bits/stdc++.h>
using namespace std;
#include <string>
typedef long long ll;

int query(int l, int r) {
  assert(r > l);
  if (r-l == 1) return -1e9;
  cout << "? " << l+1 << ' ' << r << endl;
  int ans;
  cin >> ans;
  return ans-1;
}

int main() {
  int n;
  cin >> n;
  int l = 0, r = n;
  while (r-l > 1) {
    int m = (l+r)/2;
    int s = query(l, r);
    if (s >= m) {
      if (query(m,r) == s) l = m;
      else r = m;
    } else {
      if (query(l,m) == s) r = m;
      else l = m;
    }
  }
  cout << "! " << r << endl;
}