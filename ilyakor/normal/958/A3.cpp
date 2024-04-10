#include <bits/stdc++.h>
#include <cmath>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

typedef double D;

constexpr D PI = 4.0 * atan(1.0);

int my_rand() {
    int res = (rand() << 16) + rand();
    if (res < 0) res = -res;
    if (res < 0) res = 0;
    return res;
}

struct P {
  D x, y;

  P() {}
  P(D x, D y) : x(x), y(y) {}

  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  D operator*(P p) { return x * p.y - y * p.x; }
  D operator&(P p) { return x * p.x + y * p.y; }
  P operator*(D l) { return P(x * l, y * l); }
  D norm2() { return x * x + y * y; }
  D norm() { return sqrt(x * x + y * y); }
  P rot(D alpha) {
    return P(x * cos(alpha) + y * sin(alpha), -x * sin(alpha) + y * cos(alpha));
  }
  string str() {
    return "(" + to_string(x) + ", " + to_string(y) + ")";
  }

  static P rand() {
    return P(::my_rand() % 20000000 - 10000000, ::my_rand() % 20000000 - 10000000) * 0.001;
  }

  P round() {
    return P(int64(x * 100.0) * 0.01, int64(y * 100.0) * 0.01);
  }
};

int n, n1, n2;
vector<P> a1, a2;

vector<P> oa;
vi oi1, oi2;
P dx1, dx2;
D alpha1, alpha2;

void Generate(int n) {
  ::n = n;
  n1 = rand() % (n / 2) + n;
  n2 = rand() % (n / 2) + n;
  oa.clear();
  oi1.clear();
  oi2.clear();
  a1.clear();
  a2.clear();
  for (int i = 0; i < n; ++i)
    oa.pb(P::rand());
  a1 = oa;
  a2 = oa;
  for (int i = n; i < n1; ++i)
    a1.pb(P::rand());
  for (int i = n; i < n2; ++i)
    a2.pb(P::rand());
  dx1 = P::rand(), dx2 = P::rand();
  alpha1 = rand() * 2.0 / RAND_MAX * PI;
  alpha2 = rand() * 2.0 / RAND_MAX * PI;

  for (int i = 0; i < n1; ++i)
    a1[i] = (a1[i] + dx1).rot(alpha1);
    //a1[i] = (a1[i].rot(alpha1) + dx1);
  for (int i = 0; i < n2; ++i)
    a2[i] = (a2[i] + dx2).rot(alpha2);
    //a2[i] = (a2[i].rot(alpha2) + dx2);
  {
    vector<pair<int, P>> v;
    for (int i = 0; i < sz(a1); ++i) v.eb(i < n ? i : -1, a1[i]);
    //random_shuffle(all(v));
    a1.clear();
    for (int i = 0; i < sz(v); ++i) {
      a1.pb(v[i].second.round());
      oi1.pb(v[i].first);
    }
  }
  {
    vector<pair<int, P>> v;
    for (int i = 0; i < sz(a2); ++i) v.eb(i < n ? i : -1, a2[i]);
    //random_shuffle(all(v));
    a2.clear();
    for (int i = 0; i < sz(v); ++i) {
      a2.pb(v[i].second.round());
      oi2.pb(v[i].first);
    }
  }
}

double Eval(vector<ii> v) {
  assert(n == sz(v));
  D num = 0, den = 0;
  for (ii e : v) {
    if (oi1[e.first] != -1 && oi2[e.second] != -1 && oi1[e.first] == oi2[e.second])
      ++num;
    ++den;
  }
  return num / den;
}

P GetShift(vector<P> v) {
  P s(0, 0);
  for (P p : v)
    s = s + p;
  s = s * (1.0 / sz(v));
  return s;
}

pair<pair<P, P>, double> GetShiftRot(vector<P> v1, vector<P> v2) {
  P shift1 = GetShift(v1);
  for (P& p : v1) p = p - shift1;
  P shift2 = GetShift(v2);
  for (P& p : v2) p = p - shift2;
  P best1(0, 0);
  for (P p : v1) {
    if (p.norm2() > best1.norm2())
      best1 = p;
  }
  P best2(0, 0);
  for (P p : v2) {
    if (p.norm2() > best2.norm2())
      best2 = p;
  }
  double alpha = atan2(best1 & best2, best1 * best2);
  return mp(mp(shift1, shift2), alpha);
}

