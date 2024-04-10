#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<18;

struct Tree {
  ll off[nax*2];
  ll sum1[nax*2];
  ll sum2[nax*2];
  ll sum3[nax*2];
  void update(int i) {
    if (i < nax)
      sum1[i] = sum1[i*2]+sum1[i*2+1];
    sum2[i] = off[i]*sum1[i] + (i<nax ? sum2[i*2] + sum2[i*2+1] : 0);
    sum3[i] = off[i]*(sum2[i]-off[i]*sum1[i]) + off[i]*(off[i]-1)/2*sum1[i] + (i<nax ? sum3[i*2] + sum3[i*2+1] : 0);
  }
  void add(int a, int b, int v, int l = 0, int r = nax, int i = 1) {
    if (a <= l && b >= r) {
      off[i] += v;
      update(i);
    } else if (a >= r || b <= l) return;
    else {
      int m = (l+r)/2;
      add(a, b, v, l, m, i*2);
      add(a, b, v, m, r, i*2+1);
      update(i);
    }
  }
  void lock(int p, int now, int l = 0, int r = nax, int i = 1) {
    if (r-l == 1 && l == p) {
      sum1[i] = now;
      update(i);
    } else if (p >= r || p < l) return;
    else {
      int m = (l+r)/2;
      lock(p, now, l, m, i*2);
      lock(p, now, m, r, i*2+1);
      update(i);
    }
  }
  ll query() {
    return sum3[1];
  }
};

struct BruteTree {
  ll l[nax], s[nax];
  void add(int a, int b, int v) {
    for (int i = a; i < b; i++) {
      s[i] += v;
    }
  }
  void lock(int p, int now) {
    l[p] = now;
  }
  ll query() {
    ll ans = 0;
    for (int i = 0; i < nax; i++) {
      ans += s[i]*(s[i]-1)/2*l[i];
    }
    return ans;
  }
};

Tree tree;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> on(nax);
  int q, d;
  cin >> q >> d;
  while (q--) {
    int p;
    cin >> p;
    on[p] ^= 1;
    tree.add(max(p-d,0), p, on[p]?1:-1);
    tree.lock(p, on[p]);
    cout << tree.query() << endl;
  }
}