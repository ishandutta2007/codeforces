#line 1 "codeforces-workspace\\contest\\1439\\c\\c.cpp"
#include <bits/extc++.h>

#line 4 "codeforces-workspace\\contest\\1439\\c\\c.cpp"
using namespace std;

#line 5 "Library\\src\\data_structure\\segment_tree\\lazy.hpp"

#line 2 "Library\\src\\utils\\sfinae.hpp"

/*
 * @file sfinae.hpp
 * @brief SFINAE
 */

#line 10 "Library\\src\\utils\\sfinae.hpp"
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
#line 2 "Library\\algebra\\system\\monoid.hpp"

/*
 * @file monoid.hpp
 * @brief Monoid
 */

#line 9 "Library\\algebra\\system\\monoid.hpp"

namespace workspace {

template <class T, class E = T> struct min_monoid {
  using value_type = T;
  static T min, max;
  T value;
  min_monoid() : value(max) {}
  min_monoid(const T &value) : value(value) {}
  operator T() const { return value; }
  min_monoid operator+(const min_monoid &rhs) const {
    return value < rhs.value ? *this : rhs;
  }
  min_monoid operator*(const E &rhs) const;
};

template <class T, class E>
T min_monoid<T, E>::min = std::numeric_limits<T>::min() / 2;
template <class T, class E>
T min_monoid<T, E>::max = std::numeric_limits<T>::max() / 2;

template <class T, class E = T> struct max_monoid : min_monoid<T, E> {
  using base = min_monoid<T, E>;
  using base::min_monoid;
  max_monoid() : base(base::min) {}
  max_monoid operator+(const max_monoid &rhs) const {
    return !(base::value < rhs.value) ? *this : rhs;
  }
  max_monoid operator*(const E &rhs) const;
};

}  // namespace workspace
#line 3 "Library\\src\\data_structure\\segment_tree\\waitlist.hpp"

namespace internal {
struct waitlist : std::queue<size_t> {
  waitlist(size_t n) : in(n) {}

  bool push(size_t index) {
    assert(index < in.size());
    if (in[index]) return false;
    emplace(index);
    return (in[index] = true);
  }

  size_t pop() {
    assert(!empty());
    auto index = front();
    std::queue<size_t>::pop();
    in[index] = false;
    return index;
  }

 private:
  std::vector<int_least8_t> in;
};
}
#line 9 "Library\\src\\data_structure\\segment_tree\\lazy.hpp"

template <class Monoid, class Endomorphism,
          class Monoid_container = std::vector<Monoid>,
          class Endomorphism_container = std::vector<Endomorphism>>
class lazy_segment_tree {
  static_assert(std::is_same<Monoid, mapped_type<Monoid_container>>::value);

  static_assert(
      std::is_same<Endomorphism, mapped_type<Endomorphism_container>>::value);

  static_assert(std::is_same<Monoid, decltype(Monoid{} + Monoid{})>::value,
                "\'Monoid\' has no proper binary operator+.");

  static_assert(std::is_same<Endomorphism,
                             decltype(Endomorphism{} * Endomorphism{})>::value,
                "\'Endomorphism\' has no proper binary operator*.");

  static_assert(
      std::is_same<Monoid, decltype(Monoid{} * Endomorphism{})>::value,
      "\'Endomorphism\' is not applicable to \'Monoid\'.");

  size_t size_orig, height, size_ext;
  Monoid_container data;
  Endomorphism_container lazy;
  internal::waitlist wait;

  void repair() {
    while (!wait.empty()) {
      const size_t index = wait.pop() >> 1;
      if (index && wait.push(index)) pull(index);
    }
  }

  void apply(size_t node, const Endomorphism &endo) {
    data[node] = data[node] * endo;
    if (node < size_ext) lazy[node] = lazy[node] * endo;
  }

  void push(size_t node) {
    if (!(node < size_ext)) return;
    apply(node << 1, lazy[node]);
    apply(node << 1 | 1, lazy[node]);
    lazy[node] = Endomorphism{};
  }

