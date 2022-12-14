/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>

#include <cstring>
#include <cstdio>
#ifndef ATCODER_DSU_HPP
#define ATCODER_DSU_HPP 1





namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#endif  // ATCODER_DSU_HPP


using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

class TaskC {
public:
    vector<vector<ii>> g;
    vector<vi> up;
    vi d;
    vi tin, tout;
    int T;

	void solve(std::istream& in, std::ostream& out) {
	    int n, m;
	    in >> n >> m;
	    vector<pair<int, ii>> edges(m);
	    set<ii> es;
	    int X = 0;
	    for (int i = 0; i < m; ++i) {
            in >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
            X ^= edges[i].first;
            --edges[i].second.first;
            --edges[i].second.second;
            es.insert(ii(edges[i].second.first, edges[i].second.second));
            es.insert(ii(edges[i].second.second, edges[i].second.first));
            //g[edges[i].second.first].pb(ii(edges[i].second.second, edges[i].first));
            //g[edges[i].second.second].pb(ii(edges[i].second.first, edges[i].first));
        }
	    sort(all(edges));
//	    for (int i = 0; i < n; ++i) {
//	        sort(all(g[i]));
//	    }
	    int64 remaining = n;
	    remaining *= (n - 1);
	    remaining /= 2LL;
	    remaining -= m;
	    assert(remaining >= 0);
	    if (remaining >= n) {
	        atcoder::dsu dsu(n);
	        set<int> alive;
            for (int i = 0; i < n; ++i) {
                alive.insert(i);
            }
	        for (int i = 0; i < n; ++i) {
	            vi cur(all(alive));
	            for (int x : cur) {
	                if (dsu.same(x, i)) continue;
	                if (es.count(ii(x, i))) continue;
	                alive.erase(dsu.leader(x));
                    alive.erase(dsu.leader(i));
	                dsu.merge(x, i);
                    alive.insert(dsu.leader(x));
	            }
	        }
	        int64 res = 0;
	        for (auto e : edges) {
	            int x = e.second.first;
	            int y = e.second.second;
	            if (dsu.same(x, y)) continue;
	            res += e.first;
	            dsu.merge(x, y);
	        }
	        out << res << "\n";
	        return;
	    }
	    assert(n <= 1000);
	    for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!es.count(ii(i, j)))
                    edges.emplace_back(0, ii(i, j));
            }
        }
	    sort(all(edges));
        int64 base = 0;
        atcoder::dsu dsu(n);
        g = vector<vector<ii>>(n);
        vi in_tree(sz(edges), 0);
        for (int i = 0; i < sz(edges); ++i) {
            auto e = edges[i];
            int x = e.second.first;
            int y = e.second.second;
            if (dsu.same(x, y)) continue;
            g[x].pb(ii(e.first, y));
            g[y].pb(ii(e.first, x));
            base += e.first;
            dsu.merge(x, y);
            in_tree[i] = 1;
        }
        int64 res = base + X;

        up = vector<vi>(21, vi(n, -1));
        tin = vi(n, 0);
        tout = vi(n, 0);
        d = vi(n, 0);
        T = 0;
        dfs(0, -1, 0);
        for (int i = 1; i < sz(up); ++i) {
            for (int j = 0; j < n; ++j) {
                int x = up[i - 1][j];
                if (x != -1) {
                    x = up[i - 1][x];
                }
                up[i][j] = x;
            }
        }
        int64 best = (int64)(1e12);
        for (int I = 0; I < sz(edges); ++I) {
            auto e = edges[I];
            //if (e.first == 0) continue;
            if (in_tree[I]) continue;
            if (e.first >= best) continue;
            int x = e.second.first;
            int y = e.second.second;
            int r = x;
            for (int i = sz(up) - 1; i >= 0; --i) {
                int t = up[i][r];
                if (t == -1) continue;
                if (!parent(t, y))
                    r = t;
            }
            if (!parent(r, y))
                r = up[0][r];
            assert(parent(r, x));
            assert(parent(r, y));
            int s = (d[x] - d[r]) + (d[y] - d[r]);
            if (s > 0) {
                best = min<int64>(best, e.first);
            }
        }
        res = min(res, base + best);

        out << res << "\n";
	}

	void dfs(int x, int p, int s) {
	    up[0][x] = p;
	    ++T;
	    tin[x] = T;
	    d[x] = s;
	    for (ii e : g[x]) if (e.second != p) {
	        dfs(e.second, x, s + (e.first == 0 ? 1 : 0));
	    }
	    tout[x] = T;
	}

	bool parent(int x, int y) {
	    return tin[y] >= tin[x] && tin[y] <= tout[x];
	}
};


int main() {
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}