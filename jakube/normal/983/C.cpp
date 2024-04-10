#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    vector<vector<vector<vector<int>>>> dp(10, vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(10, std::numeric_limits<int>::max() / 2))));
    dp[0][0][0][0] = 0;
    vector<vector<vector<vector<int>>>> dp2(10, vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(10, std::numeric_limits<int>::max() / 2))));
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 10; a++) {
            for (int b = a; b < 10; b++) {
                for (int c = b; c < 10; c++) {
                    for (int d = c; d < 10; d++) {
                        dp2[a][b][c][d] = std::numeric_limits<int>::max() / 2;
                    }
                }
            }
        }

        int cur = i ? v[i-1].first : 1;
        int next = v[i].first;

        auto f = [&dp2, &v, i](int cost, vector<int> path, vector<int> pass) {
            int mi = *min_element(path.begin(), path.end());
            int ma = *max_element(path.begin(), path.end());
            vector<int> after;
            for (int p : pass) {
                if (p < mi || p > ma) {
                    after.push_back(p);
                }
            }
            after.push_back(v[i].second);
            for (int i = 1; i < (int)path.size(); i++) {
                cost += abs(path[i] - path[i-1]);
            }
            if (after.size() > 4)
                return;
            while (after.size() < 4)
                after.push_back(0);
            sort(after.begin(), after.end());
            int& tmp = dp2[after[0]][after[1]][after[2]][after[3]];
            tmp = min(tmp, cost);
        };

        for (int a = 0; a < 10; a++) {
            for (int b = a; b < 10; b++) {
                for (int c = b; c < 10; c++) {
                    for (int d = c; d < 10; d++) {
                        int cost = dp[a][b][c][d];
                        if (cost == std::numeric_limits<int>::max() / 2)
                            continue;

                        vector<int> pass;
                        if (a)
                            pass.push_back(a);
                        if (b)
                            pass.push_back(b);
                        if (c)
                            pass.push_back(c);
                        if (d)
                            pass.push_back(d);

                        // go directly
                        f(cost, {cur, next}, pass);
                        
                        // one detour
                        for (int x : pass) {
                            f(cost, {cur, x, next}, pass);
                        }

                        // two detours
                        for (int x : pass) {
                            for (int y : pass) {
                                f(cost, {cur, x, y, next}, pass);
                            }
                        }
                    }
                }
            }
        }

        dp.swap(dp2);
    }

    int best = std::numeric_limits<int>::max() / 2;
    int cur = v.back().first;
    for (int a = 0; a < 10; a++) {
        for (int b = a; b < 10; b++) {
            for (int c = b; c < 10; c++) {
                for (int d = c; d < 10; d++) {
                    vector<int> pass;
                    if (a)
                        pass.push_back(a);
                    if (b)
                        pass.push_back(b);
                    if (c)
                        pass.push_back(c);
                    if (d)
                        pass.push_back(d);

                    if (pass.empty())
                        continue;

                    int mi = *min_element(pass.begin(), pass.end());
                    int ma = *max_element(pass.begin(), pass.end());

                    int cost = dp[a][b][c][d];
                    best = min(best, cost + abs(cur - mi) + abs(mi - ma));
                    best = min(best, cost + abs(cur - ma) + abs(mi - ma));
                }
            }
        }
    }
    cout << best + 2*n << '\n';
    
}