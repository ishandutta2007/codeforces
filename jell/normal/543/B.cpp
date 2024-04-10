#line 1 "codeforces-workspace\\contest\\543\\b\\b.cpp"
#include <bits/extc++.h>

#line 7 "Library\\alias.hpp"
namespace workspace {
constexpr char eol = '\n';
using namespace std;
using i32 = int_least32_t;
using i64 = int_least64_t;
using i128 = __int128_t;
using u32 = uint_least32_t;
using u64 = uint_least64_t;
using u128 = __uint128_t;
template <class T, class Comp = less<T>>
using priority_queue = std::priority_queue<T, vector<T>, Comp>;
template <class T> using stack = std::stack<T, vector<T>>;
}  // namespace workspace
#line 5 "Library\\config.hpp"
namespace config {
const auto start_time{std::chrono::system_clock::now()};
int64_t elapsed() {
  using namespace std::chrono;
  const auto end_time{system_clock::now()};
  return duration_cast<milliseconds>(end_time - start_time).count();
}
__attribute__((constructor)) void setup() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(15);
#ifdef _buffer_check
  atexit([] {
    char bufc;
    if (cin >> bufc)
      cerr << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n";
  });
#endif
}
unsigned cases(), caseid = 1;
template <class F> void loop(F main) {
  for (const unsigned total = cases(); caseid <= total; ++caseid) main();
}
}  // namespace config
#line 1 "Library\\cxx20.hpp"
#if __cplusplus <= 201703L

#if __has_include(<bit>)
#include <bit>
#endif

#include <vector>
namespace std {
template <typename _Tp, typename _Alloc, typename _Predicate>
inline typename vector<_Tp, _Alloc>::size_type erase_if(
    vector<_Tp, _Alloc>& __cont, _Predicate __pred) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove_if(__cont.begin(), __cont.end(), __pred),
               __cont.end());
  return __osz - __cont.size();
}
template <typename _Tp, typename _Alloc, typename _Up>
inline typename vector<_Tp, _Alloc>::size_type erase(
    vector<_Tp, _Alloc>& __cont, const _Up& __value) {
  const auto __osz = __cont.size();
  __cont.erase(std::remove(__cont.begin(), __cont.end(), __value),
               __cont.end());
  return __osz - __cont.size();
}
}

