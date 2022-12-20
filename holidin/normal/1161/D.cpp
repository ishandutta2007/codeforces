#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N = 1e4 + 1;
const long long mod = 998244353;
int t[N], dp[N];
vector <int> e[N], v[N];
string s;
bool use[N], flag2, flag1;
int st0, st1;

void uni(int a, int b) {
    if (a == b)
        return;
    if (v[a].size() < v[b].size())
        swap(a, b);
    for (int i = 0; i < v[b].size(); ++i) {
        v[a].push_back(v[b][i]);
        t[v[b][i]] = a;
    }
    v[b].clear();
}

bool dfs(int u) {
    if (u == t[st0])
        flag1 = 1;
    if (u == t[st1])
        flag2 = 1;
    use[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (!use[e[u][i]]) {
        dp[e[u][i]] = dp[u] + 1;
        if (dfs(e[u][i]))
            return true;
    } else if ((dp[u] - dp[e[u][i]]) % 2 == 0)
            return true;
    return false;
}

int main() {
    int i, j, k, n, l, r, a, b;
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    for (i = 0; i < n / 2; ++i)
        swap(s[i], s[n - i - 1]);
    long long ans = 0;
    for (i = 1; i < n; ++i) {
        for (j = 1; j <= 2*n + 2; ++j)
            v[j].clear();
        for (j = 1; j <= n; ++j) {
            v[j].clear();
            v[j].push_back(j);
            t[j] = j;
        }
        for (j = 1; j <= i; ++j) {
            v[n + j].clear();
            v[n + j].push_back(n + j);
            t[n + j] = n + j;
        }
        st0 = 2*n + 1;
        t[st0] = st0;
        v[st0] = {st0};
        st1 = 2*n + 2;
        t[st1] = st1;
        v[st1]= {st1};
        for (j = 1; j <= i / 2; ++j)
            uni(t[n + j], t[n + i - j + 1]);
        for (j = 1; j <= n; ++j)
            uni(t[j], t[n - j + 1]);
        vector <pair<int, int> > w;
        for (j = 1; j <= n; ++j)
        if (s[j - 1] != '?')
            if (j <= i)
                if (s[j - 1] == '0')
                    uni(t[j], t[n + j]);
                else
                    w.push_back({j, n + j});
            else if (s[j - 1] == '0')
                    uni(t[j], t[st0]);
                else
                    uni(t[j], t[st1]);
        uni(t[1], t[st1]);
        uni(t[n + 1], t[st1]);
        if (t[st0] == t[st1])
            continue;
        for (j = 1; j <= 2 * n + 2; ++j) {
            e[j].clear();
            use[j] = 0;
        }
        for (j = 0; j < w.size(); ++j) {
            e[t[w[j].fi]].push_back(t[w[j].se]);
            e[t[w[j].se]].push_back(t[w[j].fi]);
        }
        long long ans1 = 1;
        bool flag3 = 0;
        for (j = 1; j <= 2 * n + 2; ++j)
        if (!use[j] && v[j].size() != 0) {
            dp[j] = 0;
            flag1 = 0;
            flag2 = 0;
            if (dfs(j)) {
                ans1 = 0;
            }
            if (flag1 && flag2)
                flag3 = 1;
            if (!flag1 && !flag2)
                ans1 = (ans1 * 2) % mod;
        }
        if (flag3 && abs(dp[t[st0]] - dp[t[st1]]) % 2 == 0)
            ans1 = 0;
        ans = (ans + ans1) % mod;
    }
    cout << ans;
}