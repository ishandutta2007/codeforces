#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 4005;

int t, n;
vector <int> v;
int p[MAXN], dp[MAXN][MAXN];

void solve (int len) {
    int mx = 0, ind = -1;
    for (int i = 1; i <= len; i++) {
        if (p[i] > mx) {
            mx = p[i];
            ind = i;
        }
    }
    v.push_back(len + 1 - ind);
    if (ind > 1) solve(ind - 1);
}

bool calc (int pos, int ost) {
    if (pos == v.size()) return (ost == 0);
    if (dp[pos][ost] != -1) return dp[pos][ost];
    bool res = 0;
    res |= calc(pos + 1, ost);
    if (ost >= v[pos]) res |= calc(pos + 1, ost - v[pos]);
    return dp[pos][ost] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2*n; i++) cin >> p[i];
        v.clear();
        solve(2 * n);
        for (int pos = 0; pos < v.size(); pos++) {
            for (int val = 0; val <= n; val++) {
                dp[pos][val] = -1;
            }
        }
        if (calc(0, n)) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}