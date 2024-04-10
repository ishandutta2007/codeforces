#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n;
int lo[MAXN], hi[MAXN];
llint dp[MAXN][2];
vector <int> v[MAXN];

void calc (int x, int rod) {
    dp[x][0] = dp[x][1] = 0;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        calc(sus, x);
        dp[x][0] += max(dp[sus][0] + abs(lo[x] - lo[sus]), dp[sus][1] + abs(lo[x] - hi[sus]));
        dp[x][1] += max(dp[sus][0] + abs(hi[x] - lo[sus]), dp[sus][1] + abs(hi[x] - hi[sus]));
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> lo[i] >> hi[i];
            v[i].clear();
        }
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        calc(1, 0);
        cout << max(dp[1][0], dp[1][1]) << '\n';
    }
    return 0;
}