/* preprocessor start */
#ifdef LOCAL
//*
    #define _GLIBCXX_DEBUG  // gcc
/*/
    #define _LIBCPP_DEBUG 0 // clang
//*/
    #define __clock__
    // #define __buffer_check__
#else
    #pragma GCC optimize("Ofast")
/*
    #define _GLIBCXX_DEBUG  // gcc
/*/
//    #define _LIBCPP_DEBUG 0 // clang
//*/
    // #define __buffer_check__
    // #define NDEBUG
#endif
#define __precision__ 10
#define iostream_untie true
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#define __all(v) std::begin(v), std::end(v)
#define __rall(v) std::rbegin(v), std::rend(v)
#define __popcount(n) __builtin_popcountll(n)
#define __clz32(n) __builtin_clz(n)
#define __clz64(n) __builtin_clzll(n)
#define __ctz32(n) __builtin_ctz(n)
#define __ctz64(n) __builtin_ctzll(n)
/* preprocessor end */

namespace std
{
    // hash
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    // iostream
    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} // namespace std

namespace setting
{
    using namespace std;
    using namespace chrono;
    system_clock::time_point start_time, end_time;
    long long get_elapsed_time() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void print_elapsed_time() { cerr << "\n----- Exec time : " << get_elapsed_time() << " ms -----\n"; }
    void buffer_check() { char bufc; if(cin >> bufc) cerr << "\n\033[1;35mwarning\033[0m: buffer not empty.\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) ios::sync_with_stdio(false), cin.tie(nullptr);
            cout << fixed << setprecision(__precision__);
    #ifdef stderr_path
            if(freopen(stderr_path, "a", stderr)) cerr << fixed << setprecision(__precision__);
    #endif
    #ifdef LOCAL
            cerr << "\n----- stderr at LOCAL -----\n\n";
    #endif
    #ifdef __buffer_check__
            atexit(buffer_check);
    #endif
    #ifdef __clock__
            start_time = system_clock::now();
            atexit(print_elapsed_time);
    #endif
        }
    } __setupper; // struct setupper
} // namespace setting

#ifdef __clock__
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\Clock.hpp"
#else
    #define build_clock() ((void)0)
    #define set_clock() ((void)0)
    #define get_clock() ((void)0)
#endif

#ifdef LOCAL
    #include "C:\Users\euler\OneDrive\Documents\Competitive_Programming\Library\local\Dump.hpp"
#else
    #define dump(...) ((void)0)
#endif

/* function utility start */
template <class T, class... types> T read(types... args) noexcept { T obj(args...); std::cin >> obj; return obj; }
#define input(type, var, ...) type var{read<type>(__VA_ARGS__)}
// substitute y for x if x > y.
template <class T> inline bool sbmin(T &x, const T &y) { return x > y ? x = y, true : false; }
// substitute y for x if x < y.
template <class T> inline bool sbmax(T &x, const T &y) { return x < y ? x = y, true : false; }
// binary search on discrete range.
template <class iter_type, class pred_type>
iter_type binary(iter_type __ok, iter_type __ng, pred_type pred)
{
    std::ptrdiff_t dist(__ng - __ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(__ok + dist / 2);
        if(pred(mid)) __ok = mid, dist -= dist / 2;
        else __ng = mid, dist /= 2;
    }
    return __ok;
}
// binary search on real numbers.
template <class pred_type>
long double binary(long double __ok, long double __ng, const long double eps, pred_type pred)
{
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}
// reset all bits.
template <class A> void reset(A &array) { memset(array, 0, sizeof(array)); }
// be careful that val is type-sensitive.
template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
/* functon utility end */

/* using alias start */
using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using pii = pair<i32, i32>; using pll = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;
/* using alias end */

/* library start */

// verified at https://codeforces.com/contest/1202/submission/59818756
#ifndef Trie_hpp
#define Trie_hpp
#include <map>

template <class str_type>
struct trie
{
    struct Aho_Corasick;
    struct node;
    using char_type = typename str_type::value_type;
    using dict_type = std::map<char_type, node*>;

    struct node
    {
        const char_type tag;
        const bool is_ter;
        node *const par, *ter;
        dict_type child;
        size_t cnt, type;

        node() : tag(), is_ter(), par(), ter(), child(), cnt(), type() {}

        node(node *const p) : tag(), is_ter(true), par(p), ter(), child(), cnt(), type() {}

        node(const char_type &_tag, node *const p) : tag(_tag), is_ter(), par(p), ter(), child(), cnt(), type() {}

        ~node() { delete ter; for(auto &e : child) delete e.second; }

        node *add(const char_type &x)
        {
            node *&p = child[x];
            return p ? p : p = new node(x, this);
        }

        node *add()
        {
            return sfx_wrd++, ter ? ter : ter = new node(this);
        }

