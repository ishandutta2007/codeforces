#include <bits/stdc++.h>

using namespace std;

const long long mod = 982452203;
#define pb push_back

class Query {
public:
    int l, r, x;
    bool operator < (Query q) const {
        return l < q.l;
    }
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n, q;
    cin >> n >> q;

    Query query[q];

    for(int i = 0; i < q; ++i) {
        cin >> query[i].l >> query[i].r >> query[i].x;
    }

    sort(query, query + q);

    vector<int> start[n + 1], end[n + 1];

    for(int i = 0; i < q; ++i) {
        start[query[i].l].pb(query[i].x);
        if(query[i].r < n)
            end[query[i].r + 1].pb(query[i].x);
    }

    long long dp[n + 1];
    dp[0] = 1L;
    for(int i = 1; i <= n; ++i)
        dp[i] = 0L;

    int vis[n + 1];

    for(int i = 1; i <= n; ++i) {
        for(int j : start[i]) {
            for(int k = n; k >= j; k--)
                dp[k] = (dp[k] + dp[k - j]) % mod;
        }
        for(int j : end[i]) {
            for(int k = 0; k <= n - j; ++k) 
                dp[k + j] = (dp[k + j] - dp[k] + mod) % mod;
        }
        for(int j = 1; j <= n; ++j) {
            if(dp[j] > 0)
                vis[j] = 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(vis[i] == 1)
            ans++;
    }

    cout << ans << "\n";
    for(int i = 1; i <= n; ++i) {
        if(vis[i] == 1)
            cout << i << " ";
    }

    return 0;
}