#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100000], kacc[100000], kacc2[100001];

const ll n = 1<<17;
struct treeA {
  ll data[n*2];
  ll get(int i) {
    i += n;
    ll r = data[i];
    for (; i > 1; i /= 2)
      if (i&1)
	r = max(data[i-1], r);
    return r;
  }
  void set(int i, ll v) {
    i += n;
    data[i] = v;
    for (i /= 2; i; i /= 2)
      data[i] = max(data[i*2], data[i*2+1]);
  }
  int find(ll v) {
    if (data[1] <= v) return n-1;
    int i = 1;
    while (i < n) {
      i *= 2;
      if (data[i] <= v) i++;
    }
    return i-n;
  }
};

struct treeB {
  ll data[n*2], lazy[n*2];
  void set(int a, int b, ll v, int l = 0, int r = n, int i = 1) {
    prop(i, r-l);
    if (b <= l || a >= r) return;
    if (a <= l && b >= r) {
      lazy[i] = v;
      prop(i, r-l);
      return;
    }
    ll m = l+r>>1;
    set(a, b, v, l, m, i*2);
    set(a, b, v, m, r, i*2+1);
    data[i] = data[i*2]+data[i*2+1];
  }
  ll sum(int i) {
    i += n;
    ll r = 0;
    for (int j = 17; j >= 0; j--) {
      prop(i>>j, 1<<j);
      if (i>1 && (i>>j&1))
	r += data[(i>>j)-1];
    }
    return r;
  }
  void prop(int i, int w) {
    if (lazy[i] == -1e18) return;
    data[i] = lazy[i]*w;
    if (i >= n) return;
    lazy[i*2] = lazy[i*2+1] = lazy[i];
    data[i*2] = lazy[i]*(w/2);
    data[i*2+1] = lazy[i]*(w/2);
    lazy[i] = -1e18;
  }
};

treeA A;
treeB B;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  kacc[0] = 0;
  for (int i = 0; i < n-1; i++) {
    ll k;
    cin >> k;
    kacc[i+1] = kacc[i]+k;
  }
  for (int i = 1; i <= n; i++)
    kacc2[i] = kacc2[i-1]+kacc[i-1];
  for (int i = 0; i < n; i++) {
    a[i] -= kacc[i];
    A.set(i, a[i]);
    B.set(i, i+1, a[i]);
  }

  int q;
  cin >> q;
  while (q--) {
    string cmd;
    cin >> cmd;
    /*for (int i = 0; i < n; i++)
      cout << a[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
      cout << B.sum(i+1)-B.sum(i) << ' ';
      cout << endl;*/
    if (cmd[0] == '+') {
      ll i, x;
      cin >> i >> x;
      i--;
      ll a0 = A.get(i)+x;
      A.set(i, a0);
      //assert(A.get(i) == a0);
      int e = A.find(a0);
      //e = min(e, n);
      B.set(i, e, a0);
      //cerr << i << ' ' << e << endl;
      //cerr << B.sum(e)-B.sum(i) << ' ' << a0*(e-i) << endl;
      //assert(B.sum(e)-B.sum(i) == a0*(e-i));
      //a[i] += x;
      //cout << e << ' ' << n << endl;
      //for (int j = i; j < n; j++)
      //a[j] = max(a[i], a[j]);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      ll ans = 0;
      //for (int i = l; i < r; i++)
      //ans += a[i];
      ans = B.sum(r)-B.sum(l);
      cout << ans+kacc2[r]-kacc2[l] << endl;
    }
  }
}