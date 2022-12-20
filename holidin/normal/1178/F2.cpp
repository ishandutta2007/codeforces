#include <bits/stdc++.h>
//#pragma GCC optimize 03
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 512;
const int mod = 998244353;
int c[1000001];
long long dp[N][N];
int a[N], mn[N], mx[N];
vector <int> v[N];

long long f(int l, int r) {
    if (l > r)
        dp[l][r] = 1;
    if (dp[l][r] == -1) {
        dp[l][r] = 0;
        int num = l, i, j;
        for (i = l; i <= r; ++i)
        if (a[i] < a[num])
            num = i;
        long long l1 = 0, r1 = 0;
        for (i = l; i <= num; ++i)
            l1 = (l1 + f(l, i - 1) * f(i, num - 1)) % mod;
        for (j = num; j <= r; ++j)
            r1 = (r1 + f(num + 1, j) * f(j + 1, r)) % mod;
        dp[l][r] = (l1 * r1) % mod;
    }
    return dp[l][r];
}

bool use[N];


long long solve(int l, int r) {
    int i, j;
    bool ft[512];
    int h[N];
    vector <pair<int, int> > ps;
    for (i = 0; i < 512; ++i)
        ft[i] = use[i];
    for (i = l; i <= r; ++i)
    if (!ft[c[i]]) {
        ft[c[i]] = 1;
        ps.push_back({mn[c[i]], c[i]});
    }
    if (ps.size() == 0)
        return 1;
    sort(ps.begin(), ps.end());
    long long ans = 1;
    int top = 0;
    for (i = 0; i < ps.size(); ++i)
    if (!use[ps[i].se]){
        use[ps[i].se] = 1;
        int u = ps[i].se;
        for (j = 0; j < v[u].size() - 1; ++j)
        if (v[u][j] + 1 != v[u][j + 1])
            ans = (ans * solve(v[u][j] + 1, v[u][j + 1] - 1)) % mod;
        h[++top] = ps[i].se;
    }
    for (i = 1; i <= top; ++i)
        a[i] = h[i];
    for (i = 0; i <= top + 1; ++i)
    for (j = 0; j <= top + 1; ++j)
        dp[i][j] = -1;
    return (ans * f(1, top)) % mod;
}

int main() {
    int i, j, k, n, w, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        mx[i] = 0;
        mn[i] = k + 1;
    }
    for (i = 1; i <= k; ++i) {
        cin >> c[i];
        v[c[i]].push_back(i);
        mx[c[i]] = max(i, mx[c[i]]);
        mn[c[i]] = min(i, mn[c[i]]);
    }
    for (i = 1; i <= n; ++i)
    for (j = mn[i]; j <= mx[i]; ++j)
    if (c[j] < i) {
        cout << 0;
        exit(0);
    }
    cout << solve(1, k);
}