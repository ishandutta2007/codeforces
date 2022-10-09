// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[100005];
int p[100005];
ull sz[100005];

void dfs(int x) {
  sz[x] = 1;
  for (int y : e[x]) {
    if (!sz[y]) {
      p[y] = x;
      dfs(y);
      sz[x] += sz[y];
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=1; i<n; i++) {
    int x, y;
    cin >> x >> y;
    e[x] += y;
    e[y] += x;
  }

  dfs(1);

  ull sol = ull(n) * (n-1) / 2 * (n-2) / 3 * (n-3) / 4;

  for (int x=1; x<=n; x++) {
    vector<ull> b;
    for (int y : e[x]) {
      if (y == p[x]) {
        b.push_back(n - sz[x]);
      } else {
        b.push_back(sz[y]);
      }
    }

    vector<ull> ol(5);
    for (ull w : b) {
      vector<ull> nu = ol;
      for (int i=1; i<4; i++) {
        nu[i+1] += ol[i] * w;
      }
      nu[1] += w;
      swap(ol, nu);
    }

    sol -= ol[3] + ol[4];
  }

  cout << 2*sol << '\n';
}