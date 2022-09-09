#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
//freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  start = clock();
  int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
    solve(false);
  }
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

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
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

#define int li
//const li mod = 1000000007;
//const li mod = 998244353;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n;
  cin >> n;
  vector<vector<int>> vals(n);
  vector<int> initial_sum(n, 0);
  int overall_sum = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    vals[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> vals[i][j];
      initial_sum[i] += vals[i][j];
    }
    make_unique(vals[i]);
    overall_sum += initial_sum[i];
  }
  if (overall_sum % n) {
    cout << "No\n";
    return;
  }
  int need_every = overall_sum / n;
  vector<vector<pair<int, int>>> edges(n);
  for (int i = 0; i < n; ++i) {
    edges[i].assign(vals[i].size(), {-1, -1});
    if (initial_sum[i] == need_every) {
      continue;
    }
    for (int to_erase = 0; to_erase < vals[i].size(); ++to_erase) {
      int need_rest = need_every - initial_sum[i] + vals[i][to_erase];
      //cout << i << " " << vals[i][to_erase] << " " << need_rest << endl;
      for (int nex = 0; nex < n; ++nex) {
        if (nex == i) {
          continue;
        }
        auto it = lower_bound(all(vals[nex]), need_rest);
        if (it != vals[nex].end() && *it == need_rest) {
          edges[i][to_erase] = {nex, it - vals[nex].begin()};
          //cout << i << " " << vals[i][to_erase] << " " << nex << " " << vals[nex][edges[i][to_erase].second] << endl;
          break;
        }
      }
    }
  }
  vector<vector<pair<int, int>>> good_cycles(1 << n);
  int start_mask = 0;
  for (int i = 0; i < n; ++i) {
    if (initial_sum[i] == need_every) {
      start_mask |= (1 << i);
      continue;
    }
    for (int s = 0; s < vals[i].size(); ++s) {
      vector<pair<int, int>> cycle;
      cycle.push_back({i, s});
      int cur_box = i, cur_index = s;
      int mask = (1 << cur_box);
      bool f = true;
      while (edges[cur_box][cur_index].first != -1 && edges[cur_box][cur_index].first != i) {
        int new_box = edges[cur_box][cur_index].first;
        cur_index = edges[cur_box][cur_index].second;
        cur_box = new_box;
        if (mask & (1 << cur_box)) {
          f = false;
          break;
        }
        mask |= (1 << cur_box);
        cycle.push_back({cur_box, cur_index});
      }
      if (f && edges[cur_box][cur_index].first == i && edges[cur_box][cur_index].second == s) {
        good_cycles[mask] = cycle;
      }
    }
  }
  vector<int> dp(1 << n, -1);
  dp[start_mask] = 0;
  for (int mask = start_mask + 1; mask < (1 << n); ++mask) {
    for (int s = mask; s > 0; s = (s - 1) & mask) {
      if (dp[mask ^ s] == -1) {
        continue;
      }
      if (!good_cycles[s].empty()) {
        dp[mask] = (mask ^ s);
        break;
      }
    }
  }
  auto cur_mask = dp[(1 << n) - 1];
  if (cur_mask == -1) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  cur_mask = (1 << n) - 1;
  vector<pair<int, int>> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = {0, i};
  }
  while (cur_mask != start_mask) {
    int s = (dp[cur_mask] ^ cur_mask);
    for (int j = 0; j < good_cycles[s].size(); ++j) {
      int prev_index = j - 1;
      if (prev_index < 0) {
        prev_index = (int)good_cycles[s].size() - 1;
      }
      ans[good_cycles[s][j].first] = {good_cycles[s][j].second, good_cycles[s][prev_index].first};
    }
    cur_mask = dp[cur_mask];
  }
  for (int i = 0; i < n; ++i) {
    cout << vals[i][ans[i].first] << " " << ans[i].second + 1 << endl;
  }

}