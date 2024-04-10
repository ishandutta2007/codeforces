#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<llint, llint> point;
#define x first
#define y second

const int MAXN = 100100;
const llint inf = 6e18;

inline llint sqr(int x) { return llint(x)*x; }

point a[MAXN];

point Ql[MAXN], Qr[MAXN];
int head_l, tail_l, head_r, tail_r;

llint dist(const point &a, const point &b) {
  return sqr(a.x-b.x) + sqr(a.y-b.y);
}

bool cmpY(const point &a, const point &b) {
  return a.y < b.y;
}

llint solve(int lo, int hi) {
  if (hi-lo == 1) return inf;
  if (hi-lo == 2) {
    if (a[lo].y > a[lo+1].y) swap(a[lo], a[lo+1]);
    return dist(a[lo], a[lo+1]);
  }

  int mid = (lo + hi)/2;
  int midx = a[mid].x;

  llint left = solve(lo, mid);
  llint right = solve(mid, hi);
  llint best = min(left, right);

  int i = lo, j = mid;
  head_l = tail_l = head_r = tail_r = 0;
  while (i < mid || j < hi) {
    if (i < mid && sqr(a[i].x-midx) > best) { ++i; continue; }
    if (j < hi && sqr(a[j].x-midx) > best) { ++j; continue; }
    
    int y = 0;
    if (i < mid && (j == hi || a[i].y <= a[j].y)) {
      y = a[i].y;
      for (int r = tail_r; r < head_r; ++r)
        best = min(best, dist(a[i], Qr[r]));
      Ql[head_l++] = a[i++];
    } else {
      y = a[j].y;
      for (int l = tail_l; l < head_l; ++l)
        best = min(best, dist(a[j], Ql[l]));
      Qr[head_r++] = a[j++];
    }

    while (tail_l < head_l && sqr(y-Ql[tail_l].y) > best) tail_l++;
    while (tail_r < head_r && sqr(y-Qr[tail_r].y) > best) tail_r++;
  }

  inplace_merge(a+lo, a+mid, a+hi, cmpY);
  return best;
}

int main(void) {
  int n;
  scanf("%d", &n);
  int sum = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    sum += x;
    a[i] = {i, sum};
  }

  sort(a, a + n);
  llint ans = solve(0, n);
  cout << ans << endl;
  return 0;
}