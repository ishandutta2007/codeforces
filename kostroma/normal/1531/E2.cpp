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
    //cin >> t;
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

string s;
vector<vector<int>> pref_sums;
vector<vector<int>> poses;
vector<map<pair<int, int>, int>> dp;

pair<int, int> get_jump(int pos, int l, int r) {
  int mid = (l + r) / 2;
  int last = s[pos] - '0';
  int need = (last == 0 ? mid - l : r - mid);
  int bigger = upper_bound(all(poses[last]), pos) - poses[last].begin();
  if (bigger < need) {
    return {-1, -1};
  }
  int candy = poses[last][bigger - need];
  int opposite_count = pref_sums[pos][last ^ 1] - pref_sums[candy][last ^ 1];
  int max_opposite_count = r - l - need;
  if (opposite_count >= max_opposite_count) {
    return {-1, -1};
  }
  int min_candy = max(candy - (max_opposite_count - opposite_count - 1),
      (bigger > need ? poses[last][bigger - need - 1] + 1 : 0));
  //cout << "jump pos: " << pos << " l: " << l << " r: " << r << " candy: " << min_candy << " " << candy << endl;
  return {min_candy, candy};
}

int get_pos(int pos, int l, int r) {
  if (r - l <= 1) {
    return pos;
  }
  if (pos == -1) {
    return -2;
  }
  if (dp[pos].count({l, r})) {
    return dp[pos][{l, r}];
  }
  auto possible = get_jump(pos, l, r);
  if (possible.first == -1) {
    return dp[pos][{l, r}] = -2;
  }

  //cout << pos << " " << l << " " << r << " " << possible.first << " " << possible.second << endl;
  int mid = (l + r) / 2;
  for (int div = possible.first; div <= possible.second; ++div) {
    int new_pos = get_pos(div - 1, mid, r);
    if (new_pos == -2) {
      continue;
    }
    //cout << "new_pos: " << new_pos << " l: " << l << " mid: " << mid << endl;
    new_pos = get_pos(new_pos, l, mid);
    if (new_pos != -2) {
      //cout << "found pos: " << pos << " l: " << l << " r: " << r << endl;
      return dp[pos][{l, r}] = new_pos;
    }
  }
  //cout << "failed pos: " << pos << " l: " << l << " r: " << r << endl;
  return -2;
}

vector<vector<int>> g;

bool my_merge_sort(vector<int>& perm, int l, int r, int& pos) {
  if (r - l <= 1) {
    return true;
  }
  int m = (l + r) / 2;
  if (!my_merge_sort(perm, l, m, pos)) {
    return false;
  }
  if (!my_merge_sort(perm, m, r, pos)) {
    return false;
  }
  int i = l, j = m;
  vector<int> b;
  while (i < m && j < r) {
    if (pos == s.length()) {
      return false;
    }
    if (s[pos++] == '0') {
      g[perm[i]].push_back(perm[j]);
      b.push_back(perm[i]);
      ++i;
    } else {
      g[perm[j]].push_back(perm[i]);
      b.push_back(perm[j]);
      ++j;
    }
  }
  while (i < m) {
    b.push_back(perm[i++]);
  }
  while (j < r) {
    b.push_back(perm[j++]);
  }
  for (int w = 0; w < b.size(); ++w) {
    perm[l + w] = b[w];
  }
  return true;
}

string output(vector<int>& perm, int l, int r) {
  if (r - l <= 1) {
    return "";
  }
  int m = (l + r) / 2;
  auto res = output(perm, l, m);
  res += output(perm, m, r);
  int i = l, j = m;
  vector<int> b;
  while (i < m && j < r) {
    if (perm[i] < perm[j]) {
      res += '0';
      b.push_back(perm[i]);
      ++i;
    } else {
      res += '1';
      b.push_back(perm[j]);
      ++j;
    }
  }
  while (i < m) {
    b.push_back(perm[i++]);
  }
  while (j < r) {
    b.push_back(perm[j++]);
  }
  for (int w = 0; w < b.size(); ++w) {
    perm[l + w] = b[w];
  }
  return res;
}

enum How {
  LESS = 0,
  EQ = 1,
  MORE = 2
};

void solve(__attribute__((unused)) bool read) {
  cin >> s;

  vector<int> res;

  auto sub_solve = [&] (int n) {
    g.clear();
    g.resize(n);
    vector<int> perm(n);
    iota(all(perm), 0);
    int st = 0;
    if (!my_merge_sort(perm, 0, n, st)) {
      return MORE;
    }
    if (st != s.length()) {
      return LESS;
    }
    vector<int> deg(n, 0);
    for (int v = 0; v < n; ++v) {
      for (int to : g[v]) {
        ++deg[to];
      }
    }
    queue<int> q;
    for (int v = 0; v < n; ++v) {
      if (deg[v] == 0) {
        q.push(v);
      }
    }
    res.assign(n, -1);
    int cnt = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      res[v] = cnt++;
      for (int to : g[v]) {
        --deg[to];
        if (deg[to] == 0) {
          q.push(to);
        }
      }
    }
    return EQ;
  };

  auto print_res = [&] () {
    cout << res.size() << "\n";
    for (int x : res) {
      cout << x + 1 << " ";
    }
    cout << endl;
  };

  int L = 0, R = 100005;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    auto cur_res = sub_solve(M);
    if (cur_res == EQ) {
      print_res();
      return;
    } else if (cur_res == LESS) {
      L = M;
    } else {
      R = M;
    }
  }
  assert(false);


  poses.resize(2);
  pref_sums.assign(s.length() + 1, vector<int>(2, 0));
  for (int i = 0; i < s.length(); ++i) {
    poses[s[i] - '0'].push_back(i);
    pref_sums[i + 1] = pref_sums[i];
    ++pref_sums[i + 1][s[i] - '0'];
  }
  vector<int> suf_count(2, 0);
  int last = s.back() - '0';
  dp.resize(s.length() + 1);
  for (int i = (int)s.length() - 1; i >= 0; --i) {
    ++suf_count[s[i] - '0'];
    for (int h = 0; h < 2; ++h) {
      int n = suf_count[last] * 2 + (last == 0 ? h : -h);
      if (n - suf_count[last] > suf_count[last ^ 1]) {
        auto fin = get_pos((int)s.length() - 1, 0, n);
        if (fin == -1) {
          g.clear();
          g.resize(n);
          vector<int> perm(n);
          iota(all(perm), 0);
          int st = 0;
          my_merge_sort(perm, 0, n, st);
          vector<int> deg(n, 0);
          for (int v = 0; v < n; ++v) {
            for (int to : g[v]) {
              ++deg[to];
            }
          }
          queue<int> q;
          for (int v = 0; v < n; ++v) {
            if (deg[v] == 0) {
              q.push(v);
            }
          }
          vector<int> res(n, -1);
          int cnt = 0;
          while (!q.empty()) {
            int v = q.front();
            q.pop();
            res[v] = cnt++;
            for (int to : g[v]) {
              --deg[to];
              if (deg[to] == 0) {
                q.push(to);
              }
            }
          }
          cout << n << "\n";
          for (int x : res) {
            cout << x + 1 << " ";
          }
          cout << endl;
          cout << s << endl;
          cout << output(perm, 0, n) << endl;
          return;
        }
      }
    }
  }
  assert(false);

}