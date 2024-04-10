// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, p;
int a[50005], ainv[50005];
bool used[50005];

void rd() {
  cin >> n >> p;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
    ainv[a[i]] = i;
  }
}

void pr() {
  int u = count(used+1, used+n+1, true);
  if (u == 0) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n" << u << "\n";
  for (int i=1; i<=n; i++) {
    if (used[i]) {
      cout << ainv[i] << ' ';
    }
  }
  cout << '\n';
}

struct dpval {
  uint16_t rem;
  uint8_t xr;
  uint8_t ok;
};

dpval d[32][32][50005];
vector<int> s;

int xt(int x, int y) {
  if (y < 10) return (10*x + y) % p;
  return (100*x + y) % p;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  rd();

  int k = min(31, n);
  d[0][0][0].ok = 1;

  for (int i=1; i<=n; i++) {
    if (a[i] <= k) {
      s.emplace_back(a[i]);
    }
  }

  for (int i=0; i<k; i++) {
    for (int x=0; x<32; x++) {
      for (int r=0; r<p; r++) {
        if (d[i][x][r].ok) {
          d[i+1][x][r] = {r, x, 1};
          d[i+1][x^s[i]][xt(r, s[i])] = {r, x, 1};
        }
      }
    }
  }

  // rekonstrukcija
  if (d[k][0][0].ok) {
    int r=0, x=0;
    for (int i=k; i>0; i--) {
      auto [rem, xr, ok] = d[i][x][r];
      if (x != xr) {
        used[x ^ xr] = 1;
      }

      r = rem;
      x = xr;
    }
  }

  pr();
}