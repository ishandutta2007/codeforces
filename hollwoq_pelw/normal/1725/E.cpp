#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

template<typename T>
struct modular_base{
    using Type = typename decay<decltype(T::value)>::type;
    template<class U>
    static vector<modular_base<T>> precalc_power(U base, size_t SZ){
        vector<modular_base<T>> res(SZ + 1, 1);
        for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
        return res;
    }
    static vector<Type> _INV;
    static void precalc_inverse(size_t SZ){
        if(_INV.empty()) _INV.assign(2, 1);
        for(auto x = (int)_INV.size(); x <= SZ; ++ x) _INV.push_back((mod() - 1LL * mod() / x * _INV[mod() % x]) % mod());
    }
    // mod must be a prime
    static Type _primitive_root;
    static modular_base<T> primitive_root(){
        if(_primitive_root) return _primitive_root;
        if(mod() == 2) return _primitive_root = 1;
        if(mod() == 998244353) return _primitive_root = 3;
        Type divs[20] = {};
        divs[0] = 2;
        int cnt = 1;
        Type x = (mod() - 1) / 2;
        while(x % 2 == 0) x /= 2;
        for(auto i = 3; 1LL * i * i <= x; i += 2){
            if(x % i == 0){
                divs[cnt ++] = i;
                while(x % i == 0) x /= i;
            }
        }
        if(x > 1) divs[cnt ++] = x;
        for(auto g = 2; ; ++ g){
            bool ok = true;
            for(auto i = 0; i < cnt; ++ i){
                if((modular_base<T>(g) ^ (mod() - 1) / divs[i]) == 1){
                    ok = false;
                    break;
                }
            }
            if(ok) return _primitive_root = g;
        }
    }
    constexpr modular_base(): value(){ }
    modular_base(const double &x){ value = normalize(llround(x)); }
    modular_base(const long double &x){ value = normalize(llround(x)); }
    template<typename U> modular_base(const U &x){ value = normalize(x); }
    template<typename U> static Type normalize(const U &x){
        Type v;
        if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if(v < 0) v += mod();
        return v;
    }
    const Type& operator()() const{ return value; }
    template<typename U> operator U() const{ return value; }
    constexpr static Type mod(){ return T::value; }
    modular_base &operator+=(const modular_base &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
    modular_base &operator-=(const modular_base &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
    template<typename U> modular_base &operator+=(const U &otr){ return *this += modular_base(otr); }
    template<typename U> modular_base &operator-=(const U &otr){ return *this -= modular_base(otr); }
    modular_base &operator++(){ return *this += 1; }
    modular_base &operator--(){ return *this -= 1; }
    modular_base operator++(int){ modular_base result(*this); *this += 1; return result; }
    modular_base operator--(int){ modular_base result(*this); *this -= 1; return result; }
    modular_base operator-() const{ return modular_base(-value); }
    template<typename U = T>
    typename enable_if<is_same<typename modular_base<U>::Type, int>::value, modular_base>::type &operator*=(const modular_base& rhs){
        #ifdef _WIN32
        unsigned long long x = static_cast<long long>(value) * static_cast<long long>(rhs.value);
        unsigned int xh = static_cast<unsigned int>(x >> 32), xl = static_cast<unsigned int>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
        #else
        value = normalize(static_cast<long long>(value) * static_cast<long long>(rhs.value));
        #endif
        return *this;
    }
    template<typename U = T>
    typename enable_if<is_same<typename modular_base<U>::Type, long long>::value, modular_base>::type &operator*=(const modular_base &rhs){
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template<typename U = T>
    typename enable_if<!is_integral<typename modular_base<U>::Type>::value, modular_base>::type &operator*=(const modular_base &rhs){
        value = normalize(value * rhs.value);
        return *this;
    }
    template<typename U>
    modular_base &operator^=(U e){
        if(e < 0) *this = 1 / *this, e = -e;
        modular_base res = 1;
        for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
        return *this = res;
    }
    template<typename U>
    modular_base operator^(U e) const{
        return modular_base(*this) ^= e;
    }
    modular_base &operator/=(const modular_base &otr){
        Type a = otr.value, m = mod(), u = 0, v = 1;
        if(a < (int)_INV.size()) return *this *= _INV[a];
        while(a){
            Type t = m / a;
            m -= t * a; swap(a, m);
            u -= t * v; swap(u, v);
        }
        assert(m == 1);
        return *this *= u;
    }
    Type value;
};
template<typename T>
vector<typename std::decay<decltype (T::value)>::type> modular_base<T>::_INV;
template<typename T>
typename std::decay<decltype (T::value)>::type modular_base<T>::_primitive_root;
template<typename T> bool operator==(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const modular_base<T>& lhs, U rhs){ return lhs == modular_base<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) == rhs; }
template<typename T> bool operator!=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const modular_base<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> modular_base<T> operator+(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(const modular_base<T> &lhs, U rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T> modular_base<T> operator-(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T> modular_base<T> operator*(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T> modular_base<T> operator/(const modular_base<T> &lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(const modular_base<T>& lhs, U rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(U lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, modular_base<T> &number){
    typename common_type<typename modular_base<T>::Type, long long>::type x;
    in >> x;
    number.value = modular_base<T>::normalize(x);
    return in;
}
#define _PRINT_AS_FRACTION
template<typename T> ostream &operator<<(ostream &out, const modular_base<T> &number){
#ifdef LOCAL
#ifdef _PRINT_AS_FRACTION
    for(auto d = 1; ; ++ d){
        if((number * d).value <= 1000000){
            out << (number * d).value << "/" << d;
            break;
        }
        else if((-number * d).value <= 1000000){
            out << "-" << (-number * d).value << "/" << d;
            break;
        }
    }
    return out;
#else
    return out << number();
#endif
#else
    return out << number();
#endif
}
#undef _PRINT_AS_FRACTION

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using modular = modular_base<VarMod>;
*/

// constexpr int mod = 1e9 + 7; // 1000000007
constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using modular = modular_base<integral_constant<decay<decltype(mod)>::type, mod>>;

template<class T>
struct graph{
    struct E{
        int from, to;
        T cost;
    };
    int n;
    vector<E> edge;
    vector<vector<int>> adj;
    function<bool(int)> ignore;
    graph(int n = 0): n(n), adj(n){ }
    graph(const vector<vector<int>> &adj, bool undirected = true): n(n){
        if(undirected) for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) if(u < v) link(u, v);
        else for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) orient(u, v);
    }
    graph(const vector<vector<pair<int, T>>> &adj, bool undirected = true): n(n){
        if(undirected) for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) if(u < v) link(u, v, w);
        else for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) orient(u, v, w);
    }
    graph(int n, vector<array<int, 2>> &edge, bool undirected = true): n(n){
        for(auto [u, v]: edge) undirected ? link(u, v) : orient(u, v);
    }
    graph(int n, vector<tuple<int, int, T>> &edge, bool undirected = true): n(n){
        for(auto [u, v, w]: edge) undirected ? link(u, v, w) : orient(u, v, w);
    }
    int operator()(int u, int id) const{
        #ifdef LOCAL
        assert(0 <= id && id < (int)edge.size());
        assert(edge[id].from == u || edge[id].to == u);
        #endif
        return u ^ edge[id].from ^ edge[id].to;
    }
    int link(int u, int v, T w = {}){ // insert an undirected edge
        int id = (int)edge.size();
        adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
        return id;
    }
    int orient(int u, int v, T w = {}){ // insert a directed edge
        int id = (int)edge.size();
        adj[u].push_back(id), edge.push_back({u, v, w});
        return id;
    }
    graph transposed() const{ // the transpose of the directed graph
        graph res(n);
        for(auto &e: edge) res.orient(e.to, e.from, e.cost);
        res.ignore = ignore;
        return res;
    }
    int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
        return (int)adj[u].size();
    }
    vector<vector<int>> get_adjacency_list() const{
        vector<vector<int>> res(n);
        for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
            if(ignore && ignore(id)) continue;
            auto &e = edge[id];
            int v = u ^ e.from ^ e.to;
            res[u].push_back(v);
        }
        return res;
    }
    void set_ignoration_rule(const function<bool(int)> &f){
        ignore = f;
    }
    void reset_ignoration_rule(){
        ignore = nullptr;
    }
    friend ostream &operator<<(ostream &out, const graph &g){
        for(auto id = 0; id < (int)g.edge.size(); ++ id){
            if(g.ignore && g.ignore(id)) continue;
            auto &e = g.edge[id];
            out << "{" << e.from << ", " << e.to << ", " << e.cost << "}\n";
        }
        return out;
    }
};

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
    int n;
    vector<vector<T>> data;
    Compare cmp;
    T T_id;
    range_minmax_query_solver(){ }
    // O(n log n)
    range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
        for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
            data.emplace_back(n - (p << 1) + 1);
            for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
        }
    }
    // O(1)
    T query(int l, int r) const{
        assert(0 <= l && l <= r && r <= n);
        if(l == r) return T_id;
        int d = __lg(r - l);
        return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
    }
};

