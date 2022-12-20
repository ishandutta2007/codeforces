#include <bits/stdc++.h>
#define fi first
#define se second
#define sqr(a) ((a) * (a))
#define ll long long
#define ld lond double
using namespace std;
const long long N = 5e5 + 1;
const long long inf = 1e18 + 1;

int c[N], p[N], lcp[N], ds[N];
long long dp[N];

int main() {
    string s;
    int i, j, n, k, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    cin >> s;
    s += (char) (127);
    for (i = 0; i < s.size(); ++i)
        c[i] = s[i] - 'a';
    for (int l = 1; l / 2 < s.size(); l *= 2) {
        vector <pair<pair<int, int>, int> > v;
        for (j = 0; j < s.size(); ++j)
            v.push_back({{c[j], c[(j + l) % s.size()]}, j});
        sort(v.begin(), v.end());
        int top = 0;
        for (i = 0; i < s.size(); ++i)  {
            if (i > 0 && v[i].fi != v[i - 1].fi)
                ++top;
            c[v[i].se] = top;
            p[i] = v[i].se;
        }
    }
    for (i = 0; i < s.size() - 1; ++i) {
        lcp[i] = 0;
        while (s[p[i] + lcp[i]] == s[p[i + 1] + lcp[i]])
            ++lcp[i];
    }
    for (i = 1; i < s.size(); ++i) {
        for (j = 0; j < s.size(); ++j)
        if (p[j] == i - 1)
            break;
        ds[i - 1] = 0;
        int x = 1e9;
        for (int l = j; l < s.size() - 1; ++l) {
            x = min(x, lcp[l]);
            if (p[l + 1] < i - 1)
                ds[i - 1] = max(ds[i - 1], min(x, i - p[l + 1] - 1));
        }
        x = 1e9;
        for (int l = j - 1; l >= 0; --l) {
            x = min(x, lcp[l]);
            if (p[l] < i - 1)
                ds[i - 1] = max(ds[i - 1], min(x, i - p[l] - 1));
        }
    }
    for (i = 1; i < s.size(); ++i)
        dp[i] = inf;
    for (i = 0; i < s.size() - 1; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + a);
        for (j = 1; j <= ds[i]; ++j)
            dp[i + j] = min(dp[i + j], dp[i] + b);
    }
    cout << dp[s.size() - 1];
}