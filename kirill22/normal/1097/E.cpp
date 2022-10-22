#include<bits/stdc++.h>

using namespace std;

vector<int> up(vector<int> a) {
    int n = (int) a.size();
    vector<int> dp(n + 1, (int) 1e9), mx(n);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        mx[i] = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[mx[i]] = a[i];
    }
    vector<int> res;
    int i = *max_element(mx.begin(), mx.end()), f = (int) 1e9;
    for (int j = n - 1; j >= 0; j--) {
        if (mx[j] == i && a[j] < f) {
            res.push_back(j);
            f = a[j], i--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> life(n);
        for (int i = 0; i < n; i++) {
            cin >> life[i];
        }
        vector<vector<int>> ans;
        int answer = 1;
        while ((answer + 1) * (answer + 2) / 2 <= n) {
            answer++;
        }
        while ((int) life.size()) {
            auto res = up(life);
            if ((int) res.size() >= answer + 1) {
                answer--;
                ans.push_back({});
                vector<int> ban((int) life.size());
                for (auto i : res) {
                    ban[i] = 1;
                    ans.back().push_back(life[i]);
                }
                vector<int> nlife;
                for (int i = 0; i < (int) life.size(); i++) {
                    if (!ban[i]) {
                        nlife.push_back(life[i]);
                    }
                }
                life = nlife;
            } else {
                vector<vector<int>> ans2(answer);
                for (auto x : life) {
                    int l = -1, r = (int) ans2.size();
                    while (l + 1 < r) {
                        int m = (l + r) / 2;
                        if ((int) ans2[m].size() == 0 || ans2[m].back() > x) {
                            r = m;
                        } else {
                            l = m;
                        }
                    }
                    ans2[r].push_back(x);
                } 
                for (auto res : ans2) {
                    if ((int) res.size()) {
                        ans.push_back(res);
                    }
                }
                break;
            }
        }
        cout << (int) ans.size() << '\n';
        for (auto res : ans) {
            cout << (int) res.size() << " ";
            for (auto x : res) {
                cout << x << " ";
            }
            cout << '\n';
        }
    }
}