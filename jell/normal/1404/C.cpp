#line 1 "codeforces-workspace\\contest\\1404\\c\\c.cpp"
#include <bits/extc++.h>

#line 5 "Library\\config.hpp"
namespace config {
const auto start_time{std::chrono::system_clock::now()};
int64_t elapsed()
{
    using namespace std::chrono;
    const auto end_time{system_clock::now()};
    return duration_cast<milliseconds>(end_time - start_time).count();
}
__attribute__((constructor)) void setup()
{
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
#ifdef _buffer_check
    atexit([]{ ofstream cnsl("CON"); char bufc; if(cin >> bufc) cnsl << "\n\033[43m\033[30mwarning: buffer not empty.\033[0m\n\n"; });
#endif
}
unsigned cases(void), caseid = 1;
template <class C> void main() { for(const unsigned total = cases(); caseid <= total; ++caseid) C(); }
} // namespace config
#line 3 "Library\\gcc_builtin.hpp"
namespace workspace {
constexpr int clz32(const uint32_t &n) noexcept { return __builtin_clz(n); }
constexpr int clz64(const uint64_t &n) noexcept{ return __builtin_clzll(n); }
constexpr int ctz(const uint64_t &n) noexcept { return __builtin_ctzll(n); }
constexpr int popcnt(const uint64_t &n) noexcept { return __builtin_popcountll(n); }
} // namespace workspace
#line 2 "Library\\gcc_option.hpp"
#ifdef ONLINE_JUDGE
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2")
    #pragma GCC optimize("unroll-loops")
#endif
#line 5 "Library\\utils\\binary_search.hpp"
namespace workspace {
// binary search on discrete range.
template <class iter_type, class pred_type, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>, std::nullptr_t> = nullptr>
iter_type binary_search(iter_type ok, iter_type ng, pred_type pred)
{
    assert(ok != ng);
    intmax_t dist(ng - ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(ok + dist / 2);
        if(pred(mid)) ok = mid, dist -= dist / 2;
        else ng = mid, dist /= 2;
    }
    return ok;
}
// binary search on real numbers.
template <class real_type, class pred_type, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>, std::nullptr_t> = nullptr>
real_type binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred)
{
    assert(ok != ng);
    while(std::abs(ok - ng) > eps)
    {
        real_type mid{(ok + ng) / 2};
        (pred(mid) ? ok : ng) = mid;
    }
    return ok;
}
} // namespace workspace
#line 3 "Library\\utils\\casefmt.hpp"
namespace workspace {
std::ostream &casefmt(std::ostream& os) { return os << "Case #" << config::caseid << ": "; }
} // namespace workspace
#line 3 "Library\\utils\\chval.hpp"
namespace workspace {
template <class T, class Comp = std::less<T>> bool chle(T &x, const T &y, Comp comp = Comp()) { return comp(y, x) ? x = y, true : false; }
template <class T, class Comp = std::less<T>> bool chge(T &x, const T &y, Comp comp = Comp()) { return comp(x, y) ? x = y, true : false; }
} // namespace workspace
#line 3 "Library\\utils\\fixed_point.hpp"
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
#line 2 "Library\\utils\\sfinae.hpp"
#include <type_traits>
template <class type, template <class> class trait>
using enable_if_trait_type = typename std::enable_if<trait<type>::value>::type;
template <class Container>
using element_type =
    std::decay_t<decltype(*std::begin(std::declval<Container&>()))>;
#line 7 "Library\\utils\\hash.hpp"
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
#line 3 "Library\\utils\\iostream_overload.hpp"
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
template <class Container, typename Value = typename Container::value_type,
          enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> =
              nullptr>
istream &operator>>(istream &is, Container &cont) {
  for (auto &&e : cont) is >> e;
  return is;
}
template <class Container, typename Value = typename Container::value_type,
          enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> =
              nullptr>
