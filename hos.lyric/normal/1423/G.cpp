//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL









#include <cassert>

#include <numeric>

#include <type_traits>

namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;
template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

} // namespace internal

} // namespace atcoder


#include <vector>

namespace atcoder {

// Reference: https://en.wikipedia.org/wiki/Fenwick_tree
template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

} // namespace atcoder

using namespace atcoder;




#include <algorithm>

#include <array>

#include <bitset>


#include <complex>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <map>


#include <queue>

#include <set>

#include <string>

#include <unordered_map>

#include <unordered_set>


using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;



#include <unistd.h>

struct Scanner {
    int fd = -1;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += ::read(fd, line + ed, (1 << 15) - ed);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) {
            bool sep = false;
            for (size_t i = st; i < ed; i++) {
                if (isspace(line[i])) {
                    sep = true;
                    break;
                }
            }
            if (!sep) reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] & 0xf);
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    int read_unsafe() { return 0; }
    template <class H, class... T> int read_unsafe(H& h, T&... t) {
        bool f = read_single(h);
        if (!f) return 0;
        return 1 + read_unsafe(t...);
    }
    Scanner(FILE* fp) : fd(fileno(fp)) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char(0x30 | (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(__int128 val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char(0x30 | (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }

    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};

Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

using P = pair<int, int>;
using Q = tuple<int, int, int>;

int main() {
    int n, q;
    sc.read(n, q);

    V<set<P>> stv(n + q);
    map<int, int> col2id;
    auto get_id = [&](int col) {
        if (!col2id.count(col)) {
            int id = int(col2id.size());
            col2id[col] = id;
        }
        return col2id[col];
    };
    set<Q> st;

    fenwick_tree<ll> fw0(n + 2), fw1(n + 2);

    auto rng_detect = [&](int p, int id, int f) {
        auto it = stv[id].lower_bound({p, -1});
        int r = (it == stv[id].end()) ? n : it->first;
        int l = (it == stv[id].begin()) ? 0 : prev(it)->second;
        if (p < l || r <= p) return;

        int di = r - l;

                  ;

        // 1 -= di
        // 2 -= (di - 1)
        // di -= 1

        // ->
        // offset: -di - 1
        // 1 += 1
        // 2 += 2
        // di += di

        fw1.add(1, 1 * f);
        fw1.add(di + 1, -1 * f);

        fw0.add(1, (-di - 1) * f);
        fw0.add(di + 1, -(-di - 1) * f);
    };
    auto add_rng = [&](int l, int r, int id) {
        rng_detect(l, id, -1);
        stv[id].insert({l, r});
        st.insert({l, r, id});
        rng_detect(l - 1, id, 1);
        rng_detect(r, id, 1);
    };
    auto del_rng = [&](int l, int r, int id) {
        rng_detect(l - 1, id, -1);
        rng_detect(r, id, -1);
        stv[id].erase({l, r});
        st.erase({l, r, id});
        rng_detect(l, id, 1);
    };
    for (int i = 0; i < n + q; i++) {
        rng_detect(0, i, 1);
    }

    for (int i = 0; i < n; i++) {
        int a;
        sc.read(a);
        int id = get_id(a);
        add_rng(i, i + 1, id);

    }

    for (int ph = 0; ph < q; ph++) {
        int t;
        sc.read(t);
        if (t == 1) {
            int l, r, _id;
            sc.read(l, r, _id);
            l--;
            int id = get_id(_id);

            while (true) {
                auto it = st.lower_bound({l, -1, -1});
                if (it == st.end() || r <= get<0>(*it)) {
                    if (it == st.begin()) break;
                    int nl, nr, nid;
                    it--;
                    tie(nl, nr, nid) = *it;
                    if (nr <= l) break;
                    del_rng(nl, nr, nid);
                    add_rng(nl, l, nid);
                    if (r < nr) {
                        add_rng(r, nr, nid);
                    }
                    break;
                }
                int nl, nr, nid;
                tie(nl, nr, nid) = *it;
                del_rng(nl, nr, nid);
                if (nr <= r) continue;
                add_rng(r, nr, nid);
                continue;
            }
            add_rng(l, r, id);
        } else {
            int k;
            sc.read(k);
            pr.writeln(1LL * (n + q) * (n - k + 1) + (fw0.sum(0, k + 1) + fw1.sum(0, k + 1) * k));
        }
    }

    return 0;
}