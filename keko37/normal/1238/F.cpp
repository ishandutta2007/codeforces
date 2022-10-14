#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int q, n, sol;
vector <int> v[MAXN];
int dp[MAXN];

void calc (int x, int rod) {
    int mx[2], ind[2];
    mx[0] = mx[1] = 0;
    ind[0] = ind[1] = -1;
    int cnt = 0;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        cnt++;
        calc(sus, x);
        if (dp[sus] > mx[1]) {
            mx[1] = dp[sus];
            ind[1] = sus;
        }
        if (mx[1] > mx[0]) {
            swap(mx[0], mx[1]);
            swap(ind[0], ind[1]);
        }
    }
    dp[x] = max(cnt, 1) + mx[0];
    sol = max(sol, mx[0] + (int) v[x].size());
    sol = max(sol, mx[0] + mx[1] + (int) v[x].size() - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        sol = 0;
        for (int i=1; i<=n; i++) v[i].clear();
        for (int i=0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        calc(1, 0);
        cout << sol << '\n';
    }
    return 0;
}