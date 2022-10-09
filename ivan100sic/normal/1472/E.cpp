// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct covek {
  int x, y, id;

  bool operator< (const covek& b) const {
    return x < b.x;
  }
};

vector<covek> bp(vector<covek> a) {
  int n = a.size();
  vector<covek> b(n+1);
  b[0] = {1123123123, 1123123123, -1};
  for (int i=0; i<n; i++) {
    if (a[i].y < b[i].y) {
      b[i+1] = a[i];
    } else {
      b[i+1] = b[i];
    }
  }
  return b;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<covek> a(n), b, c;
    for (int i=0; i<n; i++) {
      cin >> a[i].x >> a[i].y;
      a[i].id = i+1;
    }

    b = a;
    c = a;

    for (int i=0; i<n; i++) {
      swap(c[i].x, c[i].y);
    }

    sort(begin(b), end(b));
    sort(begin(c), end(c));

    auto d = bp(b);
    auto e = bp(c);

    for (int i=0; i<n; i++) {
      int z = -1;
      auto j = lower_bound(begin(b), end(b), a[i]) - begin(b);
      if (d[j].x < a[i].x && d[j].y < a[i].y) {
        z = d[j].id;
      }

      j = lower_bound(begin(c), end(c), a[i]) - begin(c);
      if (e[j].x < a[i].x && e[j].y < a[i].y) {
        z = e[j].id;
      }

      cout << z << " \n"[i == n-1];
    }
  }
}