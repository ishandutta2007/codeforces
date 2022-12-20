#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int len[N];
int p[N][26], t[N], top;
multiset <int> s[N];

int uni(int a, int b) {
    if (s[b].size() > s[a].size())
        swap(a, b);
    for (multiset<int> ::iterator it = s[b].begin(); it != s[b].end(); ++it)
        s[a].insert(*it);
    return a;
}

int main() {
    int a1, b1, i, j, n, k;
    string s1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 0;
    for (i = 0; i < n; ++i) {
        int u = 0;
        cin >> s1;
        for (j = 0; j < s1.size(); ++j) {
            if (p[u][s1[j] - 'a'] == 0) {
                ++top;
                len[top] = len[u] + 1;
                p[u][s1[j] - 'a'] = top;
            }
            u = p[u][s1[j] - 'a'];
        }
        t[u] = u;
        s[u].insert(s1.size());
        ans += s1.size();
    }
    for (i = top; i > 0; --i) {
        for (j = 0; j < 26; ++j)
        if (p[i][j] != 0 && t[p[i][j]] != 0)
            t[i] = uni(t[i], t[p[i][j]]);
        if (t[i] != 0 && s[t[i]].find(len[i]) == s[t[i]].end()) {
            multiset <int> :: iterator it = s[t[i]].end();
            --it;
            j = *it;
            ans -= j - len[i];
            s[t[i]].erase(it);
            s[t[i]].insert(len[i]);
        }
    }
    cout << ans;
}