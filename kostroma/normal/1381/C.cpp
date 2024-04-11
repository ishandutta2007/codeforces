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
  cin >> t;
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

void solve(__attribute__((unused)) bool read) {
  int n, x, y;
  if (read) {
    cin >> n >> x >> y;
  } else {
    n = rand() % 4 + 1;
  }
  vector<vector<int>> poses(n + 1);
  vector<int> inp(n);
  if (read) {
    for (int i = 0; i < n; ++i) {
      int cur;
      cin >> cur;
      --cur;
      inp[i] = cur;
      poses[cur].push_back(i);
    }
  } else {
    x = y = 0;
    vector<int> ans(n);
    map<int, int> mapa1, mapa2;
    for (int i = 0; i < n; ++i) {
      inp[i] = rand() % (n + 1);
      ans[i] = rand() % (n + 1);
      ++mapa1[inp[i]];
      ++mapa2[ans[i]];
      x += (ans[i] == inp[i]);
      poses[inp[i]].push_back(i);
    }
    for (auto item : mapa1) {
      y += min(item.second, mapa2[item.first]);
    }
    /*y = rand() % (n + 1);
    x = rand() % (y + 1);*/
  }
  int free_color = -1;
  for (int i = 0; i < poses.size(); ++i) {
    if (poses[i].empty()) {
      free_color = i;
      break;
    }
  }
  assert(free_color != -1);
  int free_vals = n - y;
  vector<int> res(n, -1);
  set<pair<int, int>> counts;

  auto try_insert = [&] (int val) {
    if (!poses[val].empty()) {
      counts.insert({poses[val].size(), val});
    }
  };

  for (int i = 0; i < poses.size(); ++i) {
    if (!poses[i].empty()) {
      counts.insert({poses[i].size(), i});
    }
  }

  int set_vals = 0;
  while (set_vals < x) {
    auto it = --counts.end();
    int index = it->second;
    counts.erase(it);
    res[poses[index].back()] = index;
    poses[index].pop_back();
    ++set_vals;
    try_insert(index);
  }
  int need_change = y - x;
  if (need_change % 2 && free_vals == 0) {
    if (counts.size() < 3 || need_change == 1) {
      cout << "NO\n";
      assert(read);
      return;
    }
    vector<int> indices;
    for (auto it = counts.rbegin(); it != counts.rend() && indices.size() < 3; ++it) {
      indices.push_back(it->second);
    }
    assert(indices.size() == 3);
    for (int i = 0; i < 3; ++i) {
      int old_val = indices[i];
      int new_val = indices[(i + 1) % 3];
      res[poses[old_val].back()] = new_val;
      counts.erase({poses[old_val].size(), old_val});
      poses[old_val].pop_back();
      try_insert(old_val);
    }
    need_change -= 3;
  }
  while (counts.size() >= 2 && need_change >= 2) {
    auto max_it = --counts.end();
    auto second_it = prev(max_it);
    int a = max_it->second, b = second_it->second;
    assert(second_it->first > 0);
    counts.erase(max_it);
    counts.erase(second_it);
    res[poses[a].back()] = b;
    res[poses[b].back()] = a;
    poses[a].pop_back();
    poses[b].pop_back();
    try_insert(a);
    try_insert(b);
    need_change -= 2;
  }
  if (need_change >= 2) {
    cout << "NO\n";
    assert(read);
    return;
  }
  if (need_change == 1) {
    assert(free_vals > 0);
    assert(!counts.empty());
    int a = counts.begin()->second;
    assert(!poses[a].empty());
    res[poses[a].back()] = free_color;
    bool found = false;
    for (int i = 0; i < n; ++i) {
      if (res[i] == -1 && inp[i] != a) {
        res[i] = a;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO\n";
      assert(read);
      return;
    }
    need_change = 0;
  }
  for (int& v : res) {
    if (v == -1) {
      v = free_color;
    }
  }
  cout << "YES\n";
  for (int v : res) {
    assert(v != -1);
    cout << v + 1 << " ";
  }
  cout << endl;

#ifdef AIM
  int X = 0, Y = 0;
  map<int, int> mapa1, mapa2;
  for (int i = 0; i < n; ++i) {
    X += (res[i] == inp[i]);
    ++mapa1[res[i]];
    ++mapa2[inp[i]];
  }
  for (auto item : mapa1) {
    Y += min(item.second, mapa2[item.first]);
  }
  cerr << "X: " << X << " Y: "  << Y << " ok: " << (x == X && y == Y) << endl;
  /*cout << n << " " << x << " " << y << endl;
  for (int v : inp) {
    cout << v + 1 << " ";
  }
  cout << endl;*/
  assert(x == X && y == Y);
#endif

}