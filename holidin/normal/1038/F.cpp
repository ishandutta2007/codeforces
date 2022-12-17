#include <bits/stdc++.h>
using namespace std;

struct aho {
    int go[2], link, back;
};

aho suf[1600], pr[41];
string sufs[1600], prs[41];

void add_string(aho m[], string ms[], int &top, string s) {
    int u = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (m[u].go[s[i]] == 0) {
            ++top;
            m[u].go[s[i]] = top;
            ms[top] = ms[u] + s[i];
        }
        u = m[u].go[s[i]];
    }
}

void build_aho(aho m[]) {
    m[0].link = 0;
    vector <int> v = {0};
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < 2; ++j)
        if (m[v[i]].go[j] != 0) {
            if (i == 0)
                m[m[v[i]].go[j]].link = 0;
            else
                m[m[v[i]].go[j]].link = m[m[v[i]].link].go[j];
            v.push_back(m[v[i]].go[j]);
        } else
            m[v[i]].go[j] = m[m[v[i]].link].go[j];
    }
}
int find_string(aho m[], string s) {
    int u = 0;
    for (int i = 0; i < s.size(); ++i)
        u = m[u].go[s[i]];
    return u;
}

string cnt(string s) {
    for (int i = 0; i < s.size(); ++i)
        s[i] += '0';
    return s;
}

long long dp[41][41][1600][2];

int main() {
    int i, j, k, n, top, l;
    string s;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (i = 0; i < s.size(); ++i)
        s[i] -= '0';
    if (s.size() > n) {
        for (i = 0; i < s.size() - n; ++i)
        if (s[i] != s[i + n]) {
            cout << 0;
            return 0;
        }
        cout << 1;
        return 0;
    }
    add_string(pr, prs, j = 0, s);
    build_aho(pr);
    k = 0;
    for (int i = 0; i < s.size(); ++i) {
        string s1 = "";
        for (int j = i; j < s.size(); ++j)
            s1 += s[j];
        add_string(suf, sufs, k, s1);
    }
    build_aho(suf);
    dp[0][0][0][0] = 1;
    for (i = 0; i < n; ++i)
    for (j = 0; j < s.size(); ++j)
    for (l = 0; l <= k; ++l)
    if (l != s.size()) {
        for (int i1 = 0; i1 < 2; ++i1)
            dp[i + 1][pr[j].go[i1]][l][1] += dp[i][j][l][1];
        for (int i1 = 0; i1 < 2; ++i1)
        if (sufs[suf[l].go[i1]].size() <= sufs[l].size())
            dp[i + 1][pr[j].go[i1]][l][1] += dp[i][j][l][0];
        else {
            dp[i + 1][pr[j].go[i1]][suf[l].go[i1]][0] += dp[i][j][l][0];
        }
    }
    long long ans = 1;
    for (i = 0; i < n; ++i)
        ans *= 2;
    for (i = 0; i <= s.size(); ++i)
    for (j = 0; j <= k; ++j) {
        string s1 = prs[i] + sufs[j];
        int u = 0;
        bool flag = true;
        for (l = 0; l < s1.size(); ++l) {
            u = suf[u].go[s1[l]];
            if (u == s.size())
                flag = false;
        }
        if (flag)
            ans -= dp[n][i][j][0] + dp[n][i][j][1];
    }
    cout << ans;
}