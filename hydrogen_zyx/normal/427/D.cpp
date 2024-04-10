#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

struct SAM {
    int tot = 1, last = 1;
    struct Node {
        int len, fa;
        int ch[26];
    } node[N];
    char str[N];
    ll f[N];
    vector<int> g[N];

    void build() {
        int l = strlen(str);
        for (int i = 0; i < l; i++) {
            extend(str[i] - 'a');
        }
        for (int i = 2; i <= tot; i++) {
            g[node[i].fa].push_back(i);
        }
        dfs(1);
    }

    void extend(int c) {
        int p = last, np = last = ++tot;
        f[tot] = 1;
        node[np].len = node[p].len + 1;
        for (; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
        if (!p) node[np].fa = 1;
        else {
            int q = node[p].ch[c];
            if (node[q].len == node[p].len + 1) node[np].fa = q;
            else {
                int nq = ++tot;
                node[nq] = node[q], node[nq].len = node[p].len + 1;
                node[q].fa = node[np].fa = nq;
                for (; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
            }
        }
    }


    void dfs(int u) {
        for (auto x: g[u]) {
            dfs(x);
            f[u] += f[x];
        }
    }

} s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s1.str >> s2.str;
    s1.build();
    s2.build();
    int l = strlen(s1.str);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < l; i++) {
        int now1 = 1, now2 = 1;
        for (int j = i; j < l; j++) {
            now1 = s1.node[now1].ch[s1.str[j] - 'a'];
            now2 = s2.node[now2].ch[s1.str[j] - 'a'];
            if (now1 * now2 == 0) break;
            if (s1.f[now1] == 1 && s2.f[now2] == 1) ans = min(ans, j - i + 1);
        }
    }
    if (ans == 0x3f3f3f3f) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}