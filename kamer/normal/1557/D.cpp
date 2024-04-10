#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> segments;
    vector<vector<int>> graph(n, vector<int>());
    vector<int> counts(n, 0);
    set<int> current_filled;

    for (int _ = 0; _ < m; _++) {
        int i, l, r;
        cin >> i >> l >> r;
        i--;
        segments.emplace_back(l, -1, i);
        segments.emplace_back(r, 1, i);
    }

    sort(segments.begin(), segments.end());

    for (auto [_, flag, i] : segments) {
        // cout << "C " << _ << " " << i << " " << flag << "\n";
        if (flag == -1) {
            counts[i]++;
            if (counts[i] == 1) {
                current_filled.insert(i);
                auto it = current_filled.find(i);

                if (it != current_filled.begin()) {
                    graph[*(--it)].push_back(i);
                    ++it;
                }

                ++it;
                if (it != current_filled.end()) {
                    graph[i].push_back(*it);
                }
            }
        } else {
            counts[i]--;
            if (counts[i] == 0) {
                current_filled.erase(i);
            }
        }
    }

    vector<int> dp(n, 1);
    vector<int> next(n, n);
    int best = 1;
    int bestIndex = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        for (auto j : graph[i]) {
            if (dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                next[i] = j;
            }
            // cout << "G " << i << " " << j << "\n";
        }

        if (dp[i] > best) {
            bestIndex = i;
            best = dp[i];
        }
    }

    cout << n - best << "\n";
    vector<bool> good(n, true);
    
    while (bestIndex < n) {
        good[bestIndex] = false;
        bestIndex = next[bestIndex];
    }

    for (int i = 0; i < n; i++) {
        if (good[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}