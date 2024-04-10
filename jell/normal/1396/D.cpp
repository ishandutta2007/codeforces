#line 1 "codeforces-workspace\\contest\\1396\\d\\d.cpp"
#include <bits/extc++.h>

#line 5 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\config.hpp"
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
unsigned cases(void), caseid = 1;
template <class C> void main() {
  for (const unsigned total = cases(); caseid <= total; ++caseid) C();
}
}  // namespace config
#line 3 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\gcc_builtin.hpp"
namespace workspace {
constexpr int clz32(const uint32_t &n) noexcept { return __builtin_clz(n); }
constexpr int clz64(const uint64_t &n) noexcept{ return __builtin_clzll(n); }
constexpr int ctz(const uint64_t &n) noexcept { return __builtin_ctzll(n); }
constexpr int popcnt(const uint64_t &n) noexcept { return __builtin_popcountll(n); }
} // namespace workspace
#line 2 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\gcc_option.hpp"
#ifdef ONLINE_JUDGE
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2")
    #pragma GCC optimize("unroll-loops")
#endif
#line 5 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\binary_search.hpp"
namespace workspace {
// binary search on discrete range.
template <class iter_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>,
    iter_type>
binary_search(iter_type ok, iter_type ng, pred_type pred) {
  assert(ok != ng);
  intmax_t dist(ng - ok);
  while (std::abs(dist) > 1) {
    iter_type mid(ok + dist / 2);
    if (pred(mid))
      ok = mid, dist -= dist / 2;
    else
      ng = mid, dist /= 2;
  }
  return ok;
}
// binary search on real numbers.
template <class real_type, class pred_type>
std::enable_if_t<
    std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>,
    real_type>
binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred) {
  assert(ok != ng);
  while (eps < std::abs(ok - ng)) {
    real_type mid{(ok + ng) / 2};
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}
}  // namespace workspace
#line 3 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\casefmt.hpp"
namespace workspace {
std::ostream &casefmt(std::ostream& os) { return os << "Case #" << config::caseid << ": "; }
} // namespace workspace
#line 3 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\chval.hpp"
namespace workspace {
template <class T, class Comp = std::less<T>> bool chle(T &x, const T &y, Comp comp = Comp()) { return comp(y, x) ? x = y, true : false; }
template <class T, class Comp = std::less<T>> bool chge(T &x, const T &y, Comp comp = Comp()) { return comp(x, y) ? x = y, true : false; }
} // namespace workspace
#line 3 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\fixed_point.hpp"
namespace workspace {
// specify the return type of lambda.
template <class lambda_type>
class fixed_point
{
    lambda_type func;
public:
    fixed_point(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
} // namespace workspace
#line 2 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\sfinae.hpp"
#include <type_traits>
template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;
template <class Container>
using element_type = typename std::decay<decltype(
    *std::begin(std::declval<Container&>()))>::type;
#line 7 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\hash.hpp"
namespace workspace {
template <class T, class = void>
struct hash : std::hash<T> {};
template <class Unique_bits_type>
struct hash<Unique_bits_type, enable_if_trait_type<Unique_bits_type, std::has_unique_object_representations>>
{
    size_t operator()(uint64_t x) const
    {
        static const uint64_t m = std::random_device{}();
        x ^= x >> 23;
        // x *= 0x2127599bf4325c37ULL;
        x ^= m;
        x ^= x >> 47;
        return x - (x >> 32);
    }
};
template <class Key>
size_t hash_combine(const size_t &seed, const Key &key)
{
    return seed ^ (hash<Key>()(key) + 0x9e3779b9 /* + (seed << 6) + (seed >> 2) */ );
}
template <class T1, class T2>
struct hash<std::pair<T1, T2>>
{
    size_t operator()(const std::pair<T1, T2> &pair) const
    {
        return hash_combine(hash<T1>()(pair.first), pair.second);
    }
};
template <class... T>
class hash<std::tuple<T...>>
{
    template <class Tuple, size_t index = std::tuple_size<Tuple>::value - 1> struct tuple_hash { static uint64_t apply(const Tuple &t) { return hash_combine(tuple_hash<Tuple, index - 1>::apply(t), std::get<index>(t)); } };
    template <class Tuple> struct tuple_hash<Tuple, size_t(-1)> { static uint64_t apply(const Tuple &t) { return 0; } };
public:
    uint64_t operator()(const std::tuple<T...> &t) const { return tuple_hash<std::tuple<T...>>::apply(t); }
};
template <class hash_table>
struct hash_table_wrapper : hash_table
{
    using key_type = typename hash_table::key_type;
    size_t count(const key_type &key) const { return hash_table::find(key) != hash_table::end(); }
    template <class... Args> auto emplace(Args&&... args) { return hash_table::insert(typename hash_table::value_type(args...)); }
};
template <class Key, class Mapped = __gnu_pbds::null_type>
using cc_hash_table = hash_table_wrapper<__gnu_pbds::cc_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped = __gnu_pbds::null_type>
using gp_hash_table = hash_table_wrapper<__gnu_pbds::gp_hash_table<Key, Mapped, hash<Key>>>;
template <class Key, class Mapped>
using unordered_map = std::unordered_map<Key, Mapped, hash<Key>>;
template <class Key>
using unordered_set = std::unordered_set<Key, hash<Key>>;
} // namespace workspace
#line 3 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\read.hpp"
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
#line 4 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\stream.hpp"

#line 6 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\stream.hpp"
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
#line 13 "codeforces-workspace\\contest\\1396\\d\\d.cpp"
namespace workspace {
constexpr char eol = '\n';
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using i64 = int_least64_t;
using p32 = pair<int, int>;
using p64 = pair<i64, i64>;
using __gnu_pbds::priority_queue;
struct solver;
}  // namespace workspace
int main() { config::main<workspace::solver>(); }
unsigned config::cases() {
  // return -1; // not specify
  // int t; std::cin >> t; return t; // given
  return 1;
}

#line 4 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\modulus\\modint.hpp"
template <int_fast64_t mod = 0> // compile-time defined modulo.
struct modint
{
    static_assert(mod > 0);
    template <bool i32, class = void> struct modif { using value_type = int_least32_t; };
    template <class void_t> struct modif<false, void_t> { using value_type = int_least64_t; };
    using value_type = typename modif<mod < (1 << 30)>::value_type;
    constexpr static modint one() noexcept { return 1; }
    constexpr operator value_type() const noexcept { return value; }
    constexpr modint() noexcept = default;
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr modint(int_type n) noexcept : value((n %= mod) < 0 ? mod + n : n) {}
    constexpr modint operator++(int) noexcept { modint t{*this}; return operator+=(1), t; }
    constexpr modint operator--(int) noexcept { modint t{*this}; return operator-=(1), t; }
    constexpr modint &operator++() noexcept { return operator+=(1); }
    constexpr modint &operator--() noexcept { return operator-=(1); }
    constexpr modint operator-() const noexcept { return value ? mod - value : 0; }
    constexpr modint &operator+=(const modint &rhs) noexcept { return (value += rhs.value) < mod ? 0 : value -= mod, *this; }
    constexpr modint &operator-=(const modint &rhs) noexcept { return (value += mod - rhs.value) < mod ? 0 : value -= mod, *this; }
    constexpr modint &operator*=(const modint &rhs) noexcept { return value = (int_fast64_t)value * rhs.value % mod, *this; }
    constexpr modint &operator/=(const modint &rhs) noexcept { return operator*=(rhs.inverse()); }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr modint operator+(const int_type &rhs) const noexcept { return modint{*this} += rhs; }
    constexpr modint operator+(const modint &rhs) const noexcept { return modint{*this} += rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr modint operator-(const int_type &rhs) const noexcept { return modint{*this} -= rhs; }
    constexpr modint operator-(const modint &rhs) const noexcept { return modint{*this} -= rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr modint operator*(const int_type &rhs) const noexcept { return modint{*this} *= rhs; }
    constexpr modint operator*(const modint &rhs) const noexcept { return modint{*this} *= rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr modint operator/(const int_type &rhs) const noexcept { return modint{*this} /= rhs; }
    constexpr modint operator/(const modint &rhs) const noexcept { return modint{*this} /= rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr friend modint operator+(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) + rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr friend modint operator-(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) - rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr friend modint operator*(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) * rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    constexpr friend modint operator/(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) / rhs; }
    constexpr modint inverse() const noexcept
    {
        assert(value);
        value_type a{mod}, b{value}, u{}, v{1}, t{};
        while(b) t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
        return {u};
    }
    constexpr static modint pow(modint rhs, int_fast64_t e) noexcept
    {
        if(e < 0) e = e % (mod - 1) + mod - 1;
        modint res{1};
        while(e) { if(e & 1) res *= rhs; rhs *= rhs, e >>= 1; }
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint &rhs) noexcept { return os << rhs.value; }
    friend std::istream &operator>>(std::istream &is, modint &rhs) noexcept { int_fast64_t value; rhs = (is >> value, value); return is; }
protected:
    value_type value = 0;
}; // class modint
template <> // runtime defined modulo as default(mod = 0).
struct modint<0>
{
    using value_type = int_fast64_t;
    static value_type &mod() noexcept { static value_type mod{}; return mod; }
    static modint one() noexcept { return 1; }
    operator value_type() const noexcept { return value; }
    modint() noexcept = default;
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    modint(int_type n) noexcept : value{ (assert(mod()), n %= mod() < 0 ? n + mod() : n) } {}
    modint operator++(int) noexcept { modint t{*this}; return operator+=(1), t; }
    modint operator--(int) noexcept { modint t{*this}; return operator-=(1), t; }
    modint &operator++() noexcept { return operator+=(1); }
    modint &operator--() noexcept { return operator-=(1); }
    modint operator-() const noexcept { return value ? mod() - value : 0; }
    modint &operator+=(const modint &rhs) noexcept { return (value += rhs.value) < mod() ? 0 : value -= mod(), *this; }
    modint &operator-=(const modint &rhs) noexcept { return (value += mod() - rhs.value) < mod() ? 0 : value -= mod(), *this; }
    modint &operator*=(const modint &rhs) noexcept { return (value *= rhs.value) %= mod(), *this; }
    modint &operator/=(const modint &rhs) noexcept { return operator*=(rhs.inverse()); }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    modint operator+(const int_type &rhs) const noexcept { return modint{*this} += rhs; }
    modint operator+(const modint &rhs) const noexcept { return modint{*this} += rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    modint operator-(const int_type &rhs) const noexcept { return modint{*this} -= rhs; }
    modint operator-(const modint &rhs) const noexcept { return modint{*this} -= rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    modint operator*(const int_type &rhs) const noexcept { return modint{*this} *= rhs; }
    modint operator*(const modint &rhs) const noexcept { return modint{*this} *= rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    modint operator/(const int_type &rhs) const noexcept { return modint{*this} /= rhs; }
    modint operator/(const modint &rhs) const noexcept { return modint{*this} /= rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    friend modint operator+(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) + rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    friend modint operator-(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) - rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    friend modint operator*(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) * rhs; }
    template <class int_type, std::enable_if_t<std::is_integral<int_type>::value, std::nullptr_t> = nullptr>
    friend modint operator/(const int_type &lhs, const modint &rhs) noexcept { return modint(lhs) / rhs; }
    modint inverse() const noexcept
    {
        assert(mod() && value);
        value_type a{mod()}, b{value}, u{}, v{1}, t{};
        while(b) t = a / b, a ^= b ^= (a -= t * b) ^= b, u ^= v ^= (u -= t * v) ^= v;
        return {u};
    }
    static modint pow(modint rhs, int_fast64_t e) noexcept
    {
        if(e < 0) e = e % (mod() - 1) + mod() - 1;
        modint res{1};
        while(e) { if(e & 1) res *= rhs; rhs *= rhs, e >>= 1; }
        return res;
    }
    friend std::ostream &operator<<(std::ostream &os, const modint &rhs) noexcept { return os << rhs.value; }
    friend std::istream &operator>>(std::istream &is, modint &rhs) noexcept { int_fast64_t value; rhs = modint((is >> value, value)); return is; }
protected:
    value_type value = 0;
}; // class modint<0>
using modint_runtime = modint<0>;
#line 4 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\coordinate_compression.hpp"

template <class T>
class coordinate_compression
{
    std::vector<T> uniquely;
    std::vector<size_t> compressed;

public:
    coordinate_compression(const std::vector<T> &raw) : uniquely(raw), compressed(raw.size())
    {
        std::sort(uniquely.begin(), uniquely.end());
        uniquely.erase(std::unique(uniquely.begin(), uniquely.end()), uniquely.end());
        for(size_t i = 0; i != size(); ++i)
            compressed[i] = std::lower_bound(uniquely.begin(), uniquely.end(), raw[i]) - uniquely.begin();
    }

    size_t operator[](const size_t idx) const
    {
        assert(idx < size());
        return compressed[idx];
    }

    size_t size() const { return compressed.size(); }

    size_t count() const { return uniquely.size(); }

    T value_of(const size_t ord) const
    {
        assert(ord < count());
        return uniquely[ord];
    }

    size_t order_of(const T &val) const { return std::lower_bound(uniquely.begin(), uniquely.end(), val) - uniquely.begin(); }

    std::vector<size_t>::iterator begin() { return compressed.begin(); }
    std::vector<size_t>::iterator end() { return compressed.end(); }
    std::vector<size_t>::reverse_iterator rbegin() { return compressed.rbegin(); }
    std::vector<size_t>::reverse_iterator rend() { return compressed.rend(); }
};
#line 2 "C:\\cygwin64\\home\\euler\\competitive-programming\\Library\\utils\\wrapper.hpp"
template <class Container> class reversed {
  Container &ref, copy;

 public:
  reversed(Container &ref) : ref(ref) {}
  reversed(Container &&ref = Container()) : ref(copy), copy(ref) {}
  auto begin() const { return ref.rbegin(); }
  auto end() const { return ref.rend(); }
};
#line 34 "codeforces-workspace\\contest\\1396\\d\\d.cpp"

// template <class Container> class reversed {
//   Container *const ptr;
//   Container const &cref;

//  public:
//   reversed(Container &ref) : ptr(&ref), cref(*ptr) {}
//   reversed(Container &&ref) : ptr(&cref), cref(ref) {}
//   auto begin() { return ptr->rbegin(); }
//   auto end() { return ptr->rend(); }
// };

struct workspace::solver {  // start here!

  using mint = modint<1000000007>;

  struct point {
    int x, y;
    int color;
  };

  solver() {
    auto xcmp = [](point p1, point p2) { return p1.x < p2.x; };
    auto ycmp = [](point p1, point p2) { return p1.y < p2.y; };
    int n, k, L;
    cin >> n >> k >> L;

    vector<point> pts(n);

    for (auto &p : reversed(pts)) {
      int x, y, c;
      cin >> x >> y >> c;
      c--;
      p = {x, y, c};
    }
    sort(begin(pts), end(pts), ycmp);
    pts.push_back({L, L, -1});
    int py = -1;
    mint ans;
    for (auto r = begin(pts); r != end(pts); py = r->y, ++r) {
      vector<set<pair<int, int>>> colx(k);
      map<int, int> bound;
      mint sum;
      // construct [0,r)
      {
        // init colx
        for (auto i = begin(pts); i != r; ++i) {
          auto [x, y, c] = *i;
          colx[c].emplace(x, y);
        }
        // init bound
        set<pair<int, int>> low;  // (low,color)
        for (int i = 0; i < k; i++) {
          low.emplace(L, i);
        }
        vector byx(begin(pts), r);
        sort(begin(byx), end(byx), xcmp);
        vector<int> lowx(k, L);
        for (auto [x, y, c] : reversed(byx)) {
          low.erase({lowx[c], c});
          low.insert({lowx[c] = x, c});
          auto nlow = low.rbegin()->first;
          bound[x] = nlow;
        }
        bound[L] = L;
        for (auto &c : colx) {
          c.emplace(L, L);
          c.emplace(-1, -1);
        }
        // init sum
        {
          int px = -1;
          for (auto [x, l] : bound) {
            sum += mint(x - px) * (L - l);
            px = x;
          }
        }
      }

      // erase one by one
      mint ans2;
      for (auto l = begin(pts); l != r; ++l) {
        ans2 += sum * (l->y - (l == begin(pts) ? -1 : prev(l)->y));
        // erase here
        auto it = colx[l->color].find({l->x, l->y});
        auto xb = prev(it)->first;
        auto upto = next(it)->first;
        colx[l->color].erase(it);
        // update bound & sum
        auto p = bound.lower_bound(xb);
        if (p->second < upto) {  // update
          auto [fst, snd] = *p;
          bound.erase(p);
          sum -= mint(fst - xb) * (upto - snd);
          tie(p, ignore) = bound.emplace(xb, snd);
          ++p;
          int nx = fst;
          while (p->second < upto) {
            sum -= mint(p->first - nx) * (upto - p->second);
            nx = p->first;
            p = bound.erase(p);
          }
          if (xb < nx) bound[nx] = upto;
          assert(nx <= l->x);
        }
      }
      assert(sum == 0);
      // add to ans
      ans += ans2 * (r->y - py);
    }
    cout << ans << eol;
  }
};