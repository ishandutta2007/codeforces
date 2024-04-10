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
#include <complex>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int dist(const tuple<int, int>& a, const tuple<int, int>& b) {
    auto [x_a, y_a] = a;
    auto [x_b, y_b] = b;

    return abs(x_a - x_b) + abs(y_a - y_b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);

    int n;
    cin >> n;

    vector<tuple<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = { x, y };
    }

    vector<int> min_dist(n, 1'000'000'000);
    vector<int> min_dist_count(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            
            if (dist(points[i], points[j]) < min_dist[i]) {
                min_dist[i] = dist(points[i], points[j]);
                min_dist_count[i] = 1;
            } else if (dist(points[i], points[j]) == min_dist[i]) {
                min_dist_count[i]++;
            }
        }
    }

    vector<bool> vis(n, false);
    vector<int> groups;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;

        vector<int> nearest_points;
        bool previous_min = false;
        for (int j = 0; j < i; j++) {
            if (dist(points[i], points[j]) == min_dist[i]) {
                previous_min = true;
                break;
            }
        }

        if (previous_min) {
            groups.emplace_back(1);
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (dist(points[i], points[j]) == min_dist[i]) {
                nearest_points.emplace_back(j);
            }
        }

        if (nearest_points.size() > 5) {
            groups.emplace_back(1);
            continue;
        }

        bool smaller_min = false;
        for (int j : nearest_points) {
            if (min_dist[j] < min_dist[i]) {
                smaller_min = true;
                break;
            }
        }

        if (smaller_min) {
            groups.emplace_back(1);
            continue;
        }

        bool unequal_dist = false;
        for (int j0 = 0; j0 < nearest_points.size(); j0++) {
            for (int j1 = j0 + 1; j1 < nearest_points.size(); j1++) {
                if (dist(points[nearest_points[j0]], points[nearest_points[j1]]) != min_dist[i]) {
                    unequal_dist = true;
                }
            }
        }

        if (unequal_dist) {
            groups.emplace_back(1);
            continue;
        }

        bool more_min = false;
        for (int j : nearest_points) {
            if (min_dist_count[j] > nearest_points.size()) {
                more_min = true;
                break;
            }
        }

        if (more_min) {
            groups.emplace_back(1);
            continue;
        }


        for (int j : nearest_points) {
            vis[j] = true;
        }

        groups.emplace_back(nearest_points.size() + 1);
    }

    vector<ll> counts(n + 1, 0);
    counts[0] = 1;

    for (int g : groups) {
        // cout << "G " << g << "\n";
        for (int i = n; i > 0; i--) {
            counts[i] = counts[i - 1];

            if (g > 1 && i >= g) {
                counts[i] = (counts[i] + counts[i - g]) % MOD;
            }
        }

        counts[0] = 0;
    }

    vector<ll> fact(n + 1, 0);
    fact[1] = n;
    for (ll i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * (n - i + 1)) % MOD;
    }

    ll result = 0;
    for (int i = 0; i <= n; i++) {
        result = (result + counts[i] * fact[i]) % MOD;
    }

    cout << result << "\n";
}