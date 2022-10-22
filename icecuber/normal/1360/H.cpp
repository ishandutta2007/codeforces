#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      ll v = 0;
      for (char c : s) {
	v = v*2+(c=='1');
      }
      a.push_back(v);
    }
    ll smaller = ((1ll<<m)-n-1)/2;
    ll pass = (1ll<<m)-1, fail = -1;
    while (pass-fail > 1) {
      ll mid = (pass+fail)>>1;
      ll c = mid;
      for (ll v : a)
	if (v <= mid) c--;
      if (c >= smaller) pass = mid;
      else fail = mid;
    }
    for (int i = m-1; i >= 0; i--)
      cout << (pass>>i&1);
    cout << endl;
  }
}