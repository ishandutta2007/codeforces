//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>

#define BITSET_ITER(i, bt) for (auto i = bt._Find_first(); i != bt.size();\
i = bt._Find_next(i))

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::map;
using std::set;
using std::pair;
using std::tuple;
using std::unique_ptr;
using std::shared_ptr;
using std::unordered_map;
using std::unordered_set;
using std::multiset;
using std::sort;
using std::reverse;
using std::function;
using std::make_pair;
using std::make_tuple;
using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;

#ifdef GOLIKOV
std::mt19937 rng(566);
#else
std::mt19937 rng(static_cast<unsigned>(std::chrono::high_resolution_clock::now()
.time_since_epoch().count()));
#endif

template <typename T>
T rnd(T l, T r) {
  if constexpr (std::is_integral_v<T>) {
    return std::uniform_int_distribution<T>(l, r)(rng);
  } else {
    return std::uniform_real_distribution<T>(l, r)(rng);
  }
}

template <typename T>
auto make_vector() {
  return T();
}

template <typename T, typename... Args>
auto make_vector(size_t n, Args... args) {
  return vector(n, make_vector<T>(args...));
}

template <typename... Args>
void read(Args& ... args) {
  (cin >> ... >> args);
}

constexpr bool golikov() {
#ifdef GOLIKOV
  return true;
#else
  return false;
#endif
}

template <bool flush = false>
void print() {
  if constexpr (golikov() || flush) {
    cout << std::endl;
  } else {
    cout << '\n';
  }
}

template <bool flush = false, typename T, typename... Args>
void print(T const& x, Args const& ... args) {
  cout << x;
  if constexpr (sizeof...(args)) {
    cout << ' ';
  }
  print<flush>(args...);
}

int main() {
  if constexpr (golikov()) {
    std::freopen("in", "rt", stdin);
  }
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto adj = make_vector<int>(n, n);
  vector<vector<int>> graph(n), rgraph(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch;
      cin >> ch;
      adj[i][j] = ch - '0';
      if (adj[i][j]) {
        graph[i].push_back(j);
        rgraph[j].push_back(i);
      }
    }
  }
  vector<int> ts;
  vector<bool> used(n);
  function<void(int)> dfs = [&](int v) {
    used[v] = true;
    for (int u : graph[v]) {
      if (!used[u]) {
        dfs(u);
      }
    }
    ts.push_back(v);
  };
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(ts.begin(), ts.end());
  used.assign(n, false);
  vector<vector<int>> comps;
  vector<int> comp_n(n);
  function<void(int)> dfs2 = [&](int v) {
    used[v] = true;
    comps.back().push_back(v);
    comp_n[v] = (int) comps.size() - 1;
    for (int u : rgraph[v]) {
      if (!used[u]) {
        dfs2(u);
      }
    }
  };
  for (int i : ts) {
    if (!used[i]) {
      comps.emplace_back();
      dfs2(i);
    }
  }
  auto ncomps = (int) comps.size();
  int a = 40;
  int b = 40;
  int h = 60;
  auto field = make_vector<char>(h, a, b);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < a; ++j) {
      for (int k = 0; k < b; ++k) {
        field[i][j][k] = i % 3 == 2 ? '#' : '.';
      }
    }
  }
  for (int comp = 0; comp < ncomps; ++comp) {
    int cur = 0;
    for (int x : comps[comp]) {
      field[comp * 3 + 1][2][cur++] = (char) ('0' + (x + 1));
    }
    vector DX{-1, 0, 1, 0};
    vector DY{0, -1, 0, 1};
    for (int i : comps[comp]) {
      for (int j : graph[i]) {
        auto cell_i = 4 * i;
        auto cell_j = 4 * j;
        auto comp_to = comp_n[j];
        for (int k = comp; k < comp_to; ++k) {
          field[k * 3 + 2][cell_i][cell_j] = '.';
          if (k > comp) {
            for (int di = 0; di < 4; ++di) {
                int dx = DX[di];
                int dy = DY[di];
                int ci = cell_i + dx;
                int cj = cell_j + dy;
                if (ci >= 0 && ci < a && cj >= 0 && cj < b) {
                  field[k * 3 + 1][ci][cj] = field[k * 3][ci][cj] = '#';
                }
              }
            }
          }
        }
      }
    }
  print(a, b, h);
  for (auto& l : field) {
    for (auto& r : l) {
      for (auto& c : r) {
        cout << c;
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}