// Requires graph and range_minmax_query_solver
struct lca_solver{
    int n;
    vector<int> pv, pe, pos, end, depth, order, pos_order;
    range_minmax_query_solver<int> rmq;
    // O(|V| log |V|)
    template<class T>
    lca_solver(const graph<T> &g, const vector<int> &roots): n(g.n), pv(n, -1), pe(n, -1), depth(n), pos(n, -1), end(n, -1){
        int it = 0;
        auto dfs = [&](auto self, int u)->void{
            pos[u] = (int)order.size();
            order.push_back(u), pos_order.push_back(pos[u]);
            for(auto id: g.adj[u]){
                if(id == pe[u] || g.ignore && g.ignore(id)) continue;
                auto &e = g.edge[id];
                int v = u ^ e.from ^ e.to;
                pv[v] = u;
                pe[v] = id;
                depth[v] = depth[u] + 1;
                self(self, v);
                order.push_back(u), pos_order.push_back(pos[u]);
            }
            end[u] = (int)order.size();
        };
        for(auto root: roots) if(!~pos[root]) dfs(dfs, root);
        rmq = {pos_order};
    }
    // assumes u and v are on the same component
    // O(1)
    int lca(int u, int v) const{
        if(u == v) return u;
        tie(u, v) = minmax(pos[u], pos[v]);
        return order[rmq.query(u, v)];
    }
    // assumes u and v are on the same component
    // O(1)
    int steps(int u, int v, int w = -1) const{
        return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
    }
    // O(1)
    bool ancestor_of(int u, int v) const{
        return pos[u] <= pos[v] && end[v] <= end[u];
    }
};

