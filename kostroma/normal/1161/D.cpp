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
const int mod = 998244353;

void add(int& cur, int val) {
  cur += val;
  if (cur >= mod) {
    cur -= mod;
  }
}

struct Dsu {
  vector<int> dsu;
  Dsu(int n) {
    dsu.resize(n);
    iota(all(dsu), 0);
  }
  int find_set(int v) {
    if (dsu[v] == v) {
      return v;
    }
    return dsu[v] = find_set(dsu[v]);
  }
  void merge(int q, int w) {
    q = find_set(q);
    w = find_set(w);
    dsu[w] = q;
  }
};

int get_res(string s, int n, int len) {
  Dsu dsu(n + len);
  vector<vector<int>> fixed_vals(2);
  fixed_vals[1].push_back(0);
  fixed_vals[1].push_back(n);
  for (int i = 0; i < n; ++i) {
    dsu.merge(i, n - i - 1);
  }
  for (int i = 0; i < len; ++i) {
    dsu.merge(n + i, n + len - i - 1);
  }
  vector<vector<int>> different;
  for (int i = 1; i < n; ++i) {
    char c = s[i];
    if (c != '?') {
      int val = (c - '0');
      if (i < n - len) {
        fixed_vals[val].push_back(i);
        continue;
      }
      if (val == 0) {
        dsu.merge(i, i + len);
      } else {
        different.push_back({i, i + len});
      }
    }
  }
  for (auto& vec : fixed_vals) {
    for (int i = 0; i + 1 < vec.size(); ++i) {
      dsu.merge(vec[i], vec[i + 1]);
    }
  }
  /*cout << "len: " << len << endl;
  for (int i = 0; i < dsu.dsu.size(); ++i) {
    cout << i << " " << dsu.find_set(i) << endl;
  }
  cout << "finished" << endl;*/
  if (!fixed_vals[0].empty() && !fixed_vals[1].empty()) {
    different.push_back({fixed_vals[0][0], fixed_vals[1][0]});
  }
  vector<vector<int>> g(n + len);
  for (auto& item : different) {
    int q = dsu.find_set(item[0]);
    int w = dsu.find_set(item[1]);
    if (q == w) {
      return 0;
    }
    //cout << "diff: " << q << " " << w << endl;
    g[q].push_back(w);
    g[w].push_back(q);
  }
  vector<int> color(n + len, -1);
  int cnt = 0;
  for (int st = 0; st < n + len; ++st) {
    if (dsu.find_set(st) != st || color[st] != -1) {
      continue;
    }
    color[st] = cnt * 2;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : g[v]) {
        if (color[to] == -1) {
          color[to] = color[v] ^ 1;
          q.push(to);
        }
      }
    }
    ++cnt;
  }
  for (int i = 0; i < g.size(); ++i) {
    for (int to : g[i]) {
      if (color[i] == color[to]) {
        return 0;
      }
    }
  }
  vector<char> is_fixed(cnt, false);
  for (int val = 0; val < 2; ++val) {
    for (int v : fixed_vals[val]) {
      is_fixed[color[dsu.find_set(v)] / 2] = true;
    }
  }
  int res = 1;
  for (int i = 0; i < cnt; ++i) {
    if (!is_fixed[i]) {
      res = res * 2 % mod;
    }
  }
  //cout << len << " " << res << endl;
  return res;
}

void solve(__attribute__((unused)) bool read) {
  string s;
  //read = false;
  if (read) {
    cin >> s;
  } else {
    s = "1";
    for (int i = 0; i < 999; ++i) {
      s += "?01"[rand() % 3];
    }
  }
  int n = (int)s.length();
  int ans = 0;
  for (int len = 1; len < n; ++len) {
    //if (len != 3) continue;
    add(ans, get_res(s, n, len));
  }
  cout << ans << endl;
}