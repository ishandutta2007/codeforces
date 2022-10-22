#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> nums(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < n; j++) {
                nums[i][j] = s[j] - '0';
            }
        }
        int ans = 0;
        set<pair<int, int>> s2;
        for(int i = 0; i <= n/2; i++) {
            for(int j = 0; j <= n/2; j++) {
                set<pair<int, int>> s;
                s.insert({i, j});
                s.insert({n-i-1, n-j-1});
                s.insert({j, n-i-1});
                s.insert({n-j-1, i});
                int x = 0;
                bool ok = true;
                for(auto p : s) {
                    x += nums[p.first][p.second];
                    if(s2.count(p)) ok = false;
                    s2.insert(p);
                }
                if(ok) ans += min((int)s.size() - x, x);
            }
        }
        s2.clear();
        cout << ans << '\n';
    }
}