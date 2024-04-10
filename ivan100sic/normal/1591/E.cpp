// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

int n, q;
int a[1000005];
vector<int> e[1000005];

struct upit {
    int l, k, id;
};

int ans[1000005];
vector<upit> u[1000005];

ordered_set<pair<int, int>> os;
int freq[1000005];

void dfs(int x) {
    int& c = a[x];
    os.erase({freq[c], c});
    freq[c]++;
    os.insert({freq[c], c});

    for (auto [l, k, id] : u[x]) {
        auto ord = os.order_of_key({l, -1});
        auto it = os.find_by_order(ord + k - 1);
        if (it != os.end()) {
            ans[id] = it->second;
        }
    }

    for (int y : e[x]) {
        dfs(y);
    }

    os.erase({freq[c], c});
    freq[c]--;
    os.insert({freq[c], c});
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i : ra(1, n+1)) cin >> a[i], e[i] = {}, u[i] = {};
        for (int i : ra(2, n+1)) {
            int p;
            cin >> p;
            e[p].push_back(i);
        }
        
        for (int i : ra(0, q)) {
            int v, l, k;
            cin >> v >> l >> k;
            u[v].push_back({l, k, i});
            ans[i] = -1;
        }

        dfs(1);
        for (int i : ra(0, q)) {
            cout << ans[i] << " \n"[i == q-1];
        }
    }
    
}