#endif
#line 2 "Library\\option.hpp"
#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("unroll-loops")
#endif
#line 2 "Library\\utils\\binary_search.hpp"
#if __cplusplus >= 201703L
#include <cassert>
#include <cmath>
#include <vector>
namespace workspace {
// binary search on a discrete range.
template <class iter_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>,
    iter_type>
binary_search(iter_type ok, iter_type ng, pred_type pred) {
  assert(ok != ng);
  std::make_signed_t<decltype(ng - ok)> dist(ng - ok);
  while (1 < dist || dist < -1) {
    iter_type mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
}
// parallel binary search on each discrete range.
template <class iter_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<iter_type>>,
                     std::vector<bool>>,
                 std::vector<iter_type>>
binary_search(std::vector<std::pair<iter_type, iter_type>> ends,
              pred_type pred) {
  std::vector<iter_type> mids(ends.size());
  for (;;) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      iter_type mid(ok + (ng - ok) / 2);
      if (mids[i] != mid) {
        all_found = false;
        mids[i] = mid;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
}
// binary search on a real number interval.
template <class real_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>,
    real_type>
binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred) {
  assert(ok != ng);
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits &&
                       (ok + eps < ng || ng + eps < ok);
       ++loops) {
    real_type mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}
// parallel binary search on each real interval.
template <class real_type, class pred_type>
std::enable_if_t<std::is_convertible_v<
                     std::invoke_result_t<pred_type, std::vector<real_type>>,
                     std::vector<bool>>,
                 std::vector<real_type>>
binary_search(std::vector<std::pair<real_type, real_type>> ends,
              const real_type eps, pred_type pred) {
  std::vector<real_type> mids(ends.size());
  for (auto loops = 0; loops != std::numeric_limits<real_type>::digits;
       ++loops) {
    bool all_found = true;
    for (size_t i{}; i != ends.size(); ++i) {
      auto [ok, ng] = ends[i];
      if (ok + eps < ng || ng + eps < ok) {
        all_found = false;
        mids[i] = (ok + ng) / 2;
      }
    }
    if (all_found) break;
    auto res = pred(mids);
    for (size_t i{}; i != ends.size(); ++i) {
      (res[i] ? ends[i].first : ends[i].second) = mids[i];
    }
  }
  return mids;
}
}  // namespace workspace
#endif
#line 3 "Library\\utils\\casefmt.hpp"
namespace workspace {
std::ostream &casefmt(std::ostream& os) { return os << "Case #" << config::caseid << ": "; }
} // namespace workspace
#line 3 "Library\\utils\\chval.hpp"
namespace workspace {
template <class T, class Comp = std::less<T>>
bool chle(T &x, const T &y, Comp comp = Comp()) {
  return comp(y, x) ? x = y, true : false;
}
template <class T, class Comp = std::less<T>>
bool chge(T &x, const T &y, Comp comp = Comp()) {
  return comp(x, y) ? x = y, true : false;
}
}  // namespace workspace
#line 5 "Library\\utils\\coordinate_compression.hpp"

template <class T> class coordinate_compression {
  std::vector<T> uniquely;
  std::vector<size_t> compressed;

 public:
  coordinate_compression(const std::vector<T> &raw)
      : uniquely(raw), compressed(raw.size()) {
    std::sort(uniquely.begin(), uniquely.end());
    uniquely.erase(std::unique(uniquely.begin(), uniquely.end()),
                   uniquely.end());
    for (size_t i = 0; i != size(); ++i)
      compressed[i] =
          std::lower_bound(uniquely.begin(), uniquely.end(), raw[i]) -
          uniquely.begin();
  }

  size_t operator[](const size_t idx) const {
    assert(idx < size());
    return compressed[idx];
  }

  size_t size() const { return compressed.size(); }

  size_t count() const { return uniquely.size(); }

  T value(const size_t ord) const {
    assert(ord < count());
    return uniquely[ord];
  }

  size_t order(const T &value) const {
    return std::lower_bound(uniquely.begin(), uniquely.end(), value) -
           uniquely.begin();
  }

  auto begin() { return compressed.begin(); }
  auto end() { return compressed.end(); }
  auto rbegin() { return compressed.rbegin(); }
  auto rend() { return compressed.rend(); }
};
#line 3 "Library\\utils\\fixed_point.hpp"
namespace workspace {
// specify the return type of lambda.
template <class lambda_type> class fixed_point {
  lambda_type func;

 public:
  fixed_point(lambda_type &&f) : func(std::move(f)) {}
  template <class... Args> auto operator()(Args &&... args) const {
    return func(*this, std::forward<Args>(args)...);
  }
};
}  // namespace workspace
#line 6 "Library\\utils\\hash.hpp"

#line 4 "Library\\utils\\sfinae.hpp"
#include <type_traits>

template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;

template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;

template <class T, class = int> struct mapped_of {
  using type = element_type<T>;
};
template <class T>
struct mapped_of<T,
                 typename std::pair<int, typename T::mapped_type>::first_type> {
  using type = typename T::mapped_type;
};
template <class T> using mapped_type = typename mapped_of<T>::type;

template <class T, class = void> struct is_integral_ext : std::false_type {};
template <class T>
struct is_integral_ext<
    T, typename std::enable_if<std::is_integral<T>::value>::type>
    : std::true_type {};
template <> struct is_integral_ext<__int128_t> : std::true_type {};
template <> struct is_integral_ext<__uint128_t> : std::true_type {};
#if __cplusplus >= 201402
template <class T>
constexpr static bool is_integral_ext_v = is_integral_ext<T>::value;
#endif

template <typename T, typename = void> struct multiplicable_uint {
  using type = uint_least32_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(2 < sizeof(T))>::type> {
  using type = uint_least64_t;
};
template <typename T>
struct multiplicable_uint<T, typename std::enable_if<(4 < sizeof(T))>::type> {
  using type = __uint128_t;
};
#line 8 "Library\\utils\\hash.hpp"
namespace workspace {
template <class T, class = void> struct hash : std::hash<T> {};
#if __cplusplus >= 201703L
template <class Unique_bits_type>
struct hash<Unique_bits_type,
            enable_if_trait_type<Unique_bits_type,
                                 std::has_unique_object_representations>> {
  size_t operator()(uint64_t x) const {
    static const uint64_t m = std::random_device{}();
    x ^= x >> 23;
    x ^= m;
    x ^= x >> 47;
    return x - (x >> 32);
  }
};
#endif
template <class Key> size_t hash_combine(const size_t &seed, const Key &key) {
  return seed ^
         (hash<Key>()(key) + 0x9e3779b9 /* + (seed << 6) + (seed >> 2) */);
}
template <class T1, class T2> struct hash<std::pair<T1, T2>> {
  size_t operator()(const std::pair<T1, T2> &pair) const {
    return hash_combine(hash<T1>()(pair.first), pair.second);
  }
};
template <class... T> class hash<std::tuple<T...>> {
  template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1>
  struct tuple_hash {
    static uint64_t apply(const Tuple &t) {
      return hash_combine(tuple_hash<Tuple, index - 1>::apply(t),
                          std::get<index>(t));
    }
  };
  template <class Tuple> struct tuple_hash<Tuple, size_t(-1)> {
    static uint64_t apply(const Tuple &t) { return 0; }
  };

 public:
  uint64_t operator()(const std::tuple<T...> &t) const {
    return tuple_hash<std::tuple<T...>>::apply(t);
  }
};
template <class hash_table> struct hash_table_wrapper : hash_table {
  using key_type = typename hash_table::key_type;
  size_t count(const key_type &key) const {
    return hash_table::find(key) != hash_table::end();
  }
  template <class... Args> auto emplace(Args &&... args) {
    return hash_table::insert(typename hash_table::value_type(args...));
  }
};
template <class Key, class Mapped = __gnu_pbds::null_type>
using cc_hash_table =
    hash_table_wrapper<__gnu_pbds::cc_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped = __gnu_pbds::null_type>
using gp_hash_table =
    hash_table_wrapper<__gnu_pbds::gp_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped>
using unordered_map = std::unordered_map<Key, Mapped, hash<Key>>;
template <class Key> using unordered_set = std::unordered_set<Key, hash<Key>>;
}  // namespace workspace
#line 2 "Library\\utils\\make_vector.hpp"
#if __cplusplus >= 201703L
#include <tuple>
#include <vector>
namespace workspace {
template <typename T, typename S, size_t N>
constexpr auto make_vector(S* sizes, T const& init = T()) {
  if constexpr (N)
    return std::vector(*sizes,
                       make_vector<T, S, N - 1>(std::next(sizes), init));
  else
    return init;
}
template <typename T, typename S, size_t N,
          std::enable_if_t<std::is_convertible_v<S, size_t>>* = nullptr>
constexpr auto make_vector(const S (&sizes)[N], T const& init = T()) {
  return make_vector<T, S, N>((S*)sizes, init);
}
template <typename T, size_t N, size_t I = 0>
constexpr auto make_vector(std::array<size_t, N> const& array,
                           T const& init = T()) {
  if constexpr (I == N)
    return init;
  else
    return std::vector(array[I], make_vector<T, N, I + 1>(array, init));
}
template <typename T, size_t I = 0, class... Args>
constexpr auto make_vector(std::tuple<Args...> const& tuple,
                           T const& init = T()) {
  using tuple_type = std::tuple<Args...>;
  if constexpr (I == tuple_size_v<tuple_type>)
    return init;
  else {
    static_assert(
        std::is_convertible_v<tuple_element_t<I, tuple_type>, size_t>);
    return std::vector(get<I>(tuple), make_vector<T, I + 1>(tuple, init));
  }
}
template <typename T, class Fst, class Snd>
constexpr auto make_vector(std::pair<Fst, Snd> const& pair,
                           T const& init = T()) {
  return make_vector((size_t[2]){pair.first, pair.second}, init);
}
}  // namespace workspace
#endif
#line 3 "Library\\utils\\random_number_generator.hpp"
template <typename num_type> class random_number_generator {
  typename std::conditional<std::is_integral<num_type>::value,
                            std::uniform_int_distribution<num_type>,
                            std::uniform_real_distribution<num_type>>::type
      unif;

  std::mt19937 engine;

 public:
  random_number_generator(num_type min = std::numeric_limits<num_type>::min(),
                          num_type max = std::numeric_limits<num_type>::max())
      : unif(min, max), engine(std::random_device{}()) {}

  num_type min() const { return unif.min(); }

  num_type max() const { return unif.max(); }

  // generate a random number in [min(), max()].
  num_type operator()() { return unif(engine); }
};
#line 3 "Library\\utils\\read.hpp"
namespace workspace {
// read with std::cin.
template <class T = void>
struct read
{
    typename std::remove_const<T>::type value;
    template <class... types>
    read(types... args) : value(args...) { std::cin >> value; }
    operator T() const { return value; }
};
template <>
struct read<void>
{
    template <class T>
    operator T() const { T value; std::cin >> value; return value; }
};
} // namespace workspace
#line 4 "Library\\utils\\stream.hpp"

#line 6 "Library\\utils\\stream.hpp"
namespace std {
template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
  return is >> p.first >> p.second;
}
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << ' ' << p.second;
}
template <class tuple_t, size_t index> struct tuple_is {
  static istream &apply(istream &is, tuple_t &t) {
    tuple_is<tuple_t, index - 1>::apply(is, t);
    return is >> get<index>(t);
  }
};
template <class tuple_t> struct tuple_is<tuple_t, SIZE_MAX> {
  static istream &apply(istream &is, tuple_t &t) { return is; }
};
template <class... T> istream &operator>>(istream &is, tuple<T...> &t) {
  return tuple_is<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is,
                                                                          t);
}
template <class tuple_t, size_t index> struct tuple_os {
  static ostream &apply(ostream &os, const tuple_t &t) {
    tuple_os<tuple_t, index - 1>::apply(os, t);
    return os << ' ' << get<index>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, 0> {
  static ostream &apply(ostream &os, const tuple_t &t) {
    return os << get<0>(t);
  }
};
template <class tuple_t> struct tuple_os<tuple_t, SIZE_MAX> {
  static ostream &apply(ostream &os, const tuple_t &t) { return os; }
};
template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) {
  return tuple_os<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os,
                                                                          t);
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   istream &>::type
operator>>(istream &is, Container &cont) {
  for (auto &&e : cont) is >> e;
  return is;
}
template <class Container, typename Value = element_type<Container>>
typename enable_if<!is_same<typename decay<Container>::type, string>::value &&
                       !is_same<typename decay<Container>::type, char *>::value,
                   ostream &>::type
operator<<(ostream &os, const Container &cont) {
  bool head = true;
  for (auto &&e : cont) head ? head = 0 : (os << ' ', 0), os << e;
  return os;
}
}  // namespace std
#line 4 "Library\\utils\\trinary_search.hpp"
// trinary search on discrete range.
template <class iter_type, class comp_type>
iter_type trinary(iter_type first, iter_type last, comp_type comp)
{
    assert(first < last);
    intmax_t dist(last - first);
    while(dist > 2)
    {
        iter_type left(first + dist / 3), right(first + dist * 2 / 3);
        if(comp(left, right)) last = right, dist = dist * 2 / 3;
        else first = left, dist -= dist / 3;
    }
    if(dist > 1 && comp(first + 1, first)) ++first;
    return first;
}
// trinary search on real numbers.
template <class comp_type>
long double trinary(long double first, long double last, const long double eps, comp_type comp)
{
    assert(first < last);
    while(last - first > eps)
    {
        long double left{(first * 2 + last) / 3}, right{(first + last * 2) / 3};
        if(comp(left, right)) last = right;
        else first = left;
    }
    return first;
}
#line 2 "Library\\utils\\wrapper.hpp"
template <class Container> class reversed {
  Container &ref, copy;

 public:
  constexpr reversed(Container &ref) : ref(ref) {}
  constexpr reversed(Container &&ref = Container()) : ref(copy), copy(ref) {}
  constexpr auto begin() const { return ref.rbegin(); }
  constexpr auto end() const { return ref.rend(); }
  constexpr operator Container() const { return ref; }
};
#line 8 "codeforces-workspace\\contest\\543\\b\\b.cpp"

