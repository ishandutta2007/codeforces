#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tasks;
    cin >> tasks;
    vector<int> pow(tasks);
    for (int i = 0; i < tasks; i++) {
        cin >> pow[i];
    }
    vector<int> proc(tasks);
    for (int i = 0; i < tasks; i++) {
        cin >> proc[i];
    }
    int total_proc = accumulate(proc.begin(), proc.end(), 0);

    map<int, vector<int>> pow_proc_map;
    for (int i = 0; i < tasks; i++)
        pow_proc_map[pow[i]].push_back(proc[i]);
    vector<pair<int, vector<int>>> pow_proc(pow_proc_map.begin(), pow_proc_map.end());
    reverse(pow_proc.begin(), pow_proc.end());
    
    int cnt_powers = pow_proc.size();
    
    auto inf = std::numeric_limits<long long>::max() / 2;
    // dp[handled][one_task][sum_proc]
    vector<vector<vector<long long>>> dp(cnt_powers + 1, vector<vector<long long>>(tasks + 1, vector<long long>(total_proc + 1, inf)));
    dp[0][0][0] = 0;
    for (int i = 0; i < cnt_powers; i++) {
        auto& [power, processors] = pow_proc[i];
        int cnt = processors.size();
        sort(processors.begin(), processors.end());
        reverse(processors.begin(), processors.end());

        int sum = 0;
        // how many assign to new computers?
        for (int neww = 0; neww <= cnt; neww++) {
            if (neww)
                sum += processors[neww-1];
            int old = cnt - neww;
            for (int j = old; j-old+neww <= tasks && j <= tasks; j++) {
                for (int k = 0; k <= total_proc - sum; k++) {
                    auto& x = dp[i+1][j-old+neww][k+sum];
                    auto y = dp[i][j][k] + neww * (long long)power;
                    if (y < x)
                        x = y;
                }
            }
        }
    }

    auto const& last = dp.back();
    long long best = inf;
    for (auto row : last) {
        for (int p = 0; p <= total_proc; p++) {
            if (row[p] != inf) {
                long long val = (row[p] * 1000 + p - 1) / p;
                best = min(best, val);
            }
        }
    }
    cout << best << endl;
}