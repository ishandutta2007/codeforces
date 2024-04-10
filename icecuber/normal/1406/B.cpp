#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int&v : a) cin >> v;
    vector<ll> mi(6, 1e18), ma(6, -1e18);
    mi[0] = ma[0] = 1;
    for (int i = 0; i < n; i++) {
      vector<ll> nmi = mi, nma = ma;
      for (int j = 0; j < 5; j++) {
	if (mi[j] < 1e18) {
	  ll x = a[i]*mi[j];
	  ll y = a[i]*ma[j];
	  if (x > y) swap(x,y);
	  nmi[j+1] = min(nmi[j+1], x);
	  nma[j+1] = max(nma[j+1], y);
	}
      }
      mi = nmi, ma = nma;
    }
    cout << ma[5] << endl;
  }
}