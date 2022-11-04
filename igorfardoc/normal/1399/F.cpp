#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second - a.first < b.second - b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ++n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n - 1; i++) {
            cin >> a[i].first >> a[i].second;
        }
        a[n - 1] = {0, 200001};
        sort(a.begin(), a.end(), cmp);
        vector<array<int, 3>> b(n);
        for(int i = 0; i < n; i++) {
            b[i] = {a[i].first, a[i].second, i};
        }
        sort(b.begin(), b.end());
        vi dp(n, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            vector<array<int, 3>> here;
            for(int j = 0; j < n; ++j) {
                if(a[i].first == b[j][0] && a[i].second == b[j][1]) continue;
                if(b[j][0] >= a[i].first && b[j][1] <= a[i].second) {
                    here.push_back(b[j]);
                }
            }
            vi dp1(here.size() + 1, 0);
            for(int i = (int)here.size() - 1; i >= 0; i--) {
                int id1 = lower_bound(here.begin(), here.end(), (array<int, 3>){here[i][1] + 1, here[i][1] + 1, -1}) - here.begin();
                dp1[i] = max(dp1[i + 1], dp[here[i][2]] + dp1[id1]);
            }
            dp[i] += dp1[0];
        }
        cout << dp[n - 1] - 1 << '\n';
    }
}