#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;

struct edge {
    int from;
    int to;
    int cost;
    int id;
    bool operator<(const edge& other) const {
        if (cost != other.cost) {
            return cost > other.cost;
        }
        return id < other.id;
    }
};

bool comp(const edge& x, const edge& y) {
    return x.id < y.id;
}

class SegmentTree {
public:
    SegmentTree() {}

    SegmentTree(vector<edge> a) {
        edges = a;
        sort(all(edges), comp);
        n = sz(edges);
        t.assign(2 * n, -inf);
    }

    int find(int id) {
        edge e = {-1, -1, -1, id};
        int pos = lower_bound(all(edges), e, comp) - edges.begin();
        return get(pos, n - 1);
    }

    void set(int cost, int id, int val) {
        edge e = {-1, -1, cost, id};
        int pos = lower_bound(all(edges), e, comp) - edges.begin();
        update(pos, val);
    }

private:
    int n;
    vector<int> t;
    vector<edge> edges;

    void update(int pos, int val) {
        pos += n;
        t[pos] = max(t[pos], val);
        for (pos >>= 1; pos; pos >>= 1) {
            t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
        }
    }

    int get(int l, int r) {
        int ans = -inf;
        for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                ans = max(ans, t[l]);
            }
            if (!(r & 1)) {
                ans = max(ans, t[r]);
            }
        }
        return ans;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<SegmentTree> ST(n);

    vector<edge> edges;
    vector<vector<edge> > a(n);

    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        --from, --to;
        a[from].pb({from, to, cost, i});
        edges.pb({from, to, cost, i});
    }

    sort(all(edges));
    for (int i = 0; i < n; ++i) {
        ST[i] = SegmentTree(a[i]);
    }

    int ans = 1;
    for (edge& e : edges) {
        int val = ST[e.to].find(e.id);
        //cout << e.to << " " << val << endl;
        val = max(0, val);
        ++val;
        ST[e.from].set(e.cost, e.id, val);
        ans = max(ans, val);
    }

    cout << ans << "\n";

}