#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

const int MAXN = 1e5 + 5;

typedef long double lf;
typedef long long ll;
typedef pair<int, int> point;

unordered_map<ll, bool> bio;

int n, m, r, k;

lf sol;

int x1, x2, y1, y2;

lf add(int x, int y) {

  int X = r;
  X -= max(0, r - (x + 1));
  X -= max(0, r - (m - x));

  int Y = r;
  Y -= max(0, r - (y + 1));
  Y -= max(0, r - (n - y));

  return (lf) X * Y / ((lf) (n - r + 1) * (m - r + 1));
}

ll f(int i, int j) {
  return (ll) i * MAXN + j;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

set<pair<lf, point>> S;

void solve() {
  x1 = min(r - 1, (m - 1) / 2);
  y1 = min(r - 1, (n - 1) / 2);

  x2 = m - x1 - 1;
  y2 = n - y1 - 1;

  int br = 0;

  FOR(i, x1, x2 + 1) FOR(j, y1, y2 + 1) {
    br ++;
    if(br > k) break;
    S.insert({-1, {i, j}});
    bio[f(i, j)] = true;
  }

  while(k --) {
    auto it = S.begin();

    int x = (*it).second.first;
    int y = (*it).second.second;

    S.erase(S.begin());

    REP(k, 4) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if(nx >= 0 && ny >= 0 && nx < m && ny < n && !bio[f(nx, ny)]) {
        S.insert({-add(nx, ny), {nx, ny}});
        bio[f(nx, ny)] = true;
      }
    }

    sol += add(x, y);
  }
}

int main() {
  cin >> n >> m >> r >> k;

  solve();
  cout << fixed << setprecision(10) << sol << endl;
}