#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first < b.first) {
        return true;
    }
    if(a.first > b.first) {
        return false;
    }
    return a.second > b.second;
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        int x, s;
        cin >> x >> s;
        a[i] = {x - s, x + s};
        a[i].second = min(a[i].second, m);
    }
    sort(a.begin(), a.end(), cmp);
    vector<pair<int, int>> b;
    int maxr = -1;
    for(int i = 0; i < n; i++) {
        if(maxr >= a[i].second) {
            continue;
        }
        maxr = a[i].second;
        b.push_back(a[i]);
    }
    a = b;
    n = b.size();
    /*for(const auto& el : a) {
        cout << el.first << ' ' << el.second << endl;
    }*/
    //cout << n << endl;
    vvi dp(n, vi(m + 2));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 1; j <= m + 1; j++) {
            if(j == m + 1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = max(m - a[i].second, a[i].first - j);
            if(i == n - 1) {
                if(m <= a[i].second && j >= a[i].first) {
                    dp[i][j] = 0;
                }
                continue;
            }
            dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            if(j > a[i].second) {
                continue;
            }
            if(j >= a[i].first) {
                dp[i][j] = min(dp[i][j], dp[i + 1][a[i].second + 1]);
            } else {
                int d = a[i].first - j;
                dp[i][j] = min(dp[i][j], d + dp[i + 1][min(d + 1 + a[i].second, m + 1)]);
            }
        }
    }
    cout << dp[0][1];

}