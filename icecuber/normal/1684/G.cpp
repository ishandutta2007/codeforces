#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[1000];

int matching[1000], done[1000];
int match(int p) {
  for (int i : node[p]) {
    if (!done[i]++ && (matching[i] == -1 || match(matching[i]))) {
      matching[i] = p;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ll> a, b;
  for (int i = 0; i < n; i++) {
    ll v;
    cin >> v;
    if (3*v <= m) {
      a.push_back(v);
    } else {
      b.push_back(v);
    }
  }

  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)b.size(); j++) {
      if (b[j]%a[i] == 0 && a[i]+b[j]*2 <= m) {
        node[j].push_back(i);
      }
    }
  }

  int maxmatch = 0;
  fill_n(matching, a.size(), -1);
  for (int i = 0; i < (int)b.size(); i++) {
    fill_n(done, a.size(), 0);
    maxmatch += match(i);
  }
  if (maxmatch != (int)b.size()) {
    cout << -1 << endl;
  } else {
    cout << b.size() + a.size()-b.size() << endl;
    for (int i = 0; i < (int)a.size(); i++) {
      if (matching[i] == -1) {
        cout << a[i]*2 << ' ' << a[i]*3 << endl;
      } else {
        ll v = b[matching[i]];
        cout << a[i]+v << ' ' << a[i]+v*2 << endl;
      }
    }
  }
}