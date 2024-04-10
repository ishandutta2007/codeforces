// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
int a[100005];

bool moze(int m) {
  int zeleni = ((m+1)/2) * ((m+1)/2);
  int prvi = m*m/4;

  if (n > zeleni + 2 * prvi) {
    return false;
  }

  for (int i=1; i<=k; i++) {
    if (a[i] >= prvi) {
      zeleni -= a[i] - prvi;
    }
  }

  return zeleni >= 0;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
      cin >> a[i];
    }

    int l = 1, r = 10000, o = 10001;
    while (l <= r) {
      int m = (l+r) / 2;
      if (moze(m)) {
        o = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    vector<int> b;
    for (int x=1; x<=k; x++) {
      for (int j=o*o/4; j<a[x]; j++) {
        b.push_back(x);
      }
    }

    for (int x=1; x<=k; x++) {
      for (int j=0; j<min(o*o/4, a[x]); j++) {
        b.push_back(x);
      }
    }

    int bi = 0;
    auto daj = [&]() {
      if (bi == (int)b.size()) {
        return 0;
      }
      return b[bi++];
    };

    vector<vector<int>> sol(o, vector<int>(o, 0));
    // zeleni
    for (int i=0; i<o; i+=2) {
      for (int j=0; j<o; j+=2) {
        int x = daj();
        sol[i][j] = x;
        a[x]--;
      }
    }

    // do it again...
    vector<int> as(k);
    iota(begin(as), end(as), 1);
    sort(begin(as), end(as), [&](int x, int y) { return a[x] > a[y]; });
    b.clear();
    bi = 0;
    for (int x : as) {
      for (int j=0; j<a[x]; j++) {
        b.push_back(x);
      }
    }

    auto jedni = [&]() {
      for (int i=1; i<o; i+=2) {
        for (int j=0; j<o; j+=2) {
          sol[i][j] = daj();
        }
      }
    };

    auto drugi = [&]() {
      for (int i=0; i<o; i+=2) {
        for (int j=1; j<o; j+=2) {
          sol[i][j] = daj();
        }
      }
    };

    if (o % 2 == 0) {
      jedni(); drugi();
    } else {
      drugi(); jedni();
    }

    // valjda je dobro
    cout << o << '\n';
    for (int i=0; i<o; i++) {
      for (int j=0; j<o; j++) {
        cout << sol[i][j] << " \n"[j == o-1];
      }
    }

  }
}