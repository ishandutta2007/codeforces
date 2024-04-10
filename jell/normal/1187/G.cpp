#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i64=int_least64_t;

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

#include <cassert>
#include <list>
#include <vector>


// Base class of flow algorithms
template <class cap_t, class cost_t>
struct flow_base
{
    class adj_type;

    class edge_t
    {
        friend flow_base;
        friend class adj_type;
        edge_t *link;
        friend void advance(edge_t* &ptr) { ptr = ptr->link; }
    public:
        size_t src, dst;
        cap_t cap; cost_t cost;
        edge_t *rev;
        edge_t() : link() {}
        edge_t(edge_t *link, size_t src, size_t dst, cap_t cap, cost_t cost, edge_t *rev)
            : link(link), src(src), dst(dst), cap(cap), cost(cost), rev(rev) {}
    }; // struct edge_t

    class adj_type
    {
        friend flow_base;
        edge_t *_head, *_next, *_last;
        size_t _len;

        template <class ...Args>
        edge_t *emplace(Args&&... args)
        {
            if(_next == _last)
            {
                _len <<= 1;
                _next = new edge_t[_len];
                _last = _next + _len;
            }
            *_next = edge_t(_head, args...);
            _head = _next;
            ++_next;
            return _head;
        }

    public:
        adj_type() : _head(), _next(new edge_t[1]), _last(_next + 1), _len(1) {}
        ~adj_type()
        {
            --_last, --_len;
            for(edge_t *_p; _len; _last = _p, _len >>= 1)
            {
                _last -= _len;
                _p = _last->link;
                delete[] _last;
            }
        }

        class iterator
        {
            edge_t *ptr;
        public:
            iterator(edge_t *ptr = nullptr) : ptr(ptr) {}
            iterator operator++() { ptr = ptr->link; return *this; }
            bool operator!=(const iterator &other) const { return ptr != other.ptr; }
            edge_t &operator*() const { return *ptr; }
        };

        iterator begin() const { return iterator(_head); }
        iterator end() const { return iterator(); }
    };

protected:
    std::vector<adj_type> adjs;

public:
    flow_base(size_t _n = 0) : adjs(_n) {}

    flow_base(const flow_base& other) : adjs(other.size())
    {
        for(size_t node{}; node != size(); ++node)
        {
            for(const edge_t &e : other[node])
            {
                if(e.src == node)
                {
                    edge_t *ref = adjs[e.src].emplace(e.src, e.dst, e.cap, e.cost);
                    edge_t *rref = adjs[e.dst].emplace(e.dst, e.src, e.rev->cap, -e.cost);
                    ref->rev = rref;
                    rref->rev = ref;
                    e.rev->src = -1;
                }
                else
                {
                    e.rev->rev->src = node;
                }
            }
        }
    }

    flow_base &operator=(const flow_base &other)
    {
        if(this != &other)
        {
            flow_base cop(other);
            std::swap(adjs, cop.adjs);
        }
        return *this;
    }

    size_t size() const { return adjs.size(); }

    typename decltype(adjs)::reference operator[](size_t node) { assert(node < size()); return adjs[node]; }
    typename decltype(adjs)::const_reference operator[](size_t node) const { assert(node < size()); return adjs[node]; }

    void add_edge(size_t src, size_t dst, cap_t cap, cost_t cost)
    {
        assert(src < size()); assert(dst < size());
        if(!(cap > 0)) return;
        edge_t *ref = adjs[src].emplace(src, dst, cap, cost, nullptr);
        ref->rev = adjs[dst].emplace(dst, src, 0, -cost, ref);
    }
}; // struct flow_base

template <class cap_t, class cost_t>
class min_cost_flow : public flow_base<cap_t, cost_t>
{
    using base = flow_base<cap_t, cost_t>;
    using edge_t = typename base::edge_t;
    using base::adjs;

    cost_t min_cost, total_cost;
    std::vector<cap_t> supp;
    std::vector<cost_t> ptnl;

    void copy_member(const min_cost_flow &other)
    {
        min_cost = other.min_cost;
        total_cost = other.total_cost;
        supp = other.supp;
        ptnl = other.ptnl;
    }