// Build the minimal tree containing all the nodes
// O(|subset| * log(|subset|))
// Requires graph, range_minmax_query_solver, and lca_solver
vector<array<int, 2>> compressed_tree(const lca_solver &ls, const vector<int> &subset){
    auto order = subset;
    const auto &p = ls.pos;
    auto cmp = [&](int u, int v){ return p[u] != p[v] ? p[u] < p[v] : u < v; };
    sort(order.begin(), order.end(), cmp);
    order.erase(unique(order.begin(), order.end()), order.end());
    for(auto i = 1, sz = (int)order.size(); i < sz; ++ i) order.push_back(ls.lca(order[i - 1], order[i]));
    sort(order.begin(), order.end(), cmp), order.erase(unique(order.begin(), order.end()), order.end());
    vector<array<int, 2>> edge;
    for(auto i = 1; i < (int)order.size(); ++ i) edge.push_back({ls.lca(order[i - 1], order[i]), order[i]});
    return edge;
}

vector <int> sieve(int MX){
    vector <int> lpf(MX + 1, 0), vprime;
    ForE(i, 2, MX){
        if (lpf[i] == 0){
            lpf[i] = i;
            vprime.emplace_back(i);
        }
        for (int j = 0; j < isz(vprime) and vprime[j] <= lpf[i] and vprime[j] * i <= MX; j++){
            lpf[vprime[j] * i] = vprime[j];
        }
    }
    return lpf;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    int n; cin >> n;
    vi a(n);
    For(i, 0, n){
        cin >> a[i];
    }
    graph <int> g(n);
    For(i, 0, n - 1){
        int u, v; cin >> u >> v; u--; v--;
        g.link(u, v);
    }

    lca_solver ls(g, {0});
    vi lpf = sieve(200'000);
    vvi subset(200'000 + 1);
    For(i, 0, n){
        while (a[i] != 1){
            int p = lpf[a[i]];
            while (lpf[a[i]] == p){
                a[i] /= p;
            }
            subset[p].emplace_back(i);
        }
    }
    modular ans = 0;
    For(p, 0, isz(subset)){
        if (isz(subset[p]) < 3){
            continue;
        }
        vector<array<int, 2>> vedges = compressed_tree(ls, subset[p]);
        vi vertex;
        Fora(&elem, vedges){
            vertex.emplace_back(elem[0]); vertex.emplace_back(elem[1]);
        }
        sort(bend(vertex)); vertex.erase(unique(bend(vertex)), vertex.end());
        int m = isz(vertex), k = isz(subset[p]);
        vector <vpii> adj(m);
        Fora(&elem, vedges){
            int w = ls.steps(elem[0], elem[1]);
            elem[0] = lower_bound(bend(vertex), elem[0]) - vertex.begin();
            elem[1] = lower_bound(bend(vertex), elem[1]) - vertex.begin();
            adj[elem[0]].emplace_back(elem[1], w);
            adj[elem[1]].emplace_back(elem[0], w);
        }
        vi sz(m, 0);
        Fora(u, subset[p]){
            sz[lower_bound(bend(vertex), u) - vertex.begin()] = 1;
        }
        modular tans = 0;
        auto dfs = [&](auto self, int u, int p)->void{
            Fora(&edge, adj[u]){
                int v, w; tie(v, w) = edge;
                if (v == p){
                    continue;
                }
                self(self, v, u);
                int sz1 = sz[v], sz2 = k - sz[v];
                tans += (modular)((ll)sz1 * (sz1 - 1) / 2 * sz2 + (ll)sz2 * (sz2 - 1) / 2 * sz1) * w;
                sz[u] += sz[v];
            }
        };
        dfs(dfs, 0, 0);
        ans += tans;
    }
    cout << ans << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/