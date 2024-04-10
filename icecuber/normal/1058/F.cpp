#include <iostream>

using namespace std;

typedef long long ll;

ll mod = 1e9+7;

const int m = 300000;
struct Tree {
  ll data[m];
  Tree() {
    fill_n(data, m, 0);
  }
  void add(int i, ll v) {
    for (i++; i < m; i += i&-i) data[i] += v;
  }
  ll sum(int i) {
    ll r = 0;
    for (i++; i; i -= i&-i) r += data[i];
    return r;
  }
  ll sum(int a, int b) {
    return sum(b)-sum(a-1);
  }
};

struct Tree2 {
  ll data[m];
  Tree2() {
    fill_n(data, m, 0);
  }
  void add(int i, ll v) {
    for (i++; i < m; i += i&-i) data[i] = (data[i]+v)%mod;
  }
  ll sum(int i) {
    ll r = 0;
    for (i++; i; i -= i&-i) r = (r+data[i])%mod;
    return (r+mod)%mod;
  }
  ll sum(int a, int b) {
    return (sum(b)-sum(a-1)+mod)%mod;
  }
};


ll a[200002], w[200002];

Tree wtree;
Tree2 awtree;

int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i+1];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i+1];
  }

  for (int i = 1; i <= n; i++) {
    wtree.add(i, w[i]);
    awtree.add(i, w[i]*(a[i]-i));
  }
  while (q--) {
    ll x, y;
    cin >> x >> y;
    if (x < 0) {
      ll i = -x;
      ll nw = y;
      wtree.add(i, -w[i]);
      awtree.add(i, -w[i]*(a[i]-i));
      w[i] = nw;
      wtree.add(i, w[i]);
      awtree.add(i, w[i]*(a[i]-i));
    } else {
      int l = x, r = y;
      ll wsum_all = wtree.sum(r)-wtree.sum(l-1);
      int pass = r, fail = l-1;
      while (fail+1 < pass) {
	int m = pass+fail>>1;
	ll wsum = wtree.sum(m)-wtree.sum(l-1);
	if (wsum*2 >= wsum_all) pass = m;
	else fail = m;
      }
      ll o = pass-a[pass];
      ll out =
	((-awtree.sum(l, pass-1)-wtree.sum(l, pass-1)%mod*o%mod+
	  awtree.sum(pass+1, r)+wtree.sum(pass+1, r)%mod*o%mod)%mod+mod)%mod;
      cout << out << endl;
    }
  }
}