    private:
        friend bool valid(const node *const p)
        {
            return p and p->cnt and p->type;
        }
        
        friend Aho_Corasick;

        node *failure = nullptr;

        size_t sfx_wrd = 0;
    }; // struct node

    node *const root;

    trie() : root(new node) {}
    ~trie() { delete root; }

    size_t size() const { return root->cnt; }
    size_t type() const { return root->type; }

    node *insert(const str_type &s)
    {
        node *p = root;
        p->cnt++;
        for(const char_type &x : s)
        {
            (p = p->add(x))->cnt++;
        }
        node *ret = p = p->add();
        if(not p->cnt++)
        {
            while(p)
            {
                p->type++;
                p = p->par;
            }
        }
        return ret;
    }

    size_t erase(const str_type &s, size_t k = 1)
    {
        node *p = root;
        for(const char_type &x : s)
        {
            p = p->child[x];
            if(not p) return 0;
        }
        p = p->ter;
        if(not p) return 0;
        bool ext = k >= p->cnt;
        if(ext)
        {
            k = p->cnt;
            p->par->suf_wrd--;
        }
        while(p)
        {
            p->cnt -= k;
            p->type -= ext;
            p = p->par;
        }
        return k;
    }

    size_t erase(size_t idx)
    {
        if(idx >= size()) return 0;
        node *p = root;
        while(true)
        {
            if(p->ter)
            {
                size_t here = p->ter->cnt;
                if(idx < here)
                {
                    p = p->ter;
                    break;
                }
                idx -= here;
            }
            node *nx = nullptr;
            for(const auto &e : p->child)
            {
                char_type x;
                node *t;
                tie(x, t) = e;
                size_t here = t ? t->cnt : 0;
                if(idx < here)
                {
                    nx = t;
                    break;
                }
                else
                {
                    idx -= here;
                }
            }
            p = nx;
        }
        bool ext = not--p->ter->cnt;
        while(p)
        {
            p->cnt--;
            p->type -= ext;
            p = p->par;
        }
        return 1;
    }

    size_t count(const str_type &s) const
    {
        node *p = root;
        for(const char_type &x : s)
        {
            p = p->child[x];
            if(!p->child[x]) return 0;
        }
        p = p->ter;
        return p ? p->cnt : 0;
    }

    /*
    size_t lower_bound(const str_type &s) const
    {
        size_t ret = 0;
        node *p = root;
        for(const char_type &x : s)
        {
            if(not p) break;
            if(p->ter) ret += p->ter->cnt;
            for(const auto &e : p->child)
            {
                if(e.first == x) break;
                node *t = e.second;
                if(t) ret += t->cnt;
            }
            p = p->child[x];
        }
        return ret;
    }

    size_t upper_bound(const str_type &s) const
    {
        size_t ret = 0;
        node *p = root;
        for(const char_type &x : s)
        {
            if(not p) break;
            if(p->ter) ret += p->ter->cnt;
            for(const auto &e : p->child)
            {
                if(e.first == x) break;
                node *t = e.second;
                if(t) ret += t->cnt;
            }
            p = p->child[x];
        }
        if(p and p->ter) ret += p->ter->cnt;
        return ret;
    }
    //*/

    str_type operator[](size_t idx) const
    {
        assert(idx < size());
        node *p = root;
        str_type ret = str_type();
        while(true)
        {
            if(p->ter)
            {
                size_t here = p->ter->cnt;
                if(idx < here) break;
                idx -= here;
            }
            node *nx = nullptr;
            for(const auto &e : p->child)
            {
                char_type x;
                node *t;
                std::tie(x, t) = e;
                size_t here = t ? t->cnt : 0;
                if(idx < here)
                {
                    ret.push_back(x);
                    nx = t;
                    break;
                }
                idx -= here;
            }
            p = nx;
        }
        return ret;
    }

    struct iterator_type : std::iterator<std::bidirectional_iterator_tag, str_type, std::ptrdiff_t, node *, str_type>
    {
        trie *const trie_ptr;
        node *node_ptr;
        str_type s;
        size_t type_idx, size_idx;

