#pragma comment(linker, "/STACK:512000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
  string s = FILENAME;
//    assert(!s.empty());
  freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
//freopen("/home/alexandero/ClionProjects/cryptozoology/output.txt", "w", stdout);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
      //cout << "Case #" << testNum++ << ": ";
      solve(true);
  }
  cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cout.flush();
  auto end = clock();

  usleep(10000);
  print_stats(end - start);
  usleep(10000);
#endif

    return 0;
}

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;
#define ld double

const ld eps = 1e-9;

struct Point {
  ld x, y;

  Point(ld x = 0, ld y = 0): x(x), y(y) {}

  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }

  Point operator*(ld t) const { return Point(x * t, y * t); }
  Point operator/(ld t) const { return Point(x / t, y / t); }

  ld operator *(const Point& p) const { return x * p.y - y * p.x; }
  ld operator %(const Point& p) const { return x * p.x + y * p.y; }

  Point rot() const { return Point(-y, x); }

  Point norm() const { return *this / len(); }
  bool valid() const { return isfinite(x); }

  ld len() const { return hypot(x, y); }
  ld sql() const { return x * x + y * y; }

  int half() const {
    if (abs(y) > eps)
      return y < 0;
    else
      return x < -eps;
  }
  void scan() {
    cin >> x >> y;
  }
};

const ld PI = acos((ld)-1.0);

struct DP {
  int cnt;
  int index;
  li shift;
};

const int L = 18;

vector<DP> dp[L];

const int INF = (int)1e9;

struct SegTree {
  int shift;
  vector<pair<int, int>> tree;
  SegTree(int n) {
    shift = 1;
    while (shift < n) {
      shift *= 2;
    }
    tree.assign(2 * shift, {INF, -1});
  }
  void update(int v, int val, int pos) {
    v += shift;
    relax_min(tree[v], make_pair(val, pos));
    v /= 2;
    while (v) {
      tree[v] = min(tree[2 * v], tree[2 * v + 1]);
      v /= 2;
    }
  }
  pair<int, int> get_min(int l, int r) {
    l += shift;
    r += shift;
    pair<int, int> res = {INF, -1};
    while (l < r) {
      if (l & 1) {
        relax_min(res, tree[l++]);
        continue;
      }
      if (r & 1) {
        relax_min(res, tree[--r]);
        continue;
      }
      l /= 2;
      r /= 2;
    }
    return res;
  }
};

int N;

bool is_good(vector<Point>& points, vector<ld>& atans, ld R, int m) {
  vector<pair<ld, ld>> vec;
  vector<ld> all_coords;
  for (int i = 0; i < points.size(); ++i) {
    auto def_alpha = atans[i];
    auto alpha = acos(R / points[i].len());
    //cout << alpha << " " << R << " " << points[i].len() << endl;
    auto lef = def_alpha - alpha;
    auto rig = def_alpha + alpha;
    while (lef < 0) {
      lef += 2 * PI;
      rig += 2 * PI;
    }
    while (rig >= 2 * PI) {
      rig -= 2 * PI;
    }
    vec.push_back({lef, rig});
    all_coords.push_back(lef);
    all_coords.push_back(rig);
  }
  make_unique(all_coords);
  vector<pair<int, int>> comp(vec.size());
  for (int i = 0; i < vec.size(); ++i) {
    comp[i].first = lower_bound(all(all_coords), vec[i].first) - all_coords.begin();
    comp[i].second = lower_bound(all(all_coords), vec[i].second) - all_coords.begin();
    //cout << comp[i].first << " " << comp[i].second << endl;
    //assert(comp[i].first != comp[i].second);
    if (comp[i].second < comp[i].first) {
      comp[i].second += all_coords.size();
    }
  }
  sort(all(comp));
  SegTree tree(2 * all_coords.size());
  for (int i = 0; i < comp.size(); ++i) {
    auto& item = comp[i];
    tree.update(item.first + all_coords.size(), item.second + all_coords.size(), i);
  }
  auto& need = comp;
  dp[0].resize(need.size());
  for (int i = (int)need.size() - 1; i >= 0; --i) {
    int coord = need[i].second;
    auto cur_node = tree.get_min(coord + 1, 2 * all_coords.size());
    li shift = cur_node.first - coord;
    int index = cur_node.second;
    dp[0][i] = {1, index, shift};
    tree.update(need[i].first, need[i].second, i);
    //cout << i << " " << index << " " << shift << endl;
  }
  for (int j = 1; j < L; ++j) {
    dp[j].resize(need.size());
    for (int i = 0; i < need.size(); ++i) {
      auto cur_dp = dp[j - 1][i];
      int index = cur_dp.index;
      auto next_dp = dp[j - 1][index];
      dp[j][i] = {cur_dp.cnt + next_dp.cnt, next_dp.index, cur_dp.shift + next_dp.shift};
    }
  }
  int min_cnt = INF;
  for (int i = 0; i < need.size(); ++i) {
    int cur = i;
    int cnt = 1;
    li shift = 0;
    for (int j = L - 1; j >= 0; --j) {
      auto cur_dp = dp[j][cur];
      if (cur_dp.shift + shift < all_coords.size()) {
        cur = cur_dp.index;
        shift += cur_dp.shift;
        cnt += cur_dp.cnt;
      }
    }
    relax_min(min_cnt, cnt);
    if (cnt <= m) {
      return true;
    }
  }
  return false;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  cin >> n >> m;
  N = n;
  vector<Point> points;
  ld min_dist = 1e18;
  set<pair<int, int>> have;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (have.count({x, y})) {
      continue;
    }
    have.insert({x, y});
    points.push_back({x, y});
    relax_min(min_dist, points.back().len());
  }
  n = (int)points.size();
  if (min_dist < eps) {
    cout << "0\n";
    return;
  }
  vector<ld> atans(n);
  for (int i = 0; i < n; ++i) {
    atans[i] = atan2(points[i].y, points[i].x);
  }
  ld l = 0, r = min_dist;
  while (r - l > 5e-7) {
    ld M = (l + r) / 2;
    if (is_good(points, atans, M, m)) {
      l = M;
    } else {
      r = M;
    }
  }
  cout << l << endl;
}