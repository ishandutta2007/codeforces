#include <bits/stdc++.h>

using namespace std;

struct disjoint_sets
{
    vector<size_t> repr, cnt, history;

    disjoint_sets(size_t n) : repr(2*n+2), cnt(n, 1)
    {
        iota(repr.begin(), repr.end(), 0);
        history.reserve(n);
    }

    size_t find(size_t u) const
    {
        return u == repr[u] ? u : find(repr[u]);
    }

    bool unite(size_t u, size_t v)
    {
        if((u = find(u)) == (v = find(v)))
            return false;
        if(cnt[u] > cnt[v])
            swap(u, v);
        history.push_back(u);
        repr[u] = v; cnt[v] += cnt[u];
        return true;
    }

    void rollback()
    {
        auto u = history.back(); history.pop_back();
        cnt[repr[u]] -= cnt[u]; repr[u] = u;
    }
    void rollback_till(size_t k)
    {
        while(history.size() > k)
            rollback();
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t n, q, k;
    cin >> n >> q >> k;

    vector<tuple<size_t, size_t, size_t, size_t>> edges; // what, when
    vector<size_t> day_que, que;

    edges.reserve(q); day_que.reserve(q); que.reserve(q);
    day_que.push_back(0);

    for(size_t i = 0; i <= q; i++) {
        size_t tp;
        if(i < q)
            cin >> tp;
        else
            tp = 3;

        if(tp == 1) {
            size_t u, v;
            cin >> u >> v; u--; v--;
            edges.emplace_back(u, v, que.size(), day_que.size() - 1);
        } else if(tp == 2) {
            size_t u;
            cin >> u; u--;
            que.push_back(u);
        } else if(tp == 3) {
            day_que.push_back(que.size());
        } else assert(false);
    }

    const size_t w = 1 << max(1, (int)__lg(2*que.size() - 1));
    vector<vector<size_t>> tree(2*w);

    auto tree_push = [&](size_t l, size_t r, size_t i) {
        for(l += w, r += w; l < r; l /= 2, r /= 2) {
            if(l % 2) tree[l++].push_back(i);
            if(r % 2) tree[--r].push_back(i);
        }
    };

    for(size_t i = 0; i < edges.size(); i++) {
        const auto j = get<2>(edges[i]), d = get<3>(edges[i]);
        tree_push(j, day_que[min(day_que.size() - 1, d + k)], i);
    }

    vector<size_t> result(que.size()); {
        function<void(size_t, size_t, size_t, disjoint_sets&)>
          process = [&](size_t i, size_t L, size_t R, disjoint_sets& desu) {
            if(que.size() <= L)
                return;

            const auto h = desu.history.size();
            for(auto e : tree[i]) {
                auto [u, v, j, d] = edges[e];
                desu.unite(u, v);
            }

            if(L+1 < R) {
                auto M = L + (R-L)/2;
                process(2*i, L, M, desu);
                process(2*i+1, M, R, desu);
            } else if(L+1 == R and L < que.size()) {
                auto c = desu.cnt[desu.find(que[L])];
                result[L] = c;
            }
            desu.rollback_till(h);
        };
        disjoint_sets temp(n);

        process(1, 0, w, temp);
    };

    for(size_t i = 0; i < que.size(); i++)
        cout << result[i] << '\n';
}