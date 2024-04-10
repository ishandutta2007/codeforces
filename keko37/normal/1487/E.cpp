#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 150005;
const llint INF = 1000000000000000000LL;

int n[4];
vector <int> v[MAXN];
vector <llint> cost[4], dp[4];
multiset <llint> st;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        cin >> n[i];
        cost[i].resize(n[i]);
        dp[i].resize(n[i]);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n[i]; j++) {
            cin >> cost[i][j];
            dp[i][j] = cost[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        st.clear();
        for (auto x : dp[i]) st.insert(x);
        for (int j = 0; j < n[i + 1]; j++) v[j].clear();
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            v[y].push_back(x);
        }
        for (int j = 0; j < n[i + 1]; j++) {
            for (auto sus : v[j]) {
                st.erase(st.find(dp[i][sus]));
            }
            if (!st.empty()) {
                dp[i + 1][j] = *st.begin() + cost[i + 1][j];
            } else {
                dp[i + 1][j] = INF;
            }
            for (auto sus : v[j]) {
                st.insert(dp[i][sus]);
            }
        }
    }
    llint sol = INF;
    for (auto x : dp[3]) sol = min(sol, x);
    if (sol < INF) cout << sol; else cout << -1;
    return 0;
}