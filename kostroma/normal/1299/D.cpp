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
const int mod = 1000000007;

const int L = 32;

bool get_bit(size_t mask, int pos) {
  return (bool)(mask & (1UL << pos));
}

size_t append(size_t mask, int pos) {
  if (get_bit(mask, pos)) {
    return mask;
  }
  for (int i = 0; i < L; ++i) {
    if (get_bit(mask, i)) {
      int new_pos = (pos ^ i);
      if (!get_bit(mask, new_pos)) {
        mask |= (1UL << new_pos);
      }
    }
  }
  return mask;
}

struct Edge {
  int to, cost;
};

void add(int& cur, int val) {
  cur = (cur + val) % mod;
}

void solve(__attribute__((unused)) bool read) {
  vector<size_t> spaces = {1};
  set<size_t> have_spaces;
  have_spaces.insert(spaces[0]);
  map<size_t, size_t> raw_g[L];
  map<size_t, int> mask_order;
  mask_order[spaces[0]] = 0;
  int cnt_order = 0;
  while (true) {
    ++cnt_order;
    vector<size_t> new_spaces;
    for (size_t mask : spaces) {
      for (int i = 0; i < L; ++i) {
        size_t new_mask = append(mask, i);
        raw_g[i][mask] = new_mask;
        if (!have_spaces.count(new_mask)) {
          have_spaces.insert(new_mask);
          new_spaces.push_back(new_mask);
        }
      }
    }
    if (new_spaces.empty()) {
      break;
    }
    for (size_t mask : new_spaces) {
      spaces.push_back(mask);
      mask_order[mask] = cnt_order;
    }
  }
  //cout << spaces.size() << endl;
  sort(all(spaces));
  map<int, int> mask_g[L];
  auto get_mask_index = [&] (size_t mask) {
    return lower_bound(all(spaces), mask) - spaces.begin();
  };
  for (int i = 0; i < L; ++i) {
    for (auto item : raw_g[i]) {
      mask_g[i][get_mask_index(item.first)] = get_mask_index(item.second);
    }
  }
  vector<vector<int>> matrix(spaces.size(), vector<int>(spaces.size()));
  for (int i = 0; i < spaces.size(); ++i) {
    for (int j = 0; j < spaces.size(); ++j) {
      size_t mask = spaces[i];
      for (int pos = 0; pos < L; ++pos) {
        if (get_bit(spaces[j], pos)) {
          mask = append(mask, pos);
        }
      }
      matrix[i][j] = get_mask_index(mask);
    }
  }

  //read = false;

  int n, m;
  if (read) {
    cin >> n >> m;
  } else {
    n = m = 100000;
  }
  vector<vector<Edge>> g(n);
  vector<char> is_nei(n, false);
  for (int i = 0; i < m; ++i) {
    int a, b, cost;
    cin >> a >> b >> cost;
    --a; --b;
    if (a > b) {
      swap(a, b);
    }
    g[a].push_back({b, cost});
    g[b].push_back({a, cost});
    if (a == 0) {
      is_nei[b] = true;
    }
  }

  vector<int> num_comp(n, -1);
  vector<int> prefix_xor(n, 0);
  vector<int> parent(n, -1);
  vector<int> comp_spaces;
  int n_comps = 0;
  vector<vector<int>> paired(n);
  vector<vector<int>> edge_between(n);
  vector<int> edge_to(n);
  for (int i = 1; i < n; ++i) {
    if (num_comp[i] == -1) {
      vector<int> comp;
      comp.push_back(i);
      num_comp[i] = n_comps;
      bool found = false;
      for (int j = 0; j < comp.size(); ++j) {
        int v = comp[j];
        for (auto e : g[v]) {
          if (e.to == 0) {
            edge_to[n_comps] = e.cost;
            continue;
          }
          if (is_nei[v] && is_nei[e.to]) {
            if (num_comp[e.to] != -1) {
              paired[num_comp[e.to]].push_back(n_comps);
              edge_between[num_comp[e.to]].push_back(e.cost);
              found = true;
            }
            continue;
          }
          if (num_comp[e.to] != -1) {
            continue;
          }
          parent[e.to] = v;
          prefix_xor[e.to] = (prefix_xor[v] ^ e.cost);
          num_comp[e.to] = n_comps;
          comp.push_back(e.to);
        }
      }
      if (!found) {
        paired[n_comps].push_back(n_comps);
      }
      ++n_comps;
      int current_space = 0;
      for (int v : comp) {
        for (auto e : g[v]) {
          if (e.to > v) {
            continue;
          }
          if (num_comp[e.to] == num_comp[v] && parent[e.to] != v && parent[v] != e.to) {
            int new_num = (prefix_xor[v] ^ prefix_xor[e.to] ^ e.cost);
            int new_space = mask_g[new_num][current_space];
            //cout << "append " << new_num << endl;
            if (new_space == current_space) {
              current_space = -1;
              break;
            }
            current_space = new_space;
          }
        }
        if (current_space == -1) {
          break;
        }
      }
      comp_spaces.push_back(current_space);
      //cout << i << " " << current_space << " " << spaces[current_space] << endl;
    }
  }

  vector<int> m_order(spaces.size());
  for (int i = 0; i < spaces.size(); ++i) {
    m_order[i] = mask_order[spaces[i]];
  }

  auto is_independent = [&] (int m1, int m2, int m3) {
    return m_order[m1] + m_order[m2] == m_order[m3];
  };

  vector<vector<int>> dp(n_comps + 1, vector<int>(spaces.size(), 0));
  dp[0][0] = 1;
  for (int pref = 0; pref < n_comps; ++pref) {
    dp[pref + 1] = dp[pref];
    if (paired[pref].empty()) {
      continue;
    }
    if (paired[pref].size() == 1) {
      int other_mask = comp_spaces[pref];
      if (other_mask == -1) {
        continue;
      }
      for (int mask = 0; mask < dp[pref].size(); ++mask) {
        if (!dp[pref][mask]) {
          continue;
        }
        int new_mask = matrix[mask][other_mask];
        if (is_independent(mask, other_mask, new_mask)) {
          add(dp[pref + 1][new_mask], dp[pref][mask]);
        }
      }
      continue;
    }
    assert(paired[pref].size() == 2);
    int between = edge_between[pref][0];
    vector<int> cur_spaces;
    for (int comp : paired[pref]) {
      between ^= edge_to[comp];
      cur_spaces.push_back(comp_spaces[comp]);
    }
    for (int outer_mask = 1; outer_mask < 4; ++outer_mask) {
      for (int mask = 0; mask < dp[pref].size(); ++mask) {
        if (!dp[pref][mask]) {
          continue;
        }
        int cur_mask = mask;
        for (int i = 0; i < cur_spaces.size(); ++i) {
          if (cur_spaces[i] == -1) {
            cur_mask = -1;
            break;
          }
          int next_mask = matrix[cur_mask][cur_spaces[i]];
          if (!is_independent(cur_mask, cur_spaces[i], next_mask)) {
            cur_mask = -1;
            break;
          }
          cur_mask = next_mask;
        }
        if (cur_mask == -1) {
          continue;
        }
        if (outer_mask == 3) {
          int next_mask = mask_g[between][cur_mask];
          if (cur_mask == next_mask) {
            cur_mask = -1;
          } else {
            cur_mask = next_mask;
          }
        }
        if (cur_mask != -1) {
          //cout << "pref: " << pref << " " << outer_mask << " " << dp[pref][mask] << endl;
          add(dp[pref + 1][cur_mask], dp[pref][mask]);
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < dp.back().size(); ++i) {
    add(res, dp.back()[i]);
  }
  cout << res << endl;

}