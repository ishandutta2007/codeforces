#include<bits/stdc++.h>
#define inf 1000000000
#define log 20
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    }
    return res;
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
    vvi g(n);
    vvi gr(n);
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        gr[u].push_back(v);
    }
    vvi dp(log, vi(n, inf));
    queue<int> q;
    q.push(0);
    dp[0][0] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : g[v]) {
            if(dp[0][u] == inf) {
                dp[0][u] = dp[0][v] + 1;
                q.push(u);
            }
        }
    }
    for(int i = 1; i < log; i++) {
        vvi* g1;
        vvi* g2;
        if(i % 2 == 1) {
            g1 = &gr;
            g2 = &g;
        } else {
            g1 = &g;
            g2 = &gr;
        }
        //cout << 1 << endl;
        for(int v = 0; v < n; v++) {
            dp[i][v] = dp[i - 1][v];
        }
        set<pair<int, int>> s;
        for(int v = 0; v < n; v++) {
            if(dp[i][v] != inf) {
                s.insert({dp[i][v], v});
            }
        }
        while(!s.empty()) {
            auto it = s.begin();
            int v = it->second;
            int d = it->first;
            s.erase(it);
            for(int u : (*g1)[v]) {
                int dnew = d + 1;
                if(dnew < dp[i][u]) {
                    auto it = s.find({dp[i][u], u});
                    if(it != s.end()) {
                        s.erase(it);
                    }
                    dp[i][u] = dnew;
                    s.insert({dp[i][u], u});
                }
            }
        }
        //cout << 2 << endl;
    }
    //cout << 1234 << endl;
    int ans = inf;
    for(int i = 0; i < log; i++) {
        int adding = 0;
        if(i > 0) {
            adding = (1 << i) - 1;
        }
        if(dp[i][n - 1] != inf) {
            ans = min(ans, adding + dp[i][n - 1]);
        }
    }
    //cout << dp[1][1] << endl;
    if(ans != inf) {
        cout << ans;
        return 0;
    }

    vector<pair<int, int>> dst(n * 2, {inf, inf});
    vector<vector<array<int, 3>>> g1(2 * n);
    dst[0] = {0, 0};
    set<array<int, 3>> s;
    s.insert({0, 0, 0});
    for(int v = 0; v < n; v++) {
        for(int u : g[v]) {
            g1[v].push_back({u, 0, 1});
        }
        for(int u : gr[v]) {
            g1[v + n].push_back({u + n, 0, 1});
        }
        g1[v].push_back({v + n, 1, 0});
        g1[v + n].push_back({v, 1, 0});
    }
    while(!s.empty()) {
        auto it = s.begin();
        int v = (*it)[2];
        int d1 = (*it)[0];
        int d2 = (*it)[1];
        s.erase(it);
        for(auto& u1 : g1[v]) {
            int u = u1[0];
            pair<int, int> dnew;
            dnew.first = d1 + u1[1];
            dnew.second = d2 + u1[2];
            if(dnew < dst[u]) {
                auto it = s.find({dst[u].first, dst[u].second, u});
                if(it != s.end()) {
                    s.erase(it);
                }
                dst[u] = dnew;
                s.insert({dst[u].first, dst[u].second, u});
            }
        }
    }
    pair<int, int> mn = min(dst[n - 1], dst[2 * n - 1]);
    ans = (bin_pow(2, mn.first) - 1 + mn.second) % mod;
    cout << ans;

}