        iterator_type() : trie_ptr(), node_ptr(), s(), type_idx(-1), size_idx(-1) {}
        iterator_type(const iterator_type &itr) : trie_ptr(itr.trie_ptr), node_ptr(itr.node_ptr), s(itr.s), type_idx(itr.type_idx), size_idx(itr.size_idx) {}
        iterator_type(trie *_trie_ptr, size_t _type_idx) : trie_ptr(_trie_ptr), node_ptr(), s(), type_idx(_type_idx), size_idx()
        {
            if(_type_idx < trie_ptr->type())
            {
                node *&p = (node_ptr = trie_ptr->root);
                while(p)
                {
                    size_t here_typ = p->ter ? p->ter->type : 0;
                    size_t here_cnt = p->ter ? p->ter->cnt : 0;
                    if(_type_idx < here_typ)
                    {
                        p = p->ter;
                        break;
                    }
                    _type_idx -= here_typ;
                    size_idx += here_cnt;
                    node *nx = nullptr;
                    for(const auto &e : p->child)
                    {
                        char_type x;
                        node *t;
                        std::tie(x, t) = e;
                        here_typ = t ? t->type : 0;
                        here_cnt = t ? t->cnt : 0;
                        if(_type_idx < here_typ)
                        {
                            s.push_back(x);
                            nx = t;
                            break;
                        }
                        _type_idx -= here_typ;
                        size_idx += here_cnt;
                    }
                    p = nx;
                }
            }
            else
            {
                size_idx = trie_ptr->size();
            }
        }

        iterator_type(trie *_trie_ptr, node *_node_ptr, const str_type &_s, size_t _type_idx, size_t _size_idx) : trie_ptr(_trie_ptr), node_ptr(_node_ptr), s(_s), type_idx(_type_idx), size_idx(_size_idx) {}

        node *operator->() const { return node_ptr; }

        str_type operator*() const { return s; }

        bool operator==(const iterator_type &itr) const { return trie_ptr == itr.trie_ptr and type_idx == itr.type_idx; }

        bool operator!=(const iterator_type &itr) const { return not(*this == itr); }

        iterator_type &operator++()
        {
            size_idx += count();
            node *p = node_ptr;
            while(p->par)
            {
                auto dict_itr = p->par->child.begin();
                if(not p->is_ter)
                {
                    dict_itr = p->par->child.upper_bound(p->tag);
                    s.pop_back();
                }
                p = p->par;
                while(dict_itr != p->child.end() and not valid(dict_itr->second)) ++dict_itr;
                if(dict_itr != p->child.end())
                {
                    p = dict_itr->second;
                    s.push_back(p->tag);
                    break;
                }
            }
            if(!p->par)
            {
                node_ptr = nullptr;
            }
            else
            {
                while(not valid(p->ter))
                {
                    node *nx = nullptr;
                    for(const auto &e : p->child)
                    {
                        char_type x;
                        node *t;
                        std::tie(x, t) = e;
                        if(valid(t))
                        {
                            s.push_back(x);
                            nx = t;
                            break;
                        }
                    }
                    p = nx;
                }
                node_ptr = p->ter;
            }
            ++type_idx;
            return *this;
        }

        iterator_type operator++(int)
        {
            iterator_type ret = *this;
            return ++(*this), ret;
        }

        iterator_type &operator--()
        {
            if(*this == trie_ptr->end())
            {
                node *p = trie_ptr->root;
                if(p->type)
                {
                    while(not p->is_ter)
                    {
                        auto dict_itr = p->child.rbegin();
                        while(dict_itr != p->child.rend() and
                            not valid(dict_itr->second))
                        {
                            ++dict_itr;
                        }
                        if(dict_itr != p->child.rend())
                        {
                            p = dict_itr->second;
                            s.push_back(p->tag);
                        }
                        else
                        {
                            p = p->ter;
                        }
                    }
                    node_ptr = p;
                }
            }
            else
            {
                bool is_prefix = false;
                node *p = node_ptr->par;
                while(p->par)
                {
                    auto map_ritr = p->par->child.rend();
                    map_ritr = std::reverse_iterator<typename dict_type::iterator>(
                        p->par->child.lower_bound(p->tag));
                    s.pop_back();
                    p = p->par;
                    while(map_ritr != p->child.rend() and
                        not valid(map_ritr->second))
                        ++map_ritr;
                    if(map_ritr != p->child.rend())
                    {
                        p = map_ritr->second;
                        s.push_back(map_ritr->first);
                        break;
                    }
                    else if(p->ter and p->ter->type)
                    {
                        is_prefix = true;
                        break;
                    }
                }
                if(is_prefix)
                {
                    node_ptr = p->ter;
                }
                else
                {
                    if(!p->par)
                    {
                        node_ptr = nullptr;
                    }
                    else
                    {
                        while(not p->is_ter)
                        {
                            auto map_ritr = p->child.rbegin();
                            while(map_ritr != p->child.rend() and
                                not valid(map_ritr->second))
                                ++map_ritr;
                            if(map_ritr != p->child.rend())
                            {
                                s.push_back(map_ritr->first);
                                p = map_ritr->second;
                            }
                            else
                            {
                                p = p->ter;
                            }
                        }
                        node_ptr = p;
                    }
                }
            }
            --type_idx;
            if(node_ptr)
                size_idx -= node_ptr->cnt;
            else
                size_idx = -1;
            return *this;
        }

