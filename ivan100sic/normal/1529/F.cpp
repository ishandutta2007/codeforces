// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int w[605][605];
ll d[605][605];
bool q[605];
ll r[605];

int sub(int x, int y) {
  x -= y;
  if (x < 0) x += n;
  return x;
}

void run(int x, ll* d) {
  memset(d, 63, sizeof(::d[0]));
  memset(q, 0, sizeof q);
  d[x] = 0;
  for (int i=0; i<n; i++) {
    int idx = -1;
    for (int j=0; j<n; j++) {
      if (!q[j] && (idx == -1 || d[j] < d[idx])) {
        idx = j;
      }
    }
    q[idx] = 1;

    int dmn = d[idx] % n;

    for (int j=0; j<n; j++) {
      r[j] = d[idx] + w[idx][sub(j, dmn)];
    }

    auto go = [&]() {
      r[0] = min(r[0], r[n-1] + 1);
      for (int j=1; j<n; j++) {
        r[j] = min(r[j], r[j-1] + 1);
      }
      r[0] = min(r[0], r[n-1] + 1);
    };

    go(); go();

    for (int j=0; j<n; j++) {
      d[j] = min(d[j], r[j]);
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  memset(w, 63, sizeof w);
  for (int i=0; i<m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    w[a][b] = c;
  }

  for (int i=0; i<n; i++) {
    run(i, d[i]);
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cout << d[i][j] << " \n"[j == n-1];
    }
  }
}