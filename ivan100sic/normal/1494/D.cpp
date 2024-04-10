// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct cluster {
  vector<int> l;
  int r;
};

int n, nodes;
int a[505][505], z[1005], sup[1005];
vector<cluster> b;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> a[i][j];
    }

    b.push_back({{i}, i});
    z[i] = a[i][i];
  }

  nodes = n;

  while (b.size() > 1) {
    // najmanji cross-cluster broj
    int m = b.size();
    int ci = -1, cj = -1, lo = 1e9;
    for (int i=0; i<m; i++) {
      for (int j=i+1; j<m; j++) {
        for (int x : b[i].l) {
          for (int y : b[j].l) {
            if (a[x][y] < lo) {
              lo = a[x][y];
              ci = i, cj = j;
            }
          }
        }
      }
    }

    // uzmi i prosiri
    vector<int> c = b[ci].l;
    c.insert(c.end(), begin(b[cj].l), end(b[cj].l));
    string uc(m, 0);
    uc[ci] = uc[cj] = 1;
    for (int i=0; i<m; i++) {
      if (!uc[i]) {
        if (a[c[0]][b[i].l[0]] == lo) {
          c.insert(c.end(), begin(b[i].l), end(b[i].l));
          uc[i] = 1;
        }
      }
    }

    nodes++;
    vector<cluster> b2;
    for (int i=0; i<m; i++) {
      if (!uc[i]) {
        b2.push_back(b[i]);
      } else {
        sup[b[i].r] = nodes;
      }
    }

    b2.push_back({c, nodes});
    z[nodes] = lo;
    swap(b, b2);
  }

  cout << nodes << '\n';
  for (int i=1; i<=nodes; i++) {
    cout << z[i] << " \n"[i == nodes];
  }

  cout << nodes << '\n';
  for (int i=1; i<nodes; i++) {
    cout << i << ' ' << sup[i] << '\n';
  }
}