namespace workspace {
void main();
}
int main() { config::loop(workspace::main); }

unsigned config::cases() {
  // return -1; // unspecified
  // int t; std::cin >> t; return t; // given
  return 1;
}

namespace workspace {
void main() {
  // start here!
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (auto i = 0; i != m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  auto dist = make_vector<int>({n, n}, n);
  for (auto s = 0; s != n; ++s) {
    queue<int> q({s});
    dist[s][s] = 0;
    while (!q.empty()) {
      auto f = q.front();
      q.pop();
      for (auto v : g[f]) {
        if (chle(dist[s][v], dist[s][f] + 1)) q.push(v);
      }
    }
  }
  int s1, t1, l1, s2, t2, l2;
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  s1--, s2--, t1--, t2--;
  if (dist[s1][t1] > l1 or dist[s2][t2] > l2) {
    cout << "-1\n";
    return;
  }

  int ans = dist[s1][t1] + dist[s2][t2];
  for (auto v1 = 0; v1 != n; ++v1) {
    for (auto v2 = 0; v2 != n; ++v2) {
      int d1 = dist[v1][v2] + dist[s1][v1] + dist[t1][v2];
      int d2 = dist[v1][v2] + dist[s2][v1] + dist[t2][v2];
      if (d1 <= l1 and d2 <= l2) {
        chle(ans, d1 + d2 - dist[v1][v2]);
      }
      d2 = dist[v1][v2] + dist[s2][v2] + dist[t2][v1];
      if (d1 <= l1 and d2 <= l2) {
        chle(ans, d1 + d2 - dist[v1][v2]);
      }
    }
  }

  ans = m - ans;
  cout << ans << eol;
}
}