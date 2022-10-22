#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int query(int p) {
  if (p == -1 || p == n) return 1e9;
  assert(p >= 0 && p < n);
  cout << "? " << p+1 << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int a = -1, b = n/2, c = n;
  int fa = n+1, fb = query(b), fc = n+1;
  while (abs(c-b) > 1 || abs(b-a) > 1) {
    //cerr << a << ' ' << b << ' ' << c << endl;
    //cerr << fa << ' ' << fb << ' ' << fc << endl;
    assert(fb < fa && fb < fc);
    assert((a < b && b < c) || (c < b && b < a));
    if (abs(c-b) < abs(b-a)) {
      swap(a,c);
      swap(fa,fc);
    }
    int m = b+(c-b)/3;
    if (abs(c-b) < 3)
      m = b+(c-b)/2;
    int fm = query(m);
    if (fm < fb) {
      tie(a,b,c) = make_tuple(b,m,c);
      tie(fa,fb,fc) = make_tuple(fb,fm,fc);
    } else {
      tie(a,b,c) = make_tuple(m,b,a);
      tie(fa,fb,fc) = make_tuple(fm,fb,fa);
    }
  }
  cout << "! " << b+1 << endl;
}