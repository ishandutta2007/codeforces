#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int64 mod = 2184057LL;

const int maxn = 152;
const int inf = 2 * 1000 * 1000 * 1000;

struct Matrix {
  bitset<maxn> a[maxn];

  Matrix operator*(const Matrix& other) const{
    Matrix ot;
    for (int i = 0; i < maxn; ++i)
      for (int j = 0; j < maxn; ++j)
        ot.a[i][j] = other.a[j][i];

    Matrix res;
    for (int i = 0; i < maxn; ++i)
      for (int j = 0; j < maxn; ++j) {
        res.a[i][j] = (a[i] & ot.a[j]).any();
      }
    return res;
  }

  static Matrix E() {
    Matrix res;
    for (int i = 0; i < maxn; ++i)
      res.a[i][i] = 1;
    return res;
  }
};

Matrix pow(Matrix x, int64 y) {
  Matrix res = Matrix::E();
  while (y) {
    if (y % 2LL == 1LL) {
      res = res * x;
      --y;
    } else {
      x = x * x;
      y /= 2LL;
    }
  }
  return res;
}

bool av[maxn];
bool can[maxn][maxn];
int n, m;

int calc(int base) {
  vi d(n, inf);
  queue<int> q;
  for (int i = 0; i < n; ++i)
    if (av[i]) {
      d[i] = base;
      q.push(i);
    }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < n; ++i)
      if (can[x][i] && d[i] == inf) {
        d[i] = d[x] + 1;
        q.push(i);
      }
  }
  return d[n - 1];
}

void make_steps(int num_steps) {
  Matrix a;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      a.a[i][j] = can[i][j];
  a = pow(a, num_steps);
  vi new_av(n, 0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (av[i] && a.a[i][j])
        new_av[j] = true;
  for (int i = 0; i < n; ++i)
    av[i] = new_av[i];
}

int main() {
  memset(can, 0, sizeof(can));

  cin >> n >> m;
  map<int, vector<ii>> events;
  for (int i = 0; i < m; ++i) {
    int x, y, d;
    cin >> x >> y >> d;
    --x, --y;
    events[d].pb(ii(x, y));
  }

  memset(av, 0, sizeof(av));
  av[0] = true;
  int res = inf;
  int prev = 0;
  for (auto entry : events) {
    make_steps(entry.first - prev);
    for (auto edge : entry.second) {
      int x = edge.first;
      int y = edge.second;
      can[x][y] = true;
    }
    res = min(res, calc(entry.first));
    prev = entry.first;
  }
  if (res == inf) {
    cout << "Impossible\n";
  } else {
    cout << res << "\n";
  }
  return 0;
}