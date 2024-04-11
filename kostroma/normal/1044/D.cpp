#pragma comment(linker, "/STACK:512000000")
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

map<int, int> val_index;
vector<int> values;

struct Dsu {
  vector<int> dsu;
  vector<int> color;
  vector<int> type;
  void add_val() {
    int new_id = dsu.size();
    dsu.push_back(new_id);
    color.push_back(0);
    type.push_back(0);
  }
  int find_set(int v) {
    if (dsu[v] == v) {
      return v;
    }
    int p = dsu[v];
    int res = find_set(dsu[v]);
    color[v] = type[v] ^ color[p];
    type[v] = color[res] ^ color[v];
    return dsu[v] = res;
  }
  bool merge(int q, int w, int edge_type) {
    int Q = q, W = w;
    q = find_set(q);
    w = find_set(w);
    if (q == w) {
      return false;
    }
    type[w] = (color[Q] ^ color[W] ^ edge_type);
    dsu[w] = q;
    return true;
  }
};

void solve(__attribute__((unused)) bool read) {
  Dsu comps;
  int Q;
  //read = false;
  if (read) {
    cin >> Q;
  } else {
    Q = 200000;
  }
  auto get_index = [&] (int val) {
    if (val_index.count(val)) {
      return val_index[val];
    }
    val_index[val] = values.size();
    values.push_back(val);
    comps.add_val();
    return val_index[val];
  };

  auto get_color = [&] (int l, int r) {
    if (comps.find_set(l) != comps.find_set(r)) {
      return -1;
    }
    return comps.color[l] ^ comps.color[r];
  };

  int last_ans = 0;
  while (Q--) {
    int t, l, r;
    if (read) {
      cin >> t >> l >> r;
    } else {
      t = rand() % 2 + 1;
      l = rand() % (1 << 30) + 1;
      r = rand() % (1 << 30) + 1;
    }
    l ^= last_ans;
    r ^= last_ans;
    if (l > r) {
      swap(l, r);
    }
    --l;
    //cout << "process " << l << " " << r << endl;
    l = get_index(l);
    r = get_index(r);
    if (t == 1) {
      int x;
      if (read) {
        cin >> x;
      } else {
        x = rand() % (1 << 30);
      }
      x ^= last_ans;
      int have_col = get_color(l, r);
      if (have_col != -1 && have_col != x) {
        continue;
      }
      comps.merge(l, r, x);
    } else {
      last_ans = get_color(l, r);
      if (read) {
        cout << last_ans << "\n";
      }
      if (last_ans == -1) {
        last_ans = 1;
      }
    }
  }
}