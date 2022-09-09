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

void solve(__attribute__((unused)) bool read) {
  int n;
  if (read) {
    cin >> n;
  } else {
    n = rand() % 10 + 1;
  }
  vector<vector<int>> poses(4);
  for (int i = 0; i < n; ++i) {
    int val;
    if (read) {
      cin >> val;
    } else {
      val = rand() % 4;
    }
    poses[val].push_back(i);
  }
  vector<pair<int, int>> ans;
  int row = n - 1;
  set<pair<int, int>> ones;
  auto impossible = [&] () {
    cout << "-1\n";
    //exit(0);
  };

  while (!poses[1].empty()) {
    int pos = poses[1].back();
    poses[1].pop_back();
    ans.emplace_back(row, pos);
    ones.insert({pos, row});
    --row;
  }
  set<pair<int, int>> twos;
  while (!poses[2].empty()) {
    int pos = poses[2].back();
    poses[2].pop_back();
    auto it = ones.lower_bound(make_pair(pos, 0));
    if (it == ones.end()) {
      impossible();
      return;
    }
    int cur_row = it->second;
    ans.emplace_back(cur_row, pos);
    twos.insert({pos, cur_row});
    ones.erase(it);
  }

  while (!poses[3].empty()) {
    int pos = poses[3].back();
    poses[3].pop_back();

    auto one_it = ones.lower_bound(make_pair(pos, 0));
    auto two_it = twos.lower_bound(make_pair(pos, 0));
    if (one_it == ones.end() || (two_it != twos.end() && one_it->first > two_it->first)) {
      if (two_it == twos.end()) {
        impossible();
        return;
      }
      int cur_column = two_it->first;
      ans.emplace_back(row, pos);
      ans.emplace_back(row, cur_column);
      twos.erase(two_it);
      ones.insert({pos, row});
      --row;
    } else {
      int cur_column = one_it->first;
      ans.emplace_back(row, pos);
      ans.emplace_back(row, cur_column);
      ones.erase(one_it);
      ones.insert({pos, row});
      --row;
    }
  }

  cout << ans.size() << "\n";
  for (auto item : ans) {
    cout << item.first + 1 << " " << item.second + 1 << "\n";
  }

#if 0
  vector<int> rows(n), cols(n);
  for (auto item : ans) {
    ++rows[item.first];
    ++cols[item.second];
  }
  for (int i = 0; i < n; ++i) {
    assert(rows[i] <= 2);
    assert(cols[i] <= 2);
  }
#endif

}