#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        unordered_map<int, int> ct;
        vector<vector<int>> nums(n+1);
        vector<vector<int>> pas;
        vector<int> cnt;
        set<pair<int, int>> bads;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(!ct.count(x)) ct[x] = 1;
            else ct[x]++;
        }
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            bads.insert({x, y});
            bads.insert({y, x});
        }
        for(auto p : ct) {
            nums[p.second].push_back(p.first);
        }
        for(int i = 0; i <= n; i++) {
            if(nums[i].size() > 0) {
                sort(nums[i].rbegin(), nums[i].rend());
                pas.push_back(vector<int>());
                cnt.push_back(nums[i].size());
                pas.back() = nums[i];
            }
        }
        ll ans = -1;
        auto res = [&](int x, int y) {
            return (ll)(x + y) * (ll)(ct[x] + ct[y]);
        };
        auto bad = [&](int x, int y) {
            return bads.count({x, y});
        };
        for(int i = 0; i < pas.size(); i++) {
            int count = cnt[i];
            for(int j = 0; j < pas[i].size() - 1; j++) {
                if(!bad(pas[i][j], pas[i][j+1])) {
                    ans = max(ans, res(pas[i][j], pas[i][j+1]));
                    break;
                }
                for(int k = j+1; k < pas[i].size(); k++) {
                    if(!bad(pas[i][j], pas[i][k])) {
                        ans = max(ans, res(pas[i][j], pas[i][k]));
                        break;
                    }
                }
            }
            for(int h = i+1; h < pas.size(); h++) {
                for(int j = 0; j < pas[i].size(); j++) {
                    if(!bad(pas[i][j], pas[h][0])) {
                        ans = max(ans, res(pas[i][j], pas[h][0]));
                        break;
                    }
                    for(int k = 1; k < pas[h].size(); k++) {
                        if(!bad(pas[i][j], pas[h][k])) {
                            ans = max(ans, res(pas[i][j], pas[h][k]));
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}