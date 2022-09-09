#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>

using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
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

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

vector<vector<int>> g;

int dfs(int v, vector<int>& res) {
  if (g[v].empty()) {
    return v;
  }
  vector<pair<int, int>> paths;
  for (int to : g[v]) {
    int st = dfs(to, res);
    paths.emplace_back(st, to);
  }
  for (int i = 0; i < paths.size(); ++i) {
    res[paths[i].second] = (i + 1 < paths.size() ? paths[i + 1].first : v);
  }
  return paths[0].first;
}

void solve(__attribute__((unused)) bool read) {
  vector<int> cnt(26, 0);
  string init;
  cin >> init;
  sort(all(init));
  if (init[0] == init.back()) {
    cout << init << "\n";
    return;
  }
  int n = (int)init.length();
  for (auto c : init) {
    ++cnt[c - 'a'];
  }
  for (int c = 0; c < 26; ++c) {
    if (cnt[c] == 1) {
      auto it = find(all(init), (char)('a' + c));
      assert(it != init.end());
      swap(init[0], init[it - init.begin()]);
      sort(init.begin() + 1, init.end());
      cout << init << "\n";
      return;
    }
  }

  for (int c = 0; c < 26; ++c) {
    if (cnt[c] == 0) {
      continue;
    }
    vector<int> ans;

    auto append = [&] (int num) {
      assert(cnt[num] > 0);
      ans.push_back(num);
      --cnt[num];
    };

    auto print_ans = [&] () {
      string result;
      for (int x : ans) {
        result += (char)('a' + x);
      }
      cout << result << "\n";
    };

    auto fill_by_second = [&] (int second) {
      append(c);
      append(second);
      for (int b = 0; b < 26; ++b) {
        while (cnt[b] > 0) {
          append(b);
        }
      }
    };

    auto print_by_second = [&] (int second) {
      fill_by_second(second);
      print_ans();
    };

    for (int second = 0; second < c; ++second) {
      if (cnt[second] == 0) {
        continue;
      }
      print_by_second(second);
      return;
    }
    if (cnt[c] <= n - cnt[c] + 2) {
      for (int i = 0; i < 2; ++i) {
        append(c);
      }
      while (ans.size() < n) {
        bool found = false;
        if (ans.back() == c) {
          for (int b = 0; b < 26; ++b) {
            if (b == c) {
              continue;
            }
            if (cnt[b] > 0) {
              found = true;
              append(b);
              break;
            }
          }
        } else {
          int rest = n - (int) ans.size();
          if (cnt[c] * 2 > rest) {
            append(c);
            found = true;
          } else {
            for (int b = 0; b < 26; ++b) {
              if (cnt[b] > 0) {
                found = true;
                append(b);
                break;
              }
            }
          }
        }
        assert(found);
      }
      print_ans();
      return;
    }

    bool was_non_empty = false;
    for (int second = c + 1; second < 26; ++second) {
      if (cnt[second] == 0) {
        continue;
      }
      if (was_non_empty) {
        print_by_second(second);
        return;
      }
      was_non_empty = true;
      fill_by_second(second);
      bool is_good = true;
      for (int i = 1; i + 1 < ans.size(); ++i) {
        if (ans[i] == c && ans[i + 1] == second) {
          is_good = false;
          if (ans.back() != second) {
            is_good = true;
            for (int j = i + 2; j < ans.size(); ++j) {
              if (ans[j] != second) {
                swap(ans[j], ans[i + 1]);
                break;
              }
            }
          }
        }
      }
      if (is_good) {
        print_ans();
        return;
      }
      reverse(ans.begin() + 2, ans.end());
      print_ans();
      return;
    }

  }
  assert(false);
}