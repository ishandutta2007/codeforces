#include <bits/stdc++.h>
using namespace std;
const int N = 20000;

int dp[N], pr[N];
bool b[256];
string s;

int F(int u) {
    //cout << 'x';
    if (u < 3)
        return 0;
    if (dp[u] < 0) {
        //cout << 'y';
        int j = u - 1;
        bool ras = true;
        int len = 0;
        if (b[s[u - 1]])
            ++len;
        dp[u] = F(u - 1) + 1;
        pr[u] = u - 1;
        for (j = u - 1; j > 0; --j) {
            if (b[s[j - 1]]) {
                ++len;
                if ((ras) && (len != 1) && (s[j - 1] != s[j]))
                    ras = false;
            } else {
                ras = true;
                len = 0;
            }
            if ((ras) || (len < 3)) {
                if (F(j - 1) + 1 < dp[u]) {
                    dp[u] = F(j - 1) + 1;
                    pr[u] = j - 1;
                }
            } else
                break;
        }
        if (j == 0) {
            dp[u] = 0;
            pr[u] = 0;
        }
    }
    return dp[u];
}

int main() {
    int i, j;
    cin >> s;
    for (i = 0; i < 256; ++i)
        b[i] = true;
    for (i = 0; i <= s.size(); ++i)
        dp[i] = -1;
    b['a'] = false;
    b['e'] = false;
    b['o'] = false;
    b['u'] = false;
    b['i'] = false;
    F(s.size());
    vector <int> v;
    i = s.size();
    while (i > 2) {
        v.push_back(pr[i]);
        i = pr[i];
    }
    sort(v.begin(), v.end());
    j = 0;
    //cout << pr[6] << endl;
    while ((j < v.size()) && (v[j] == 0)) ++j;
    for (i = 0; i < s.size(); ++i) {
        if ((j < v.size()) && (v[j] == i)) {
            ++j;
            cout << ' ';
        }
        cout << s[i];
    }
}