ostream &operator<<(ostream &os, const Container &cont) {
  bool flag = 1;
  for (auto &&e : cont) flag ? flag = 0 : (os << ' ', 0), os << e;
  return os;
}
}  // namespace std
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
#line 13 "codeforces-workspace\\contest\\1404\\c\\c.cpp"

namespace workspace {
constexpr char eol = '\n';
using namespace std;
using i64 = int_least64_t;
using p32 = pair<int, int>;
using p64 = pair<i64, i64>;
template <class T, class Comp = std::less<T>>
using priority_queue = std::priority_queue<T, std::vector<T>, Comp>;
template <class T> using stack = std::stack<T, std::vector<T>>;
struct solver;
}  // namespace workspace
int main() { config::main<workspace::solver>(); }
unsigned config::cases() {
  // return -1; // not specify
  // int t; std::cin >> t; return t; // given
  return 1;
}

#line 3 "Library\\algebra\\system\\monoid.hpp"
template <class T>
struct min_monoid
{
    using value_type = T;
    static T min, max;
    T value;
    min_monoid() : value(max) {}
    min_monoid(const T &value) : value(value) {}
    operator T() const { return value; }
    min_monoid operator+(const min_monoid &rhs) const
    {
        return value < rhs.value ? *this : rhs;
    }
};
template <class T> T min_monoid<T>::min = std::numeric_limits<T>::min();
template <class T> T min_monoid<T>::max = std::numeric_limits<T>::max();
template <class T>
struct max_monoid : min_monoid<T>
{
    using base = min_monoid<T>;
    using base::min_monoid;
    max_monoid() : base(base::min) {}
    max_monoid operator+(const max_monoid &rhs) const
    {
        return !(base::value < rhs.value) ? *this : rhs;
    }
};
#line 5 "Library\\data_structure\\segment_tree\\basic.hpp"
template <class Monoid, class Container = std::vector<Monoid>>
class segment_tree
{
    static_assert(std::is_same_v<Monoid, element_type<Container>>);
    
    class unique_queue
    {
        size_t *que, *begin, *end;
        bool *in;
    public:
        unique_queue(size_t n) : que(new size_t[n]), begin(que), end(que), in(new bool[n]{}) {}
        ~unique_queue() { delete[] que; delete[] in; }
        void clear() { begin = end = que; }
        bool empty() const { return begin == end; }
        bool push(size_t index)
        {
            if(in[index]) return false;
            return in[*end++ = index] = true;
        }
        size_t pop() { return in[*begin] = false, *begin++; }
    }; // struct unique_queue

    size_t size_orig, height, size_ext;
    Container data;
    unique_queue que;

