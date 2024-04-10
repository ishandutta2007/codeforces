#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int XOR(int i, int j) {
  assert(i != j);
  cout << "or " << i+1 << ' ' << j+1 << endl;
  int OR, AND;
  cin >> OR;
  cout << "and " << i+1 << ' ' << j+1 << endl;
  cin >> AND;
  return OR-AND;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int query[3][2] = {};
  for (int i = 0; i < 3; i++) {
    int j = (i+1)%3;
    for (int k : {0,1}) {
      cout << (k?"and ":"or ") << i+1 << ' ' << j+1 << endl;
      cin >> query[i][k];
    }
  }
  for (int bit = 0; bit < 30; bit++) {
    int oks = 0;
    for (int m = 0; m < 8; m++) {
      int c[3] = {m%2, m/2%2, m/4};
      int ok = 1;
      for (int i = 0; i < 3; i++) {
        int j = (i+1)%3;
        for (int k : {0,1}) {
          int expect = (k?c[i]&c[j]:c[i]|c[j]);
          if (expect != (query[i][k]>>bit&1)) {
            ok = 0;
          }
        }
      }
      if (ok) {
        oks++;
        for (int i = 0; i < 3; i++) {
          a[i] |= c[i]<<bit;
        }
      }
    }
    assert(oks == 1);
  }
  for (int i = 3; i < n; i++) {
    a[i] = XOR(0,i)^a[0];
  }
  sort(a.begin(), a.end());
  cout << "finish " << a[k-1] << endl;
}