#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

ll MOD = 1'000'000'007;

static inline ll comb(ll n, ll k, const vector<ll>& fact, const vector<ll>& inv_fact) {
    if (n < k) return 0;
    return fact[n] * inv_fact[n - k] % MOD * inv_fact[k] % MOD;
}

ll compute_sum(int r,
               int n,
               int k,
               const vector<vector<int>>& graph,
               vector<int>& p,
               const vector<ll>& fact,
               const vector<ll>& inv_fact,
               ll& sum) {
    ll full_subtree_size = 1;
    vector<ll> subtree_sizes;
    for (auto v : graph[r]) {
        if (v == p[r]) {
            continue;
        }

        p[v] = r;
        ll v_subtree_size = compute_sum(v, n, k, graph, p, fact, inv_fact, sum);
        subtree_sizes.emplace_back(v_subtree_size);
        full_subtree_size += v_subtree_size;
    }

    subtree_sizes.emplace_back(n - full_subtree_size);

    ll all_subtree_subsets = 0;
    for (auto subtree_size : subtree_sizes) {
        all_subtree_subsets = (all_subtree_subsets + comb(subtree_size, k, fact, inv_fact)) % MOD;
    }

    for (auto subtree_size : subtree_sizes) {
        sum = ((sum + subtree_size * (n - subtree_size) % MOD * (comb(n - subtree_size, k, fact, inv_fact) - all_subtree_subsets + comb(subtree_size, k, fact, inv_fact))) % MOD + MOD) % MOD;
    }

    sum = ((sum + n * (comb(n, k, fact, inv_fact) - all_subtree_subsets)) % MOD + MOD) % MOD;

    return full_subtree_size;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);

    int n, k;
    cin >> n >> k;

    vector<ll> inv(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        inv[i] = - ((MOD / i) * inv[MOD % i] % MOD) + MOD;
    }

    vector<ll> fact(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<ll> inv_fact(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;
    }

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    vector<int> p(n, 0);
    ll sum = 0;
    compute_sum(0, n, k, graph, p, fact, inv_fact, sum);

    cout << sum << "\n";
}