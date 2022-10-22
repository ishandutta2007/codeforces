#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Care about bit p and down
void rec(vector<int>&mi, int base, int opt, const vector<int>& a, int al, int ar, int p) {
  if (p == -1) {
    assert(ar-al == 1);
    int i = opt+1;
    do {
      i = (i-1)&opt;
      int x = base+i;
      mi[x] = a[al]^x;
    } while (i);
    return;
  }
  int am = ar;
  for (int i = al; i < ar; i++) {
    if (a[i]>>p&1) {
      am = i;
      break;
    }
  }
  /*for (int i = al; i < ar; i++) {
    assert((a[i]>>p&1) == (i >= am));
  }*/

  if (am == al) {
    rec(mi, base, opt, a, al, ar, p-1);
  } else if (am == ar) {
    rec(mi, base, opt, a, al, ar, p-1);
  } else {
    rec(mi, base, opt^(1<<p), a, al, am, p-1);
    rec(mi, base|1<<p, opt^(1<<p), a, am, ar, p-1);
  }
}

vector<int> recmi(const vector<int>& a, int p) {
  vector<int> mi(1<<(p+1));
  rec(mi, 0, (1<<(p+1))-1, a, 0, a.size(), p);
  return mi;
}
vector<int> recma(vector<int> a, int p) {
  for (int&v : a) v ^= (1<<(p+1))-1;
  reverse(a.begin(), a.end());
  vector<int> mi = recmi(a, p);
  for (int&v : mi) v ^= (1<<(p+1))-1;
  return mi;
}
vector<int> slowrecma(vector<int> a, int p) {
  vector<int> ma(1<<(p+1), -1);
  for (int x = 0; x < 1<<(p+1); x++) 
    for (int v : a)
      ma[x] = max(ma[x], v^x);
  return ma;
}
vector<int> slowrecmi(vector<int> a, int p) {
  vector<int> mi(1<<(p+1), 1e8);
  for (int x = 0; x < 1<<(p+1); x++) 
    for (int v : a)
      mi[x] = min(mi[x], v^x);
  return mi;
}

int ans[20][1<<19];

//Split on bit p
void rec2(const vector<int>& a, int p) {
  if (a.size() <= 1) return;
  assert(p >= 0);
  vector<int> l, r;
  for (int v : a) {
    (v>>p&1 ? r : l).push_back(v);
  }
  if (l.size() && r.size()) {
    auto lmi = recmi(l, p-1);
    auto lma = recma(l, p-1);
    //assert(lma == slowrecma(l, p-1));
    //assert(lmi == slowrecmi(l, p-1));
    auto rmi = recmi(r, p-1);
    auto rma = recma(r, p-1);
    //assert(rma == slowrecma(r, p-1));
    //for (int v : a) assert((a[0]>>(p+1)) == (v>>(p+1)));
    for (int x = 0; x < 1<<(p+1); x++) {
      if (x>>p&1) {
        ans[p][x] = min(ans[p][x], ((lmi[x-(1<<p)]+(1<<p))-(rma[x-(1<<p)]-(1<<p))));
      } else {
        ans[p][x] = min(ans[p][x], (rmi[x]-lma[x]));
      }
    }
  }
  rec2(l, p-1);
  rec2(r, p-1);
}

//#warning dummy input
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  //n = 1<<19, k = 19;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  //for (int i = 0; i < n; i++) a[i] = i;
  sort(a.begin(), a.end());
  for (int i = 0; i < k; i++) 
    for (int j = 0; j < 1<<k; j++)
      ans[i][j] = 1e9;
  rec2(a, k-1);

  for (int x = 0; x < 1<<k; x++) {
    int mi = 1e9;
    for (int i = 0; i < k; i++) mi = min(mi, ans[i][x&((1<<(i+1))-1)]);
    cout << mi << ' ';
  }
  cout << endl;
}