struct LSH {
  vector<P> a;
  vector<P> base;
  vector<vector<pair<D, int>>> proj;

  LSH(vector<P> a) : a(a) {
    for (int i = 0; i < 4; ++i) {
      P vec = P::rand();
      vec = vec * (1.0 / vec.norm());
      base.pb(vec);
      vector<pair<D, int>> line;
      for (int j = 0; j < sz(a); ++j)
        line.eb(a[j] & vec, j);
      sort(all(line));
      proj.eb(line);
    }
  }

  int closest(P p) {
    int res = 0;
    D rv = 1e100;
    for (int i = 0; i < sz(base); ++i) {
      P vec = base[i];
      D X = p & vec;
      int ind = lower_bound(all(proj[i]), mp(X, -1)) - proj[i].begin();
      for (int j = max(0, ind - 5); j < min(sz(proj[i]), ind + 6); ++j) {
        if (proj[i][j].first <= X - rv) continue;
        if (proj[i][j].first >= X + rv) break;
        int t = proj[i][j].second;
        D cur = (p - a[t]).norm();
        if (cur < rv) {
          rv = cur;
          res = t;
        }
      }
    }
    return res;
    //for (int i = 0; i < sz(a); ++i)
    //  if ((a[i] - p).norm2() < (a[res] - p).norm2())
    //    res = i;
    //return res;
  }
};

vector<ii> GetAns(vector<P> v1, vector<P> v2, bool high_conf=false) {
  LSH l1(v1), l2(v2);
  vi d1(sz(v1), -1);
  for (int i = 0; i < sz(v1); ++i)
    d1[i] = l2.closest(v1[i]);
  vi d2(sz(v2), -1);
  for (int i = 0; i < sz(v2); ++i)
    d2[i] = l1.closest(v2[i]);
  vector<pair<double, ii>> v;
  vi u1(sz(v1), 0), u2(sz(v2), 0);
  vector<ii> res;
  for (int i = 0; i < sz(v1); ++i) {
    if (d2[d1[i]] == i)
      v.eb((v1[i] - v2[d1[i]]).norm2(), ii(i, d1[i]));
  }
  sort(all(v));
  for (int i = 0; i < sz(v) && sz(res) < n; ++i) {
    res.eb(v[i].second);
    u1[v[i].second.first] = true;
    u2[v[i].second.second] = true;
  }
  if (high_conf)
    return res;
  v.clear();
  for (int i = 0; i < sz(v1); ++i) {
    if (d2[d1[i]] != i)
      v.eb((v1[i] - v2[d1[i]]).norm2(), ii(i, d1[i]));
  }
  for (int i = 0; i < sz(v2); ++i) {
    if (d1[d2[i]] != i)
      v.eb((v2[i] - v1[d2[i]]).norm2(), ii(d2[i], i));
  }
  sort(all(v));
  for (int i = 0; i < sz(v) && sz(res) < n; ++i) {
    if (u1[v[i].second.first]) continue;
    if (u2[v[i].second.second]) continue;
    res.eb(v[i].second);
    u1[v[i].second.first] = true;
    u2[v[i].second.second] = true;
  }
  vi ind1, ind2;
  for (int i = 0; i < sz(v1); ++i) if (!u1[i]) ind1.pb(i);
  for (int i = 0; i < sz(v2); ++i) if (!u2[i]) ind2.pb(i);
  for (int i = 0; sz(res) < n; ++i)
    res.pb(ii(ind1[i], ind2[i]));
  assert(sz(res) == n);
  return res;
}

D Score(vector<ii> v, P shift1, D alpha1, P shift2, D alpha2) {
  D res = 0;
  for (ii e : v) {
    res += sqrt(((a2[e.second] - shift2).rot(alpha2) - (a1[e.first] - shift1).rot(alpha1)).norm2());
  }
  return res;
}

