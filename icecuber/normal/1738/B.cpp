#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<ll> s(k);
    for (ll&v : s) cin >> v;
    ll x = s[0];
    if (x > 0)
      s.insert(s.begin(), x-((x-1)/(n-k+1)+1));
    else
      s.insert(s.begin(), x-x/(n-k+1));
    int ok = 1;
    for (int i = 2; i < (int)s.size(); i++) {
      ll a = s[i-2], b = s[i-1], c = s[i];
      if (b-a > c-b) ok = 0;
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
}