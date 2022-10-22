#pragma GCC optimize("Ofast")

#include <cassert>
#include <list>
#include <vector>

// Base class of flow algorithms.
template <class cap_t, class cost_t>
struct flow_base
{
    class adj_type;

    class edge_t
    {
        friend class adj_type;
        edge_t *link;
    public:
        size_t src, dst;
        cap_t cap; cost_t cost;
        edge_t *rev;
        edge_t() : link() {}
        edge_t(edge_t *link, size_t src, size_t dst, cap_t cap, cost_t cost, edge_t *rev)
            : link(link), src(src), dst(dst), cap(cap), cost(cost), rev(rev) {}
        bool avbl() const { return cap > static_cast<cap_t>(0); }
    }; // class edge_t

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
    }; // class adj_type

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
                    edge_t *ptr = adjs[e.src].emplace(e.src, e.dst, e.cap, e.cost, nullptr);
                    ptr->rev = adjs[e.dst].emplace(e.dst, e.src, e.rev->cap, -e.cost, ptr);
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
        edge_t *ptr = adjs[src].emplace(src, dst, cap, cost, nullptr);
        ptr->rev = adjs[dst].emplace(dst, src, 0, -cost, ptr);
    }
}; // struct flow_base

#include <queue>

// Successive shortest paths algorithm.
// Depends on "base.hpp".
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
        std::vector<cost_t> nptnl(size(), infty);
        /*/ // O((V + E)logV)
        struct node_t
        {
            size_t id; cost_t dist;
            node_t(size_t id, cost_t dist) : id(id), dist(dist) {}
            bool operator<(const node_t &rhs) const { return rhs.dist < dist; }
        };
        std::priority_queue<node_t> que;
        for(size_t src{}; src != size(); ++src)
        {
            if(supp[src] > static_cast<cap_t>(0))
            {
                nptnl[src] = 0;
                for(edge_t &e : adjs[src])
                {
                    if(supp[e.dst] > static_cast<cap_t>(0)) continue;
                    if(e.avbl() && nptnl[e.dst] > e.cost)
                    {
                        que.emplace(e.dst, (nptnl[e.dst] = e.cost) - ptnl[e.dst]);
                        last[e.dst] = &e;
                    }
                }
            }
        }
        while(!que.empty())
        {
            auto [src, ndist] = que.top();
            que.pop();
            if(ndist + ptnl[src] != nptnl[src]) continue;
            for(edge_t &e : adjs[src])
            {
                if(e.avbl() && nptnl[e.dst] > nptnl[src] + e.cost)
                {
                    que.emplace(e.dst, (nptnl[e.dst] = nptnl[src] + e.cost) - ptnl[e.dst]);
                    last[e.dst] = &e;
                }
            }
        }
        /*/ // O(V^2)
        std::vector<bool> used(size());
        for(size_t src{}; src != size(); ++src)
        {
            if(supp[src] > static_cast<cap_t>(0))
            {
                used[src] = true;
                nptnl[src] = 0;
                for(edge_t &e : adjs[src])
                {
                    if(supp[e.dst] > static_cast<cap_t>(0)) continue;
                    if(e.avbl() && nptnl[e.dst] > e.cost)
                    {
                        nptnl[e.dst] = e.cost;
                        last[e.dst] = &e;
                    }
                }
            }
        }
        for(;;)
        {
            size_t src(-1); cost_t sp{infty};
            for(size_t node{}; node != size(); ++node)
            {
                if(used[node] || nptnl[node] == infty) continue;
                cost_t dist{nptnl[node] - ptnl[node]};
                if(sp > dist)
                {
                    sp = dist;
                    src = node;
                }
            }
            if(src == static_cast<size_t>(-1)) break;
            used[src] = true;
            for(edge_t &e : adjs[src])
            {
                if(e.avbl() && nptnl[e.dst] > nptnl[src] + e.cost)
                {
                    nptnl[e.dst] = nptnl[src] + e.cost;
                    last[e.dst] = &e;
                }
            }
        }
        //*/
        ptnl.swap(nptnl);
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
                    if(~block)
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
}; // class min_cost_flow

#include <iostream>
using namespace std;
using i64=long long;

main()
{
    int n,q; cin>>n>>q;
    min_cost_flow<int,int> mcf(107);
    const int dst=mcf.size()-1;
    vector<int> low(n),up(n,n-1);
    for(int t=0; t<q; ++t)
    {
        int l,r,v,typ; cin>>typ>>l>>r>>v;
        l--,v--;
        if(typ==1)
        {
            for(int i=l; i<r; ++i)
            {
                low[i]=max(low[i],v);
            }
        }
        else
        {
            for(int i=l; i<r; ++i)
            {
                up[i]=min(up[i],v);
            }
        }
    }
    for(int i=0; i<n; ++i)
    {
        mcf.supply(i,1);
        mcf.supply(dst,-1);
        for(int j=low[i]; j<=up[i]; j++)
        {
            mcf.add_edge(i,n+j,1,0);
        }
        for(int j=0; j<n; ++j)
        {
            mcf.add_edge(i+n,dst,1,j*2+1);
        }
    }
    if(mcf.flow()) cout << mcf.optimal() << "\n";
    else cout << -1 << "\n";
}