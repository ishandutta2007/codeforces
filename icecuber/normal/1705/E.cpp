#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define l second
#define r first
const int nax = 2e5+10;
set<pair<int,int>> ones;
void add(int p) {
  auto it = ones.upper_bound({p,(int)1e9}); 
  if (it == ones.end() || it->l > p) {
    ones.insert({p+1, p});
  } else {
    auto cp = *it;
    ones.erase(it);
    if (p > cp.l) {
      ones.insert({p, cp.l});
    }
    add(cp.r);
  }
}

void sub(int p) {
  auto it = ones.upper_bound({p,(int)1e9}); 
  assert(it != ones.end());
  if (it->l > p) {
    ones.insert({it->l, p});
    sub(it->l);
  } else {
    auto cp = *it;
    ones.erase(it);
    if (p > cp.l) {
      ones.insert({p, cp.l});
    }
    if (p+1 < cp.r) {
      ones.insert({cp.r, p+1});
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    add(a[i]);
  }
  while (q--) {
    int k, l;
    cin >> k >> l;
    k--;
    sub(a[k]);
    a[k] = l;
    add(a[k]);
    cout << ones.rbegin()->r-1 << endl;
  }
}