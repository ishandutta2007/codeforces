#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int LogN = 20;
const long long mod = 998244353;

int t[LogN], c[LogN][N], cnt[LogN];
bool dp[N], m[N], vsp[N];
string s;
vector <int> v[LogN];

bool is(int x, int l, int r) {
    return (c[x][r + 1] - c[x][l] >= 1);
}


int main() {
    int i, j, n, k, b, p, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    cin >> s;
    for (i = 0; i < s.size(); ++i) {
        s[i] -= 'a';
        ++cnt[s[i]];
        for (j = 0; j < p; ++j)
            c[j][i + 1] = c[j][i];
        ++c[s[i]][i + 1];
        v[s[i]].push_back(i);
    }
    t[0] = 1;
    for (i = 1; i <= p; ++i)
        t[i] = t[i - 1] * 2;
    for (i = 0; i < p; ++i)
    for (j = 0; j < p; ++j) {
        cin >> k;
        if (k == 1)
            continue;
        for (h = 0; h < t[p]; ++h)
            vsp[h] = 0;
        int l2 = 0;
        for (int l1 = 0; l1 < v[i].size(); ++l1) {
            while (l2 < v[j].size() && v[j][l2] <= v[i][l1])
                ++l2;
            if (l2 != v[j].size() && !is(i, v[i][l1] + 1, v[j][l2] - 1)) {
                int x = 0;
                for (int l = 0; l < p; ++l)
                if (l != i && l != j && is(l, v[i][l1] + 1, v[j][l2] - 1))
                    x += t[l];
                vsp[x] = true;
            }
        }
        for (h = 0; h < t[p]; ++h)
        if (vsp[h] && (h & t[j]) == 0 && (h & t[i]) == 0) {
            for (int f = 0; f < p; ++f)
                vsp[h | t[f]] = 1;
            m[(((t[p] - 1) ^ h) | (t[i] | t[j]))] = true;
        }
    }
    dp[t[p] - 1] = true;
    int ans = n;
    for (i = t[p] - 2; i >= 0; --i)
    if (!m[i]) {
        for (j = 0; j < p; ++j)
        if ((i & t[j]) == 0)
            dp[i] |= dp[i + t[j]];
        if (dp[i]) {
            int x = 0;
            for (j = 0; j < p; ++j)
            if ((i & t[j]) > 0)
                x += cnt[j];
            ans = min(ans, x);
        }
    }
    cout << ans;
}