vector<ii> Solve() {
  auto shift_rot = GetShiftRot(a1, a2);
  P shift1 = shift_rot.first.first;
  P shift2 = shift_rot.first.second;
  double alpha = shift_rot.second;

  double best_alpha = 0.0;
  double best_score = 1E100;
  for (int i = 0; i < 4; ++i) {
    vector<P> v1 = a1;
    vector<P> v2 = a2;
    for (P& p : v1)
      p = (p - shift1).rot(alpha + PI * i * 0.5);
    for (P& p : v2)
      p = (p - shift2);
    D cur = Score(GetAns(v1, v2), shift1, alpha + PI * i * 0.5, shift2, 0.0);
    if (cur < best_score) {
      best_score = cur;
      best_alpha = PI * i * 0.5;
    }
  }

  vector<ii> res, mega_set;
  D res_score = 1E100;
  int OP = 20;
  if (n > 25000) OP = 200;
  for (int it = 0; it < 100000; ++it) {
    if (it % OP == 0) {
      cerr << "Rot\n";
      vector<P> v1 = a1;
      vector<P> v2 = a2;
      for (P& p : v1)
        p = (p - shift1).rot(alpha + best_alpha);
      for (P& p : v2)
        p = (p - shift2);
      auto t_res = GetAns(v1, v2);
      D t_score = Score(t_res, shift1, alpha + best_alpha, shift2, 0.0);
      if (t_score < res_score) {
        res_score = t_score;
        res = t_res;
      }
//      cerr << "Start score: " << res_score << "\n";
      mega_set = GetAns(v1, v2, true);
      mega_set = vector<ii>(mega_set.begin() + sz(mega_set) / 2,
                            mega_set.begin() + sz(mega_set) / 2 + 100);
      best_alpha += PI * 0.5;
    }
    int ind1 = rand() % sz(mega_set);
    int ind2;
    do {
      ind2 = rand() % sz(mega_set);
    } while (ind1 == ind2);
    int f1 = mega_set[ind1].first, t1 = mega_set[ind1].second;
    int f2 = mega_set[ind2].first, t2 = mega_set[ind2].second;
    D th = 0.5;
    if (n > 40000) th = 0.1;
    if (abs((a1[f1] - a1[f2]).norm() - (a2[t1] - a2[t2]).norm()) > th)
      continue;
    P cs1 = (a1[f1] + a1[f2]) * 0.5;
    P cs2 = (a2[t1] + a2[t2]) * 0.5;
    P p1 = a1[f1] - cs1, p2 = a1[f2] - cs1, q1 = a2[t1] - cs2, q2 = a2[t2] - cs2;
    D cal = atan2(p1 & q1, p1 * q1) + PI * 1.5;
    vector<P> v1 = a1;
    vector<P> v2 = a2;
    for (P& p : v1)
      p = (p - cs1).rot(cal);
    for (P& p : v2)
      p = (p - cs2);
    auto cur = GetAns(v1, v2);
    D cur_score = Score(cur, cs1, cal, cs2, 0.0);
   cerr << "cur score: " << cur_score << "\n";
    if (cur_score < res_score) {
      res_score = cur_score;
      res = cur;
      mega_set = GetAns(v1, v2, true);
      mega_set = vector<ii>(mega_set.begin() + sz(mega_set) / 2,
                            mega_set.begin() + sz(mega_set) / 2 + 100);
    }
    if (res_score < 20.0 * (n / 1000) * 1.0 * (n / 1000)) {
      break;
    }
  }

  return res;
}

int main() {
  //for (int it = 0; it < 100; ++it) {
    //srand(42);
  //Generate(50000);
  scanf("%d%d", &n, &n1);
  a1.resize(n1);
  for (int i = 0; i < n1; ++i)
    scanf("%lf%lf", &a1[i].x, &a1[i].y);
  scanf("%d", &n2);
  a2.resize(n2);
  for (int i = 0; i < n2; ++i)
    scanf("%lf%lf", &a2[i].x, &a2[i].y);
  vector<ii> res = Solve();
  for (int i = 0; i < sz(res); ++i)
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
  //cerr << Eval(res) << "\n";
  //}
  return 0;
}