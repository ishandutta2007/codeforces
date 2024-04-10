#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using Node = vector<P>;

vector<vector<int>> adj;
vector<int> starttime, size, depth;
vector<P> ps;
vector<int> C;

int t = 0;

class SegmentTree
{
public:
    SegmentTree(int count)
    {
        n = count;
        data.resize(2 * n);
    }

    SegmentTree(std::vector<P> const &ps)
    {
        n = ps.size();
        data.resize(2 * n);
        for (int i = 0; i < n; i++) {
            data[i + n].push_back(ps[i]);
        }
        for (int idx = n - 1; idx > 0; idx--) {
            std::merge(data[idx << 1].begin(), data[idx << 1].end(),
                       data[idx << 1 | 1].begin(), data[idx << 1 | 1].end(),
                       std::back_inserter(data[idx]));
            int best = std::numeric_limits<int>::max();
            for (auto &p : data[idx]) {
                best = min(best, p.second);
                p.second = best;
            }
        }
    }

    int minimum(int left, int right, int D)
    {  // interval [left, right)
        int ret = std::numeric_limits<int>::max();
        left += n;
        right += n;
        auto p = make_pair(D, std::numeric_limits<int>::max());

        while (left < right) {
            if (left & 1) {
                auto i = upper_bound(data[left].begin(), data[left].end(), p) -
                         data[left].begin();
                if (i) {
                    ret = min(ret, data[left][i - 1].second);
                }
                left++;
            }
            if (right & 1) {
                right--;
                auto i =
                    upper_bound(data[right].begin(), data[right].end(), p) -
                    data[right].begin();
                if (i) {
                    ret = min(ret, data[right][i - 1].second);
                }
            }
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    int n;
    std::vector<Node> data;
};

void dfs(int v, int p = -1, int d = 0)
{
    starttime[v] = t;
    size[v] = 1;
    depth[v] = d;
    t++;
    ps.push_back({d, C[v]});
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        dfs(u, v, d + 1);
        size[v] += size[u];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int root;
    cin >> root;
    root--;

    C.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    starttime.resize(n);
    size.resize(n);
    depth.resize(n);
    dfs(root);

    SegmentTree segtree(ps);

    int q;
    cin >> q;
    int last = 0;
    while (q-- > 0) {
        int a, b;
        cin >> a >> b;
        int x = (a + last) % n;
        int y = (b + last) % n;
        last =
            segtree.minimum(starttime[x], starttime[x] + size[x], depth[x] + y);
        cout << last << '\n';
    }
}