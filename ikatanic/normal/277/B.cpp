#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
typedef pair<int, int> Pt;
#define x first
#define y second

const int R = 55250;
const int r = R / 2;
const int MAXS = 1000;
const int MAX = 222;

vector<Pt> gen(llint R) {
  vector<Pt> ans;
  for (llint x = -R; x <= +R; ++x) {
    llint y = sqrt(R*R - x*x + 1);
    if (x*x + y*y == R*R) { 
      ans.push_back({x, y});
      ans.push_back({x, -y});
    }
  }
  return ans;
}

int ccw(const Pt &a, const Pt &b, const Pt &c) {
  llint w = 0;
  w += llint(a.x) * (b.y - c.y);
  w += llint(b.x) * (c.y - a.y);
  w += llint(c.x) * (a.y - b.y);
  return w < 0 ? -1 : w > 0;
}

int f[MAX][MAX];
Pt a[MAX];
int n;
Pt nova;

int rec(int i, int j) {
  if (f[i][j] != -1) return f[i][j];
  if (j == n) return f[i][j] = 0;
  if (ccw(a[i], a[j], nova) > 0) return f[i][j] = -MAX;

  f[i][j] = -MAX;
  FOR(k, j+1, n+1)
    if (ccw(a[i], a[j], a[k]) < 0) f[i][j] = max(f[i][j], 1 + rec(j, k));
  return f[i][j];
}

bool check(vector<Pt> v, int m) {
  int p = v.size();
  REP(i, p) REP(j, i) {
    if (v[i] == v[j]) return false;
    
    REP(k, j)
      if (ccw(v[i], v[j], v[k]) == 0) return false;
  }
  nova = v.back();

  sort(v.begin(), v.end());
  while ((int)v.size() > m) {
    memset(f, -1, sizeof(f));
    
    sort(v.begin() + 1, v.end(), [&] (const Pt &a, const Pt &b) {
        return ccw(v[0], a, b) < 0;
      }
    );

    n = v.size();
    REP(i, n) a[i] = v[i];
    a[n] = a[0];

    FOR(i, 1, n)
      if (rec(0, i)+1 > m) return false;
    
    if (v[0] == nova) break;
    v.erase(v.begin());
  }
  
  return true;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  REP(it, 20) {
    srand(it);

    vector<Pt> V = gen(R);
    random_shuffle(V.begin(), V.end());

    assert((int)V.size() >= m);
    V.resize(m);

    int steps = 0;
    while ((int)V.size() < n && steps < MAXS) {
      int x = (rand() % (2*r)) - r;
      int y = (rand() % (2*r)) - r;
    
      V.push_back({x, y});
      if (m > 40 || check(V, m)) {
        steps = 0;
      } else
        steps++, V.pop_back();
    }

    if ((int)V.size() == n)  {
      for (auto &p: V) printf("%d %d\n", p.x, p.y);
      return 0;
    }
  } 

  puts("-1");
  return 0;
}