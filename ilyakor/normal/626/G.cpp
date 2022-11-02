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

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

struct Guy {
  int c;
  int a;
  int x;

  double inc, dec, val;

  void Compute() {
    val = c * 1.0 * x * 1.0 / (a + x);
    inc = -1E100;
    if (x + 1 <= a) {
      inc = a * 1.0 * c * 1.0 / ((a + x) * 1.0 * (a + x + 1.0));
    }
    dec = 1E100;
    if (x > 0) {
      dec = a * 1.0 * c * 1.0 / ((a + x - 1) * 1.0 * (a + x));
    }
  }
};

vector<Guy> guys;
set<pair<double, int>> incs, decs;
double sum;

void Update(int ind) {
  sum -= guys[ind].val;
  incs.erase(incs.find(mp(-guys[ind].inc, ind)));
  decs.erase(decs.find(mp(guys[ind].dec, ind)));
  guys[ind].Compute();
  sum += guys[ind].val;
  incs.insert(mp(-guys[ind].inc, ind));
  decs.insert(mp(guys[ind].dec, ind));
}

int main() {
  int n, t, q;
  sum = 0;
  scanf("%d%d%d", &n, &t, &q);
  guys.resize(n);
  for (int i = 0; i < n; ++i) {
    int pi;
    scanf("%d", &pi);
    guys[i].c = pi;
  }
  for (int i = 0; i < n; ++i) {
    int ai;
    scanf("%d", &ai);
    guys[i].a = ai;
    guys[i].x = 0;
    guys[i].Compute();
    incs.insert(mp(-guys[i].inc, i));
    decs.insert(mp(guys[i].dec, i));
  }

  while (t > 0) {
    if (incs.begin()->first > 1E90) break;
    int ind = incs.begin()->second;
    guys[ind].x += 1;
    Update(ind);
    --t;
  }

  for (int it = 0; it < q; ++it) {
    int tk, rk;
    scanf("%d%d", &tk, &rk);
    --rk;
    guys[rk].a += tk == 1 ? 1 : -1;
    if (guys[rk].x > guys[rk].a) {
      --guys[rk].x;
      ++t;
    }
    if (guys[rk].x > 0) {
      --guys[rk].x;
      ++t;
    }
    Update(rk);

    int ind = decs.begin()->second;
    if (guys[ind].x > 0) {
      --guys[ind].x;
      ++t;
      Update(ind);
    }

    while (t > 0) {
      if (incs.begin()->first > 1E90) break;
      int ind = incs.begin()->second;
      guys[ind].x += 1;
      Update(ind);
      --t;
    }
    printf("%.15f\n", sum);
  }

  return 0;
}