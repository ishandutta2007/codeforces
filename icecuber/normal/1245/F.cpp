#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(int x, int y) {
  ll r = 0;
  for (int la = 0; x>>la; la++) {
    for (int lb = 0; y>>lb; lb++) {
      if ((x>>la&1) && (y>>lb&1)) {
	int a = (x>>la^1)<<la;
	int b = (y>>lb^1)<<lb;
	int ma = max(la,lb), mi = min(la,lb);
	ll pow3 = 1;
	for (int i = 0; i < mi; i++)
	  pow3 *= 3;
	if (!(a&b))
	  r += pow3 << ma-mi-__builtin_popcount((a^b) & ((1<<ma)-1));
      }
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    r++;
    cout << f(r,r)-f(l,r)*2+f(l,l) << endl;
  }
}