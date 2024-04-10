#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> v(n);
    for (auto& x : v)
        cin >> x.first >> x.second;
    v.push_back({2e9, 2e9});
    
    vector<int> dists(2*n), costs(2*n);
    for (int i = 0; i < n; i++) {
        auto x = v[i];
        dists[2*i] = x.second - x.first;
        costs[2*i] = 0;
        dists[2*i + 1] = v[i+1].first - x.second;
        costs[2*i + 1] = dists[2*i + 1];
    }

    vector<int> psum_dists(2*n + 1, 0);
    for (auto psum_idx = 0; psum_idx < 2*n; psum_idx++) {
        psum_dists[psum_idx+1] = psum_dists[psum_idx] + dists[psum_idx];
    }
    vector<int> psum_costs(2*n + 1, 0);
    for (auto psum_idx = 0; psum_idx < 2*n; psum_idx++) {
        psum_costs[psum_idx+1] = psum_costs[psum_idx] + costs[psum_idx];
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(psum_costs.begin(), psum_costs.end(), psum_costs[2*i] + h);
        int idx = it - psum_costs.begin();

        int costs_rem = psum_costs[idx-1] - psum_costs[2*i] - h;

        int cur = psum_dists[idx - 1] - psum_dists[2*i] + abs(costs_rem);
        best = max(best, cur);
    }
    cout << best << endl;
}