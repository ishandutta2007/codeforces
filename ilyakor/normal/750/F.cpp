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
#include <unordered_map>
#include <memory>

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

class Interactor {
 public:
  virtual int getH() = 0;
  virtual vi query(int x) = 0;
  virtual void ans(int x) = 0;
};

class StdInteractor : public Interactor {
 public:
  int getH() override {
    int h;
    scanf("%d", &h);
    if (h == 0) exit(0);
    return h;
  }

  vi query(int x) override {
    printf("? %d\n", x + 1);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    if (k == 0) exit(0);
    vi res(k);
    for (int i = 0; i < k; ++i) {
      scanf("%d", &res[i]);
      --res[i];
    }
    random_shuffle(all(res));
    return res;
  }

  void ans(int x) override {
    printf("! %d\n", x + 1);
    fflush(stdout);
  }
};

class RandomInteractor : public Interactor {
 public:
  int h;
  vi ind;
  vi pos;
  int cnt;

  void print() {
    for (int x : ind)
      cerr << x << " ";
    cerr << "\n";
  }

  RandomInteractor(int h) : h(h) {
    for (int i = 0; i < (1 << h) - 1; ++i)
      ind.pb(i);
    random_shuffle(all(ind));
    pos = vi(sz(ind));
    for (int i = 0; i < sz(ind); ++i)
      pos[ind[i]] = i;
    cnt = 0;
  }

  int getH() override {
    return h;
  }

  vi query(int x) override {
    ++cnt;
    assert(cnt <= 16);
    vi res;
    int y = pos[x];
    if (y > 0) res.pb(ind[(y - 1) / 2]);
    if (y * 2 + 1 < sz(ind)) res.pb(ind[y * 2 + 1]);
    if (y * 2 + 2 < sz(ind)) res.pb(ind[y * 2 + 2]);
    random_shuffle(all(res));
//    cerr << x << ": ";
//    for (int t : res) cerr << t << " ";
//    cerr << "\n";
    return res;
  }

  void ans(int x) override {
    assert(pos[x] == 0);
  }
};

class CachingInteractor : public Interactor {
 public:
  Interactor* interactor;
  unordered_map<int, vi> cache;
  int num_queries;

  CachingInteractor(Interactor* interactor) : interactor(interactor), num_queries(0) {
  }

  int getH() override {
    return interactor->getH();
  }

  vi query(int x) {
    if (cache.count(x)) return cache[x];
    vi res = interactor->query(x);
    ++num_queries;
    if (sz(res) == 2) {
      this->ans(x);
      throw 57;
    }
    return cache[x] = res;
  }

  void ans(int x) override {
    interactor->ans(x);
  }

  bool cached(int x) {
    return cache.count(x);
  }
};

unique_ptr<CachingInteractor> global;
int h, n;


vi query(int x) {
  return global->query(x);
}

int walk(int x, int p, int expected=-1) {
//  cerr << "Walk " << x << "\n";
  int res = 0;
  while (true) {
    vi w = query(x);
    vi v;
    for (int t : w) if (t != p) v.pb(t);
    if (sz(v) == 0) break;
    ++res;
    if (expected != -1 && res > expected) return res;
//    cerr << "Walk to " << v[0] << "\n";
    if (!global->cached(v[0]) && global->cached(v[1]))
      swap(v[0], v[1]);
    p = x;
    x = v[0];
  }
//  cerr << "Walk done: " << res << "\n";
  return res;
}


void solve(Interactor* inter) {
  global.reset(new CachingInteractor(inter));
  h = global->getH();
  n = (1 << h) - 1;
  int x, prev, height;
  while (true) {
    x = rand() % n, prev = -1, height = -1;
    vi n0 = query(x);
    random_shuffle(all(n0));
    if (sz(n0) == 1) {
      prev = x;
      x = n0[0];
      height = 1;
    } else {
      vi dist;
      int val = -1;
      for (int t : n0) {
        int cur = walk(t, x, val);
        if (val == -1) val = cur;
        else val = min(val, cur);
        dist.pb(cur);
        if (sz(dist) == 2) {
          if (dist[0] == dist[1]) {
            dist.pb(-1);
          } else if (dist[0] < dist[1]) {
            dist.pb(dist[0]);
          } else {
            dist.pb(dist[1]);
          }
          break;
        }
      }
      int z;
      if (dist[0] == dist[1]) z = 2, height = dist[0];
      else if (dist[0] == dist[2]) z = 1, height = dist[2];
      else z = 0, height = dist[1];
      z = n0[z];
      height += 2;
      prev = x;
      x = z;
    }
    break;
    //if (h - height <= 6) break;
  }
  cerr << "Start: " << x << " <- " << prev << " " << global->num_queries << "\n";
  while (true) {
    vi neigh = query(x);
    vi cn;
    for (int t : neigh) if (t != prev) cn.pb(t);
    assert(sz(cn) == 2);
    random_shuffle(all(cn));
    if (!global->cached(cn[0]) && global->cached(cn[1])) {
      swap(cn[0], cn[1]);
    }
    if (height == h - 2) {
      cerr << "Trigger " << global->num_queries << "\n";
      if (global->num_queries == 16) {
        global->ans(cn[1]);
        return;
      }
      query(cn[0]);
      cerr << "Fail\n";
      global->ans(cn[1]);
      return;
      //query(cn[1]);
    }
    int z = cn[0];
    if (height == h - 3) {
      vi vt = query(z);
      for (int t : vt) query(t);
      z = cn[1];
    } else {
      if (walk(z, x, height - 1) == height - 1)
        z = cn[1];
    }
    cerr << "Go to " << z << " " << height << " " << global->num_queries << "\n";
    prev = x;
    x = z;
    ++height;
  }
}

int main() {
//  for (int it = 0; it < 1000; ++it) {
//    cerr << "It " << it << "\n";
//    int n = 7;//rand() % 5 + 2;
//    cerr << n << "\n";
//    RandomInteractor inter(n);
//    inter.print();
//    try {
//      solve(&inter);
//    } catch(int) {}
//  }
  int nc;
  scanf("%d", &nc);
  for (int i = 0; i < nc; ++i) {
    StdInteractor interactor; 
    try {
      solve(&interactor);
    } catch (int) {}
  }
  return 0;
}