    void Dijkstra(std::vector<edge_t*> &last)
    {
        const cost_t infty(total_cost + 1);
        std::vector<cost_t> dist(size(), infty);
        /*/ // O((V + E)logV)
        std::priority_queue<std::pair<cost_t, size_t>> que;
        for(size_t node{}; node != size(); ++node)
        {
            if(supp[node] > static_cast<cap_t>(0))
            {
                dist[node] = 0;
                que.emplace(0, node);
            }
        }
        while(!que.empty())
        {
            auto [nsp, node] = que.top();
            que.pop();
            if(-nsp != dist[node]) continue;
            ptnl[node] -= nsp;
            if(ptnl[node] > infty) ptnl[node] = infty;
            dist[node] = -1;
            for(edge_t &e : adjs[node])
            {
                if(dist[e.dst] == static_cast<cost_t>(-1) || e.cap == static_cast<cap_t>(0)) continue;
                if(dist[e.dst] + ptnl[e.dst] > ptnl[node] + e.cost)
                {
                    dist[e.dst] = ptnl[node] + e.cost - ptnl[e.dst];
                    last[e.dst] = &e;
                    que.emplace(-dist[e.dst], e.dst);
                }
            }
        }
        /*/ // O(V^2)
        size_t src(-1);
        for(size_t node{}; node != size(); ++node)
        {
            if(supp[node] > static_cast<cap_t>(0))
            {
                dist[node] = 0;
                src = node;
            }
        }
        while(src != static_cast<size_t>(-1))
        {
            ptnl[src] += dist[src];
            dist[src] = -1;
            for(edge_t &e : adjs[src])
            {
                if(dist[e.dst] == static_cast<cost_t>(-1) || e.cap == static_cast<cap_t>(0)) continue;
                if(dist[e.dst] + ptnl[e.dst] > ptnl[src] + e.cost)
                {
                    dist[e.dst] = ptnl[src] + e.cost - ptnl[e.dst];
                    last[e.dst] = &e;
                }
            }
            src = -1;
            cost_t nsp{infty};
            for(size_t node{}; node != size(); ++node)
            {
                if(dist[node] == static_cast<cost_t>(-1)) continue;
                if(nsp > dist[node])
                {
                    nsp = dist[node];
                    src = node;
                }
            }
        }
        //*/
    }

public:
    using base::size;

    min_cost_flow(size_t _n = 0) : base::flow_base(_n), min_cost(0), total_cost(0), supp(_n), ptnl(_n)  {}

    min_cost_flow(const min_cost_flow &other) : base::flow_base(other)
    {
        copy_member(other);
    }

    min_cost_flow &operator=(const min_cost_flow &other)
    {
        base::operator=(other);
        copy_member(other);
        return *this;
    }

    void add_edge(size_t src, size_t dst, cap_t cap, cost_t cost)
    {
        assert(src != dst);
        if(cost < static_cast<cost_t>(0))
        {
            supp[src] -= cap;
            supp[dst] += cap;
            min_cost += cap * cost;
            total_cost -= cap * cost;
            base::add_edge(dst, src, cap, -cost);
        }
        else
        {
            total_cost += cap * cost;
            base::add_edge(src, dst, cap, cost);
        }
    }

    void supply(size_t node, cap_t vol) { assert(node < size()); supp[node] += vol; }

    bool flow()
    {
        for(bool aug = true; aug; )
        {
            aug = false;
            std::vector<edge_t*> last(size());
            Dijkstra(last);
            std::vector<bool> shut(size());
            for(size_t dst{}; dst != size(); ++dst)
            {
                if(supp[dst] < static_cast<cap_t>(0) and last[dst])
                {
                    cap_t resid{-supp[dst]};
                    size_t src{dst}, block(-1);
                    while(last[src] && !shut[src])
                    {
                        if(resid >= last[src]->cap) resid = last[block = src]->cap;
                        src = last[src]->src;
                    }
                    if(shut[src]) block = src;
                    else
                    {
                        if(resid >= supp[src])
                        {
                            resid = supp[src];
                            block = src;
                        }
                        for(edge_t *e{last[dst]}; e; e = last[e->src])
                        {
                            e->cap -= resid;
                            e->rev->cap += resid;
                        }
                        supp[src] -= resid;
                        supp[dst] += resid;
                        min_cost += ptnl[dst] * resid;
                        aug = true;
                    }
                    if(block != size_t(-1))
                    {
                        for(size_t node{dst}; node != block; node = last[node]->src) shut[node] = true;
                        shut[block] = true;
                    }
                }
            }
        }
        for(cap_t s : supp) if(s > static_cast<cap_t>(0)) return false;
        return true;
    }

    cost_t optimal() { assert(flow()); return min_cost; }
};

main()
{
    min_cost_flow<int,i64> mcf(6100);
    int n,m,k,c,d; cin>>n>>m>>k>>c>>d;
    const int tlim=105;
    for(int i=0; i<k; ++i)
    {
        int j; cin>>j; j--;
        mcf.supply(j,1);
    }
    for(int i=0; i<m; ++i)
    {
        int u,v; cin>>u>>v; --u,--v;
        for(int t=0; t<tlim; ++t)
        {
            int nu=u+n;
            int nv=v+n;
            for(int x=0; x<k; ++x)
            {
                mcf.add_edge(u,nv,1,c+d*(x*2+1));
                mcf.add_edge(v,nu,1,c+d*(x*2+1));
            }
            u=nu;
            v=nv;
        }
    }
    for(int i=1; i<n; ++i)
    {
        for(int t=0; t<tlim; t++)
        {
            mcf.add_edge(n*t+i,n*(t+1)+i,k,c);
        }
    }
    const int dst=mcf.size()-1;
    mcf.supply(dst,-k);
    for(int t=0; t<=tlim; ++t) mcf.add_edge(t*n,dst,k,0);
    cout << mcf.optimal() << "\n";
}