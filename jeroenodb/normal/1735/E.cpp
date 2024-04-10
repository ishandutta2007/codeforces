/**
 * author:  magnus_hegdahl
 * created: 02.10.2022 16:35
 * problem: E. House Planning
 * url:     https://codeforces.com/contest/1735/problem/E
 */
#include <bits/stdc++.h>

// <graph/bipartite_matcher.hpp>
#include <array>
// <graph/flow.hpp>
#include <algorithm>
#include <array>
// <container/any_map.hpp>
#include <map>
#include <tuple>
#include <utility>
template <class T>
class AnyMap {
  static int instance_count;
  const int instance_id_;
  T default_value_;
 public:
  AnyMap(T default_value = T())
      : instance_id_(instance_count++),
        default_value_(std::move(default_value)) {}
  template <class... Args>
  auto &operator()(Args &&...args) {
    using Tuple =
        decltype(std::make_tuple(instance_id_, std::forward<Args>(args)...));
    static std::map<Tuple, T> map;
    auto it = map.emplace(Tuple{instance_id_, std::forward<Args>(args)...},
                          default_value_)
                  .first;
    return it->second;
  }
};
template <class T>
int AnyMap<T>::instance_count = 0;
// </container/any_map.hpp>
#include <limits>
// <local_assertion.hpp>
#include <iostream>
#ifdef ENABLE_DEBUG
#define LOCAL_ASSERT(condition, message)            \
  if (!(condition)) {                               \
    std::cerr << "Assertion (" << #condition        \
              << ") failed\non line " << __LINE__   \
              << " in " << __FILE__                 \
              << '#' << __FUNCTION__ << "()\n";     \
    std::cerr << message << '\n';                   \
    abort();                                        \
  }
#else
#define LOCAL_ASSERT(...) do {} while (0);
#endif
#define LOCAL_ASSERT_IN_RANGE(variable, low, high)  \
  LOCAL_ASSERT(low <= variable && variable <= high, \
               #variable << '=' << variable         \
               << " is out of the range "           \
               << '[' << low << ", " << high << ']')
// </local_assertion.hpp>
#include <numeric>
#include <string>
#include <tuple>
// <utils.hpp>
// <ints.hpp>
#include <cstdint>
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
// </ints.hpp>
#include <random>
#include <chrono>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
struct r_hash {
  static u64 splitmix64(u64 x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  template<class T>
  u64 operator()(const T &x) const;
  u64 operator()(u64 x) const {
    static const u64 FIXED_RANDOM = rng();
    return splitmix64(x + FIXED_RANDOM);
  }
};
#if __cplusplus >= 201703L
template<class...Ts>
struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;
#endif
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
struct {
  template<class T>
  operator T() {
    T x;
    std::cin >> x;
    return x;
  }
} in;
// </utils.hpp>
#include <vector>


using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
// std::mt19937 rng(69);
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
struct bimatching {
    vector<basic_string<int>> adj;
    vi from,match;
    vector<bool> vis;
    bimatching(int n, int m) {
        adj.resize(n);
        match.assign(n,-1);
        from.assign(m,-1);
        vis.assign(m,false);
    }
    void addedge(int a, int b) {
        adj[a].push_back(b);
    }
    bool dfs(int at) {
        if(match[at]!=-1) vis[match[at]]=true;
        for(int to:adj[at]) {
            if(!vis[to] and (from[to]==-1 or dfs(from[to]))) {
                from[to]=at;
                match[at]=to;
                return true;
            }
        }
        return false;
    }
    int initgreedy() {
        vi order(match.size()); iota(all(order),0);
        shuffle(all(order),rng);
        int res=0;
        for(auto i : order) {
            for(int to : adj[i]) {
                if(!from[to]) {
                    from[to]=i;
                    match[i]=to;
                    res++;
                    break;
                }
            }
        }
        return res;
    }
    int solve() {
        for(auto& i : adj) {
            shuffle(all(i),rng);
        }
        // init with random shuffle
        int res = initgreedy();
        bool done=false;
        while(!done) {
            done=true;
            fill(all(vis),false);
            for(int i=0;i<(int)match.size();++i) {
                if(match[i]==-1) {
                    if(dfs(i)) {
                        done=false;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
std::optional<std::tuple<int, int, vector<int>>> solve_given_distance(
    int d, const vector<int> &a, const vector<int> &b) {
  int n = (int)a.size();
  assert(n == (int)b.size());

  bimatching bm(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = a[i];
      int y = b[j];
      bool ok = false;
      ok |= +x == d + y;
      ok |= -x == d + y;
      ok |= +x == d - y;
      ok |= -x == d - y;
      if (ok) bm.addedge(i, j);
    }
  }

  bm.solve();
  vector<pi> m;
  m.reserve(n);
  for(int i=0;i<n;++i) if(bm.match[i]!=-1) m.push_back({i,bm.match[i]});
  if ((int)m.size() != n) return std::nullopt;

  int pa = 0;
  int pb = d;
  vector<int> res;

  for (auto [i, j] : m) {
    int x = a[i];
    int y = b[j];
    if (x == d - y || x == d + y) {
      res.push_back(x);
    } else if (-x == d - y || -x == d + y) {
      res.push_back(-x);
    }
  }

  int mn = min(0, *min_element(res.begin(), res.end()));
  pa -= mn;
  pb -= mn;
  for (int &x : res) x -= mn;
  return std::make_tuple(pa, pb, res);
}

void show_ans(const std::tuple<int, int, vector<int>> &t) {
  cout << "Yes\n";
  auto [pa, pb, ans] = t;
  for (int x : ans) cout << x << ' ';
  cout << '\n';
  cout << pa << ' ' << pb << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    // case 1: both have same furthest guy
    // -> a-b = max_a-max_b
    // -> bipartitie matching
    // b-a + x = y OR
    // b-a - x = y OR
    // b-a + x = - y OR
    // b-a - x = - y

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ++cnt[a[i] + b[j]];
        ++cnt[abs(a[i] - b[j])];
      }
    }

    bool found = false;

    for (auto [diff, c] : cnt) {
      //cerr << diff << ' ' << c << '\n';
      if (c >= n) {
        auto maybe_res = solve_given_distance(diff, a, b);
        if (maybe_res) {
          show_ans(*maybe_res);
          found = true;
          break;
        }
      }
    }

    if (!found) cout << "No\n";

    // i'd guess this is wrong, but ac on sample so why not submit lol
  }
}