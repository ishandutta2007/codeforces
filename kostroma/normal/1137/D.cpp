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
  //freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
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

int T, C;
vector<int> poses;
bool local = false;

int shift_one(int v) {
  if (v < T + C - 1) {
    return v + 1;
  }
  return T;
}

int queries = 0;
void generate() {
  queries = 0;
  /*T = 2;
  C = 3;
  return;*/
  do {
    C = rand() % 1000 + 2;
    T = rand() % 1000 + 1;
  } while (T + C > 1000);
  cout << "solve " << T << " " << C << " allowed: " << 3 * (T + C) << endl;
}

vector<vector<int>> shift(vector<int> vec) {
  ++queries;
  if (local) {
    assert(queries <= 3 * (T + C));
    for (int x : vec) {
      poses[x] = shift_one(poses[x]);
    }
    map<int, vector<int>> mapa;
    for (int i = 0; i < poses.size(); ++i) {
      mapa[poses[i]].push_back(i);
      //cout << poses[i] << " ";
    }
    //cout << endl;
    vector<vector<int>> res;
    for (auto item : mapa) {
      res.push_back({});
      for (int x : item.second) {
        res.back().push_back(x);
      }
    }
    return res;
  } else {
    cout << "next";
    for (int v : vec) {
      cout << " " << v;
    }
    cout << endl;
    int n;
    cin >> n;
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
      res.push_back({});
      string s;
      cin >> s;
      for (char c : s) {
        res.back().push_back(c - '0');
      }
    }
    return res;
  }
}

vector<int> get_comps(vector<int> vec) {
  auto res = shift(vec);
  vector<int> ans(10);
  for (int i = 0; i < res.size(); ++i) {
    for (int v : res[i]) {
      ans[v] = i;
    }
  }
  return ans;
}

void solve(__attribute__((unused)) bool read) {
  poses.assign(10, 0);
  if (local) {
    generate();
  }

  int turns = 0;
  while (true) {
    ++turns;
    get_comps({0});
    auto res = get_comps({0, 1});
    if (res[0] == res[1]) {
      break;
    }
  }
  int cycle_len = 0;
  while (true) {
    auto res = get_comps({0});
    ++cycle_len;
    if (res[0] == res[1]) {
      break;
    }
  }
  //cout << "found len: " << cycle_len << " queries: " << queries << endl;
  int sum = turns;
  /*while (true) {
    auto res = get_comps({2});
    ++sum;
    if (res[2] == res[0]) {
      break;
    }
  }*/
  //cout << "found sum: " << sum << " queries: " << queries << endl;
  vector<int> al = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> rest = {2, 3, 4, 5, 6, 7, 8, 9};
  int t = 1;
  int i = sum - t;
  while (i >= cycle_len) {
    --i;
    ++t;
  }
  vector<int> cur_comps;
  int a = cycle_len - i;
  int b = t;
  while (a > 0 && b > 0) {
    cur_comps = get_comps(al);
    --a;
    --b;
  }
  while (a > 0) {
    cur_comps = get_comps({0, 1});
    --a;
  }
  while (b > 0) {
    cur_comps = get_comps(rest);
    --b;
  }

  //cout << "start search queries: " << queries << endl;

  while (cur_comps[3] != cur_comps[0]) {
    cur_comps = get_comps(al);
  }

  //cout << "done queries: " << queries << endl;

  sort(all(cur_comps));
  assert(cur_comps[0] == cur_comps.back());
  if (local) {
    assert(poses[0] == T);
  }
  cout << "done" << endl;

}