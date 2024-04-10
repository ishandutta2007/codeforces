#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

const int maxn = 218;

vector<vi> step(vector<vi> cur, int cnt, vector<vi>& was) {
  vector<vi> next(maxn * 2, vi(maxn * 2, 0));
  for (int i = 0; i < sz(cur); ++i)
    for (int j = 0; j < sz(cur[i]); ++j)
      for (int dir = 0; dir < 8; ++dir) if ((cur[i][j] >> dir) % 2) {
        int x = i, y = j;
        for (int t = 0; t < cnt; ++t) {
          x += dx[dir];
          y += dy[dir];
          was[x][y] = 1;
        }
        next[x][y] |= (1 << ((dir + 1) % 8));
        next[x][y] |= (1 << ((dir + 7) % 8));
      }
  return next;
}

int main() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  vector<vi> was(maxn * 2, vi(maxn * 2, 0));
  vector<vi> cur(maxn * 2, vi(maxn * 2, 0));
  cur[maxn][maxn] = 1;
  for (int i = 0; i < n; ++i) {
    cur = step(cur, v[i], was);
  }
  int res = 0;
  for (auto& l : was)
    for (int x : l)
      if (x) ++res;
  cout << res << "\n";
  return 0;
}