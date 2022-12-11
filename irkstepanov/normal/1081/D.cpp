#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

vector<int> parent;
vector<int> size;
vector<int> cnt;

struct edge {
    int from, to;
    int cost;
    bool operator<(const edge& other) const {
        return cost < other.cost;
    }
};

int get(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = get(parent[v]);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    size.assign(n, 1);
    cnt.assign(n, 0);

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        --x;
        ++cnt[x];
    }

    vector<edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        edges.pb({u, v, c});
    }

    sort(all(edges));

    int ans;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].from, v = edges[i].to;
        u = get(u), v = get(v);
        if (u == v) {
            continue;
        }
        if (size[u] < size[v]) {
            swap(u, v);
        }
        //cout << "!" << u << " " << v << " " << cnt[u] << " " << cnt[v] << endl;
        if (cnt[u] + cnt[v] == k) {
            ans = edges[i].cost;
            break;
        }

        parent[v] = u;
        size[u] += size[v];
        cnt[u] += cnt[v];
    }

    for (int i = 0; i < k; ++i) {
        cout << ans << " ";
    }
    cout << "\n";
    
}