  void pull(size_t node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

  template <class Pred>
  size_t left_partition_subtree(size_t node, Pred pred, Monoid mono) {
    assert(node);
    while (node < size_ext) {
      push(node);
      const Monoid &tmp = data[(node <<= 1) | 1] + mono;
      if (pred(tmp))
        mono = tmp;
      else
        ++node;
    }
    return ++node -= size_ext;
  }

  template <class Pred>
  size_t right_partition_subtree(size_t node, Pred pred, Monoid mono) {
    assert(node);
    while (node < size_ext) {
      push(node);
      const Monoid &tmp = mono + data[node <<= 1];
      if (pred(tmp)) ++node, mono = tmp;
    }
    return (node -= size_ext) < size_orig ? node : size_orig;
  }

 public:
  using value_type = Monoid;

  lazy_segment_tree(size_t n = 0)
      : size_orig{n},
        height(n > 1 ? 32 - __builtin_clz(n - 1) : 0),
        size_ext{1u << height},
        data(size_ext << 1),
        lazy(size_ext),
        wait(size_ext << 1) {}

  lazy_segment_tree(size_t n, const Monoid &init) : lazy_segment_tree(n) {
    std::fill(std::next(std::begin(data), size_ext), std::end(data), init);
    for (size_t i{size_ext}; --i;) pull(i);
  }

  template <class iter_type, class value_type = typename std::iterator_traits<
                                 iter_type>::value_type>
  lazy_segment_tree(iter_type first, iter_type last)
      : size_orig(std::distance(first, last)),
        height(size_orig > 1 ? 32 - __builtin_clz(size_orig - 1) : 0),
        size_ext{1u << height},
        data(size_ext << 1),
        lazy(size_ext),
        wait(size_ext << 1) {
    static_assert(std::is_constructible<Monoid, value_type>::value,
                  "Monoid(iter_type::value_type) is not constructible.");
    for (auto iter{std::next(std::begin(data), size_ext)};
         iter != std::end(data) && first != last; ++iter, ++first)
      *iter = Monoid(*first);
    for (size_t i{size_ext}; --i;) pull(i);
  }

  template <class Container, typename = element_type<Container>>
  lazy_segment_tree(const Container &cont)
      : lazy_segment_tree(std::begin(cont), std::end(cont)) {}

  size_t size() const { return size_orig; }

  size_t capacity() const { return size_ext; }

  Monoid &operator[](size_t index) {
    assert(index < size_orig);
    index |= size_ext;
    wait.push(index);
    for (size_t i = height; i; --i) push(index >> i);
    return data[index];
  }

  void update(size_t index, const Endomorphism &endo) {
    update(index, index + 1, endo);
  }

  void update(size_t first, size_t last, const Endomorphism &endo) {
    assert(last <= size_orig);
    repair();
    if (first >= last) return;
    first += size_ext, last += size_ext - 1;
    for (size_t i = height; i; --i) push(first >> i), push(last >> i);
    for (size_t l = first, r = last + 1; last; l >>= 1, r >>= 1) {
      if (l < r) {
        if (l & 1) apply(l++, endo);
        if (r & 1) apply(--r, endo);
      }
      if (first >>= 1, last >>= 1) {
        pull(first), pull(last);
      }
    }
  }

  Monoid fold() { return fold(0, size_orig); }

  Monoid fold(size_t first, size_t last) {
    assert(last <= size_orig);
    repair();
    if (first >= last) return Monoid{};
    first += size_ext, last += size_ext - 1;
    Monoid left_val{}, right_val{};
    for (size_t l = first, r = last + 1; last; l >>= 1, r >>= 1) {
      if (l < r) {
        if (l & 1) left_val = left_val + data[l++];
        if (r & 1) right_val = data[--r] + right_val;
      }
      if (first >>= 1, last >>= 1) {
        left_val = left_val * lazy[first];
        right_val = right_val * lazy[last];
      }
    }
    return left_val + right_val;
  }

  template <class Pred> size_t left_partition(size_t right, Pred pred) {
    assert(right <= size_orig);
    repair();
    right += size_ext - 1;
    for (size_t i{height}; i; --i) push(right >> i);
    ++right;
    Monoid mono{};
    for (size_t left{size_ext}; left != right; left >>= 1, right >>= 1) {
      if ((left & 1) != (right & 1)) {
        const Monoid &tmp = data[--right] + mono;
        if (!pred(tmp)) return left_partition_subtree(right, pred, mono);
        mono = tmp;
      }
    }
    return 0;
  }

  template <class Pred> size_t right_partition(size_t left, Pred pred) {
    assert(left <= size_orig);
    repair();
    left += size_ext;
    for (size_t i{height}; i; --i) push(left >> i);
    Monoid mono{};
    for (size_t right{size_ext << 1}; left != right; left >>= 1, right >>= 1) {
      if ((left & 1) != (right & 1)) {
        const Monoid &tmp = mono + data[left];
        if (!pred(tmp)) return right_partition_subtree(left, pred, mono);
        mono = tmp;
        ++left;
      }
    }
    return size_orig;
  }
};  // class lazy_segment_tree
#line 7 "codeforces-workspace\\contest\\1439\\c\\c.cpp"

struct endo {
  long long val = 0;
  endo operator*(endo rhs) {
    if (rhs.val) return rhs;
    return *this;
  }
};

struct mono {
  long long val = 0;
  long len = 0;
  mono operator+(mono rhs) { return {val + rhs.val, len + rhs.len}; }
  mono operator*(endo rhs) {
    return rhs.val ? mono{rhs.val * len, len} : *this;
  }
};

struct mono2 {
  long val = 2e9;
  mono2 operator+(mono2 rhs) { return {min(val, rhs.val)}; }
  mono2 operator*(endo rhs) {
    if (rhs.val) {
      return {rhs.val};
    }
    return *this;
  }
};

void _main() {
  int n, q;
  cin >> n >> q;

  lazy_segment_tree<mono, endo> laz(n);
  lazy_segment_tree<mono2, endo> laz2(n);
  for (auto i = 0; i < n; ++i) {
    int a;
    cin >> a;
    laz[i] = {a, 1};
    laz2[i] = {a};
  }

  while (q--) {
    long tp, x, y;
    cin >> tp >> x >> y;

    if (tp == 1) {
      int ok = -1, ng = x;
      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if (laz2[mid].val > y)
          ok = mid;
        else
          ng = mid;
      }
      laz2.update(ok + 1, x, {y});
      laz.update(ok + 1, x, {y});
    } else {
      int ans = 0;
      --x;
      while (x < n) {
        auto nx = laz.right_partition(x, [&](mono va) { return va.val <= y; });
        auto [sum, cnt] = laz.fold(x, nx);
        y -= sum;
        ans += cnt;
        x = laz2.right_partition(nx, [&](mono2 va) { return va.val > y; });
      }
      cout << ans << "\n";
    }
  }
}

int main() {
  int t;
  // std::cin >> t;
  t = 1;
  while (t--) {
    _main();
  }
}