    void recalc(const size_t node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

    void rebuild()
    {
        while(!que.empty())
        {
            const size_t index = que.pop() >> 1;
            if(index && que.push(index)) recalc(index);
        }
        que.clear();
    }

    template <class Pred>
    size_t left_search_subtree(size_t index, const Pred pred, Monoid mono) const
    {
        assert(index);
        while(index < size_ext)
        {
            const Monoid tmp = data[(index <<= 1) | 1] + mono;
            if(pred(tmp)) mono = tmp;
            else ++index;
        }
        return ++index -= size_ext;
    }

    template <class Pred>
    size_t right_search_subtree(size_t index, const Pred pred, Monoid mono) const
    {
        assert(index);
        while(index < size_ext)
        {
            const Monoid tmp = mono + data[index <<= 1];
            if(pred(tmp)) ++index, mono = tmp;
        }
        return (index -= size_ext) < size_orig ? index : size_orig;
    }

public:
    using value_type = Monoid;

    segment_tree(const size_t n = 0) : size_orig{n}, height(n > 1 ? 32 - __builtin_clz(n - 1) : 0), size_ext{1u << height}, data(size_ext << 1), que(size_ext << 1) {}

    segment_tree(const size_t n, const Monoid &init) : segment_tree(n)
    {
        std::fill(std::next(std::begin(data), size_ext), std::end(data), init);
        for(size_t i{size_ext}; --i; ) recalc(i);
    }

    template <class iter_type, class value_type = typename std::iterator_traits<iter_type>::value_type>
    segment_tree(iter_type first, iter_type last)
        : size_orig(std::distance(first, last)), height(size_orig > 1 ? 32 - __builtin_clz(size_orig - 1) : 0), size_ext{1u << height}, data(size_ext << 1), que(size_ext << 1)
    {
        static_assert(std::is_constructible<Monoid, value_type>::value, "Monoid(iter_type::value_type) is not constructible.");
        for(auto iter{std::next(std::begin(data), size_ext)}; iter != std::end(data) && first != last; ++iter, ++first) *iter = Monoid{*first};
        for(size_t i{size_ext}; --i; ) recalc(i);
    }

    template <class Cont, typename = typename Cont::value_type>
    segment_tree(const Cont &cont) : segment_tree(std::begin(cont), std::end(cont)) {}

    size_t size() const { return size_orig; }
    size_t capacity() const { return size_ext; }

    // reference to the element at the index.
    Monoid &operator[](size_t index)
    {
        assert(index < size_orig);
        que.push(index |= size_ext);
        return data[index];
    }

    // const reference to the element at the index.
    const Monoid &operator[](size_t index) const
    {
        assert(index < size_orig);
        return data[index |= size_orig];
    }

    Monoid fold(size_t first, size_t last)
    {
        assert(last <= size_orig);
        rebuild();
        Monoid leftval{}, rightval{};
        first += size_ext, last += size_ext;
        while(first < last)
        {
            if(first & 1) leftval = leftval + data[first++];
            if(last & 1) rightval = data[--last] + rightval;
            first >>= 1, last >>= 1;
        }
        return leftval + rightval;
    }

    Monoid fold() { return fold(0, size_orig); }

    template <class Pred>
    size_t left_search(size_t right, const Pred pred)
    {
        assert(right <= size_orig);
        rebuild();
        right += size_ext;
        Monoid mono{};
        for(size_t left{size_ext}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const Monoid tmp = data[--right] + mono;
                if(!pred(tmp)) return left_search_subtree(right, pred, mono);
                mono = tmp;
            }
        }
        return 0;
    }

    template <class Pred>
    size_t right_search(size_t left, const Pred pred)
    {
        assert(left <= size_orig);
        rebuild();
        left += size_ext;
        Monoid mono{};
        for(size_t right{size_ext << 1}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const Monoid tmp = mono + data[left];
                if(!pred(tmp)) return right_search_subtree(left, pred, mono);
                mono = tmp;
                ++left;
            }
        }
        return size_orig;
    }
}; // class segment_tree
#line 33 "codeforces-workspace\\contest\\1404\\c\\c.cpp"

struct workspace::solver {
  solver() {
    // start here!
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    for (int i = 0; i < n; i++) {
      a[i]--;
      a[i] = i - a[i];
      if (a[i] < 0) a[i] = n;  // impossible
    }

    struct query {
      int id;
      int left;
    };
    vector<vector<query>> qs(n);
    for (int t = 0; t < q; t++) {
      int l, r;
      cin >> l >> r;
      r = n - r - 1;
      qs[r].push_back({t, l});
    }

    vector<int> ans(q);
    vector<int> f(n);
    // make f
    {
      segment_tree<int> seg(1 + n);
      for (int i = 0; i < n; i++) {
        auto pred = [&](int sum) -> bool { return sum < a[i]; };
        int x = seg.left_search(1 + i, pred) - 1;
        f[i] = x;
        if (~x) seg[x]++;
        for (auto [id, lft] : qs[i]) {
          ans[id] = seg.fold(lft, n + 1);
        }
      }
    }
    for (auto e : ans) {
      cout << e << eol;
    }
  }
};