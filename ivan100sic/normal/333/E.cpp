// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int x[3005], y[3005];
bitset<3008> e[3005];

unsigned kv(int x) {
  return x*x;
}

unsigned dst(int i, int j) {
  return kv(x[i]-x[j]) + kv(y[i]-y[j]);
}

struct pt {
  unsigned d;
  uint16_t i, j;

  bool operator< (const pt& b) const {
    return tie(d, i, j) > tie(b.d, b.i, b.j);
  }
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
  }

  vector<pt> f;

  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      f.push_back(pt{dst(i, j), (uint16_t)i, (uint16_t)j});
    }
  }

  sort(begin(f), end(f));

  cout << setprecision(20) << fixed;

  for (auto [d, i, j] : f) {
    if ((e[i] & e[j]).any()) {
      cout << sqrt(double(d))/2 << '\n';
      return 0;
    }
    e[i].set(j);
    e[j].set(i);
  }
}