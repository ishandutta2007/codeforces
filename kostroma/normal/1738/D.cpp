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
#include <bitset>
#include <sstream>
#ifdef PINELY
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
#ifdef PINELY
    freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
    //freopen("/Users/alexandero/Downloads/worklife_balance_chapter_2_input.txt", "r", stdin);
    //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef PINELY
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
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
#ifndef PINELY
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

#ifdef PINELY1
    while (true) {
    solve(false);
  }
#endif

#ifdef PINELY
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

template<typename T>
void print_vec(const vector<T>& vals) {
  for (int x : vals) {
    cout << x << " ";
  }
  cout << endl;
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void precalc() {

}

void solve(__attribute__((unused)) bool read) {
  int n;
  //read = false;

  int K;
  if (read) {
    cin >> n;
  } else {
    n = rand() % 10 + 1;
    K = rand() % (n + 1);
  }
  vector<int> b(n);
  if (read) {
    for (int &x: b) {
      cin >> x;
      --x;
    }
  } else {
    vector<int> p(n);
    iota(all(p), 0);
    shuffle(all(p), rng);
    for (int i = 0; i < n; ++i) {
      if (p[i] < K) {
        b[p[i]] = n;
        for (int j = i - 1; j >= 0; --j) {
          if (p[j] >= K) {
            b[p[i]] = p[j];
            break;
          }
        }
      } else {
        b[p[i]] = -1;
        for (int j = i - 1; j >= 0; --j) {
          if (p[j] < K) {
            b[p[i]] = p[j];
            break;
          }
        }
      }
    }
  }
  int k = -1;
  while (k + 1 < n && b[k + 1] > k + 1) {
    ++k;
  }
  cout << k + 1 << "\n";
  map<int, vector<int>> groups[2];
  set<int> roots;
  for (int i = 0; i < n; ++i) {
    roots.insert(b[i]);
    groups[i > k][b[i]].push_back(i);
  }
  int cur_par = -1, cur_group = -1;
  for (int s = 0; s < 2; ++s) {
    for (auto& item : groups[s]) {
      bool is_last = true;
      for (int x : item.second) {
        if (roots.contains(x)) {
          is_last = false;
          break;
        }
      }
      /*cout << "s: " << s << " group: ";
      for (int x : item.second) {
        cout << x << " ";
      }
      cout << "is_last: " << is_last << " prev: " << b[item.second[0]] << endl;*/
      if (is_last) {
        cur_par = s;
        cur_group = item.first;
        break;
      }
    }
  }
  vector<int> ans;
  assert(cur_par != -1);
  int last_val = -1;
  while (!groups[cur_par].empty()) {
    auto group = groups[cur_par][cur_group];
    groups[cur_par].erase(cur_group);
    auto iter = find(all(group), last_val);
    if (iter != group.end()) {
      swap(group[0], group[iter - group.begin()]);
    }
    for (int x : group) {
      ans.push_back(x);
    }
    last_val = cur_group;
    cur_group = b[last_val];
    cur_par ^= 1;
  }
  reverse(all(ans));
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}