        iterator_type operator--(int)
        {
            iterator_type ret = *this;
            return --(*this), ret;
        }

        size_t count() const
        {
            return node_ptr ? node_ptr->cnt : 0;
        }
    }; // class iterator_type
    friend iterator_type;

    iterator_type begin() { return iterator_type(this, 0); }
    iterator_type end() { return iterator_type(this, type()); }
    std::reverse_iterator<iterator_type> rbegin() { return std::reverse_iterator<iterator_type>(end()); }
    std::reverse_iterator<iterator_type> rend() { return std::reverse_iterator<iterator_type>(begin()); }

    iterator_type lower_bound(const str_type &key)
    {
        size_t size_idx = 0, type_idx = 0;
        str_type s;
        node *p = root;
        bool go_back = false;
        for(const char_type &x : key)
        {
            if(p->ter)
            {
                size_idx += p->ter->cnt;
                type_idx += p->ter->type;
            }
            node *nx = nullptr;
            for(const auto &e : p->child)
            {
                char_type y;
                node *t;
                std::tie(y, t) = e;
                if(valid(t))
                {
                    if(y < x)
                    {
                        size_idx += t->cnt;
                        type_idx += t->type;
                    }
                    else if(t->type)
                    {
                        s.push_back(y);
                        nx = t;
                        break;
                    }
                }
            }
            if(not nx)
            {
                go_back = true;
                break;
            }
            p = nx;
            if(p->tag > x) break;
        }
        if(go_back)
        {
            while(!p->par)
            {
                p = p->par;
                auto dict_itr = p->child.upper_bound(s.back());
                s.pop_back();
                while(dict_itr != p->child.end() and
                    not valid(dict_itr->second))
                    ++dict_itr;
                if(dict_itr != p->child.end())
                {
                    p = dict_itr->second;
                    s.push_back(dict_itr->first);
                    break;
                }
            }
            if(!p->par) return end();
        }
        while(not p->is_ter)
        {
            if(valid(p->ter))
            {
                p = p->ter;
            }
            else
            {
                auto dict_itr = p->child.begin();
                while(dict_itr != p->child.end() and
                    not valid(dict_itr->second))
                    ++dict_itr;
                p = dict_itr->second;
                s.push_back(dict_itr->first);
            }
        }
        return iterator_type(this, p, s, type_idx, size_idx);
    }

    iterator_type upper_bound(const str_type &key)
    {
        auto itr = lower_bound(key);
        if(*itr == key) ++itr;
        return itr;
    }

    struct Aho_Corasick
    {
        node *root;

        Aho_Corasick() : root() {}
        Aho_Corasick(const trie &trie) { build(trie); }

        node *build(const trie<str_type> &trie)
        {
            root = trie.root;
            std::queue<node*> que;
            que.emplace(root);
            while(!que.empty())
            {
                node *const now = que.front();
                que.pop();
                for(const auto &e : now->child)
                {
                    char_type x;
                    node *t, *p = now;
                    std::tie(x, t) = e;
                    do
                    {
                        p = p->failure;
                    } while(p and not p->child[x]);
                    t->failure = p ? p->child[x] : root;
                    t->sfx_wrd += t->failure->sfx_wrd;
                    que.emplace(t);
                }
            }
            return root;
        }

        node *next(node *now, const char_type &x)
        {
            while(now and not now->child[x])
            {
                now = now->failure;
            }
            return now = now ? now->child[x] : root;
        }

        size_t query(node *now) { return now->sfx_wrd; }
    }; // struct Aho_Corasick
}; // struct trie

#endif // Trie_hpp

/* library end */

/* The main code follows. */


struct solver
{

    solver()
    {
        input(string,t);
        input(size_t,n);
        trie<string> tr,rtr;
        for(size_t i=0; i!=n; ++i)
        {
            input(string,s);
            tr.insert(s);
            reverse(__all(s));
            rtr.insert(s);
        }
        trie<string>::Aho_Corasick aho;
        vector<i64> l(t.size()+1);
        auto ptr=aho.build(tr);
        for(size_t i=0; i!=t.size(); ++i)
        {
            l[i]=aho.query(ptr);
            ptr=aho.next(ptr,t[i]);
        }
        dump(l);
        i64 ans{};
        ptr=aho.build(rtr);
        for(size_t i=t.size(); i--;)
        {
            ptr=aho.next(ptr,t[i]);
            ans+=l[i]*aho.query(ptr);
        }
        cout << ans << "\n";
    }
}; // struct solver

int main(int argc, char *argv[])
{
    u32 t; // loop count
#ifdef LOCAL
    t = 1;
#else
    t = 1; // single test case
#endif
    // t = -1; // infinite loop
    // cin >> t; // case number given

    while(t--)
    {
        solver();
    }
}