#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, sol;
int dp[MAXN][2];
vector <int> v[MAXN], ch[MAXN];

void dfs (int x, int rod) {
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        ch[x].push_back(sus);
        dfs(sus, x);
    }
}

int calc (int x, bool flg) {
    if (dp[x][flg] != -1) return dp[x][flg];
    int res = 0;
    if (flg == 0) {
        res = max(res, (int) ch[x].size());
        int mx = -1, mx2 = -1;
        for (auto sus : ch[x]) {
            int val = max(calc(sus, 0), calc(sus, 1));
            mx2 = max(mx2, val);
            if (mx2 > mx) swap(mx, mx2);
        }
        if (mx != -1) res = max(res, mx + (int) ch[x].size() - 1);
        if (mx2 != -1) sol = max(sol, mx + mx2 + (int) v[x].size() - 2);
        sol = max(sol, mx + (int) v[x].size() - 1);
    } else {
        res = 1;
        int mx = -1, mx2 = -1;
        for (auto sus : ch[x]) {
            int val = calc(sus, 0);
            mx2 = max(mx2, val);
            if (mx2 > mx) swap(mx, mx2);
        }
        if (mx != -1) res = max(res, mx + 1);
        if (mx2 != -1) sol = max(sol, mx + mx2 + 1);
        sol = max(sol, mx + 1);
    }
    return dp[x][flg] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0); calc(1, 0); calc(1, 1);
    cout << sol;
    return 0;
}