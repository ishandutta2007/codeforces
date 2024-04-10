#pragma GCC optimize("O3")
#include <bits/stdc++.h>

// <fastio.hpp>
#include <array>
#include <cstring>
#include <iostream>
#include <tuple>
struct IOPre {
  static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
  std::array<char, 4 * SZ> num;
  constexpr IOPre() : num{} {
    for (int i = 0; i < SZ; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = static_cast<char>(n % TEN + '0');
        n /= TEN;
      }
    }
  }
};
struct IO {
#if !HAVE_DECL_FREAD_UNLOCKED
#define fread_unlocked fread
#endif
#if !HAVE_DECL_FWRITE_UNLOCKED
#define fwrite_unlocked fwrite
#endif
  static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
                       THOUSAND = HUNDRED * TEN, TENTHOUSAND = THOUSAND * TEN,
                       MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                       TWELVE = 12, SIXTEEN = 16;
  static constexpr IOPre io_pre = {};
  std::array<char, SZ> input_buffer, output_buffer;
  int input_ptr_left, input_ptr_right, output_ptr_right;
  IO()
      : input_buffer{},
        output_buffer{},
        input_ptr_left{},
        input_ptr_right{},
        output_ptr_right{} {}
  IO(const IO&) = delete;
  IO(IO&&) = delete;
  IO& operator=(const IO&) = delete;
  IO& operator=(IO&&) = delete;
  ~IO() { flush(); }
  template <class T>
  struct is_char {
    static constexpr bool value = std::is_same_v<T, char>;
  };
  template <class T>
  struct is_bool {
    static constexpr bool value = std::is_same_v<T, bool>;
  };
  template <class T>
  struct is_string {
    static constexpr bool value =
        std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
        std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
    ;
  };
  template <class T, class D = void>
  struct is_custom {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_custom<T, std::void_t<typename T::internal_value_type>> {
    static constexpr bool value = true;
  };
  template <class T>
  struct is_default {
    static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
                                  is_string<T>::value || std::is_integral_v<T>;
  };
  template <class T, class D = void>
  struct is_iterable {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_iterable<
      T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
    static constexpr bool value = true;
  };
  template <class T, class D = void, class E = void>
  struct is_applyable {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
                      std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
    static constexpr bool value = true;
  };
  template <class T>
  static constexpr bool needs_newline = (is_iterable<T>::value ||
                                         is_applyable<T>::value) &&
                                        (!is_default<T>::value);
  template <typename T, typename U>
  struct any_needs_newline {
    static constexpr bool value = false;
  };
  template <typename T>
  struct any_needs_newline<T, std::index_sequence<>> {
    static constexpr bool value = false;
  };
  template <typename T, std::size_t I, std::size_t... Is>
  struct any_needs_newline<T, std::index_sequence<I, Is...>> {
    static constexpr bool value =
        needs_newline<decltype(std::get<I>(std::declval<T>()))> ||
        any_needs_newline<T, std::index_sequence<Is...>>::value;
  };
  inline void load() {
    memcpy(std::begin(input_buffer), std::begin(input_buffer) + input_ptr_left,
            input_ptr_right - input_ptr_left);
    input_ptr_right =
        input_ptr_right - input_ptr_left +
        static_cast<int>(fread_unlocked(
            std::begin(input_buffer) + input_ptr_right - input_ptr_left, 1,
            SZ - input_ptr_right + input_ptr_left, stdin));
    input_ptr_left = 0;
  }
  inline void read_char(char& c) {
    if (input_ptr_left + LEN > input_ptr_right) load();
    c = input_buffer[input_ptr_left++];
  }
  inline void read_string(std::string& x) {
    char c;
    while (read_char(c), c < '!') continue;
    x = c;
    while (read_char(c), c >= '!') x += c;
  }
  template <class T>
  inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
    if (input_ptr_left + LEN > input_ptr_right) load();
    char c = 0;
    do c = input_buffer[input_ptr_left++];
    while (c < '-');
    [[maybe_unused]] bool minus = false;
    if constexpr (std::is_signed<T>::value == true)
      if (c == '-') minus = true, c = input_buffer[input_ptr_left++];
    x = 0;
    while (c >= '0')
      x = x * TEN + (c & MASK), c = input_buffer[input_ptr_left++];
    if constexpr (std::is_signed<T>::value == true)
      if (minus) x = -x;
  }
  inline void skip_space() {
    if (input_ptr_left + LEN > input_ptr_right) load();
    while (input_buffer[input_ptr_left] <= ' ') input_ptr_left++;
  }
  inline void flush() {
    fwrite_unlocked(std::begin(output_buffer), 1, output_ptr_right, stdout);
    output_ptr_right = 0;
  }
  inline void write_char(char c) {
    if (output_ptr_right > SZ - LEN) flush();
    output_buffer[output_ptr_right++] = c;
  }
  inline void write_bool(bool b) {
    if (output_ptr_right > SZ - LEN) flush();
    output_buffer[output_ptr_right++] = b ? '1' : '0';
  }
  inline void write_string(const std::string& s) {
    for (auto x : s) write_char(x);
  }
  inline void write_string(const char* s) {
    while (*s) write_char(*s++);
  }
  inline void write_string(char* s) {
    while (*s) write_char(*s++);
  }
  template <typename T>
  inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
    if (output_ptr_right > SZ - LEN) flush();
    if (!x) {
      output_buffer[output_ptr_right++] = '0';
      return;
    }
    if constexpr (std::is_signed<T>::value == true)
      if (x < 0) output_buffer[output_ptr_right++] = '-', x = -x;
    int i = TWELVE;
    std::array<char, SIXTEEN> buf{};
    while (x >= TENTHOUSAND) {
      memcpy(std::begin(buf) + i,
             std::begin(io_pre.num) + (x % TENTHOUSAND) * 4, 4);
      x /= TENTHOUSAND;
      i -= 4;
    }
    if (x < HUNDRED) {
      if (x < TEN) {
        output_buffer[output_ptr_right++] = static_cast<char>('0' + x);
      } else {
        std::uint32_t q =
            (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >> MAGIC_SHIFT;
        std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
        output_buffer[output_ptr_right] = static_cast<char>('0' + q);
        output_buffer[output_ptr_right + 1] = static_cast<char>('0' + r);
        output_ptr_right += 2;
      }
    } else {
      if (x < THOUSAND) {
        memcpy(std::begin(output_buffer) + output_ptr_right,
               std::begin(io_pre.num) + (x << 2) + 1, 3),
            output_ptr_right += 3;
      } else {
        memcpy(std::begin(output_buffer) + output_ptr_right,
               std::begin(io_pre.num) + (x << 2), 4),
            output_ptr_right += 4;
      }
    }
    memcpy(std::begin(output_buffer) + output_ptr_right,
           std::begin(buf) + i + 4, TWELVE - i);
    output_ptr_right += TWELVE - i;
  }
  template <typename T_>
  IO& operator<<(T_&& x) {
    using T =
        typename std::remove_cv<typename std::remove_reference<T_>::type>::type;
    static_assert(is_custom<T>::value or is_default<T>::value or
                  is_iterable<T>::value or is_applyable<T>::value);
    if constexpr (is_custom<T>::value) {
      write_int(x.get());
    } else if constexpr (is_default<T>::value) {
      if constexpr (is_bool<T>::value) {
        write_bool(x);
      } else if constexpr (is_string<T>::value) {
        write_string(x);
      } else if constexpr (is_char<T>::value) {
        write_char(x);
      } else if constexpr (std::is_integral_v<T>) {
        write_int(x);
      }
    } else if constexpr (is_iterable<T>::value) {
      using E = decltype(*std::begin(x));
      constexpr char sep = needs_newline<E> ? '\n' : ' ';
      int i = 0;
      for (const auto& y : x) {
        if (i++) write_char(sep);
        operator<<(y);
      }
    } else if constexpr (is_applyable<T>::value) {
      constexpr char sep =
          (any_needs_newline<
              T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
              ? '\n'
              : ' ';
      int i = 0;
      std::apply(
          [this, &sep, &i](auto const&... y) {
            (((i++ ? write_char(sep) : void()), this->operator<<(y)), ...);
          },
          x);
    }
    return *this;
  }
  template <typename T>
  IO& operator>>(T& x) {
    static_assert(is_custom<T>::value or is_default<T>::value or
                  is_iterable<T>::value or is_applyable<T>::value);
    static_assert(!is_bool<T>::value);
    if constexpr (is_custom<T>::value) {
      typename T::internal_value_type y;
      read_int(y);
      x = y;
    } else if constexpr (is_default<T>::value) {
      if constexpr (is_string<T>::value) {
        read_string(x);
      } else if constexpr (is_char<T>::value) {
        read_char(x);
      } else if constexpr (std::is_integral_v<T>) {
        read_int(x);
      }
    } else if constexpr (is_iterable<T>::value) {
      for (auto& y : x) operator>>(y);
    } else if constexpr (is_applyable<T>::value) {
      std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
    }
    return *this;
  }
  IO* tie(std::nullptr_t) { return this; }
  void sync_with_stdio(bool) {}
};
namespace std {
IO io;
}  // namespace std
#define cin io
#define cout io
// </fastio.hpp>
using namespace std;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

struct Edge {
  u32 to;
  u32 w;
};

constexpr u32 mxN = 1e5;
constexpr u32 mxM = 1e5;

Edge g[mxM];
u32 g_start[mxN + 1];
u32 where[mxM];

struct cmp {
  bool operator()(pair<u64, u32> a, pair<u64, u32> b) const {
    return a.first > b.first;
  }
};

u32 q0begin = 0;
u32 q0end = 0;
u32 q1begin = 0;
u32 q1end = 0;
u16 que0[mxM * 5];
u16 que1[mxM * 5];
u64 dist[mxN];
bool queued[mxN];

void spfa() {
  fill(dist, dist + mxN, ~u64(0));

  auto try_push = [&](u64 d, u32 i) {
    if (dist[i] > d) {
      dist[i] = d;
      if (!queued[i]) {
        queued[i] = true;

        if (i < 1 << 16)
          que0[q0end++] = u16(i);
        else
          que1[q1end++] = u16(i ^ (1 << 16));
      }
    }
  };

  q0begin = q0end = 0;
  q1begin = q1end = 0;
  try_push(0, 0);

  while (q0begin < q0end || q1begin < q1end) {
    u32 i;

    auto use_q0 = [&]() {
      i = que0[q0begin];
      u32 j = que0[q0end - 1];
      if (dist[i] > dist[j]) {
        i = j;
        --q0end;
      } else {
        ++q0begin;
      }
    };

    auto use_q1 = [&]() {
      i = que1[q1begin] ^ (1 << 16);
      u32 j = que1[q1end - 1] ^ (1 << 16);
      if (dist[i] > dist[j]) {
        i = j;
        --q1end;
      } else {
        ++q1begin;
      }
    };

    if (q1begin == q1end) {
      use_q0();
    } else if (q0begin == q0end) {
      use_q1();
    } else {
      u32 i0 = que0[q0begin];
      u32 j0 = que0[q0end - 1];
      u32 i1 = que1[q1begin] ^ (1 << 16);
      u32 j1 = que1[q1end - 1] ^ (1 << 16);
      u64 d0 = min(dist[i0], dist[j0]);
      u64 d1 = min(dist[i1], dist[j1]);
      if (d0 <= d1) use_q0();
      else use_q1();
    }

    queued[i] = false;
    for (u32 p = g_start[i]; p != g_start[i + 1]; ++p) {
      auto [j, w] = g[p];
      try_push(dist[i] + w, j);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  u32 n, m, q;
  cin >> n >> m >> q;

  {
    vector<array<u32, 3>> edges(m);
    for (auto &[i, j, w] : edges) {
      cin >> i >> j >> w, --i, --j;
      ++g_start[i + 2];
    }

    for (u32 i = 0; i != n; ++i) g_start[i + 1] += g_start[i];

    vector<u32> mm_order(m);
    iota(mm_order.begin(), mm_order.end(), 0);
    mt19937 rng(
        chrono::high_resolution_clock::now().time_since_epoch().count());
    shuffle(mm_order.begin(), mm_order.end(), rng);

    for (u32 mm : mm_order) {
      auto [i, j, w] = edges[mm];
      where[mm] = g_start[i + 1];
      g[g_start[i + 1]++] = {j, w};
    }
  }

  bool changed = true;

  while (q--) {
    char qt;
    cin >> qt;
    if (qt == '1') {
      u32 v;
      cin >> v;
      --v;
      if (exchange(changed, false)) spfa();
      if (dist[v] == ~u64(0))
        cout << "-1\n";
      else
        cout << dist[v] << '\n';
    } else if (qt == '2') {
      u32 cnt;
      cin >> cnt;
      while (cnt--) {
        u32 e;
        cin >> e;
        --e;
        ++g[where[e]].w;
      }
      changed = true;
    } else
      assert(false && "invalid query type");
  }
}