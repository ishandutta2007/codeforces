#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3e5+10;

struct Tree {
  vector<ll> data;
  Tree(int n) {
    data.resize(n+1);
  }
  void add(int i, ll v) {
    for (i++; i < (int)data.size(); i += i&-i)
      data[i] += v;
  }
  ll sum(int i) {
    ll ret = 0;
    for (i++; i; i -= i&-i)
      ret += data[i];
    return ret;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  ll acc = 0, pref = 0;
  Tree A(nax), B(nax);
  for (int i = 0; i < n; i++) {
    pref += a[i];
    A.add(a[i], 1);
    acc += B.sum(a[i]);
    for (int x = 1; x*a[i] < nax; x++) {
      B.add(x*a[i], a[i]);
      acc += (i+1-A.sum(x*a[i]-1))*a[i];
    }

    /*acc = 0;
    for (int j = 0; j < nax; j++)
      acc += B.sum(j) * (A.sum(j)-A.sum(j-1));
      */
    cout << pref*(i+1)-acc << ' ';
  }
  cout << endl;
}