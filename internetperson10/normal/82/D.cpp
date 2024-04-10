#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int BIG = 1e9 + 7;
int memo[1001][1001];
pair<int, int> goTo[1001][1001], leav[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        for(int j = 0; j < n; j++) {
            memo[i][j] = BIG;
        }
    }
    function<int(int, int)> dp = [&](int i, int x) {
        if(i == n) return nums[x];
        if(i == n-1) return max(nums[i], nums[x]);
        if(memo[i][x] != BIG) return memo[i][x];
        int ans = BIG;
        int v[3];
        v[0] = dp(i+2, i) + max(nums[i+1], nums[x]);
        v[1] = dp(i+2, i+1) + max(nums[i], nums[x]);
        v[2] = dp(i+2, x) + max(nums[i], nums[i+1]);
        for(int j = 0; j < 3; j++) {
            ans = min(ans, v[j]);
        }
        if(ans == v[0]) {
            goTo[i][x] = {i+2, i};
            leav[i][x] = {i+1, x};
        }
        if(ans == v[1]) {
            goTo[i][x] = {i+2, i+1};
            leav[i][x] = {i, x};
        }
        if(ans == v[2]) {
            goTo[i][x] = {i+2, x};
            leav[i][x] = {i, i+1};
        }
        return memo[i][x] = ans;
    };
    cout << dp(1, 0) << '\n';
    int i = 1, x = 0;
    while(i < n-1) {
        cout << 1+leav[i][x].first << ' ' << 1+leav[i][x].second << '\n';
        tie(i, x) = goTo[i][x];
    }
    if(i == n-1) {
        cout << i+1 << ' ' << x+1 << '\n';
    }
    else {
        cout << x+1 << '\n';
    }
}