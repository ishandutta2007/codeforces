#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n;
int dp[MAXN], best[MAXN];
vector <int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(best, -1, sizeof best);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (v.empty() || v.back() != x) v.push_back(x);
    }
    n = v.size();
    int mx = 0;
    for (int i = n-1; i >= 0; i--) {
        dp[i] = mx;
        if (i != 0) dp[i] = max(dp[i], 1 + best[v[i - 1]]);
        mx = max(mx, dp[i]);
        best[v[i]] = max(best[v[i]], dp[i]);
    }
    cout << n - dp[0];
    return 0;
}