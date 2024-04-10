#include <bits/stdc++.h>

#define ld long double
#define ll long long
using namespace std;
template <class T>
void read(T& x) {
    T res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        res = (res << 3) + (res << 1) + c - '0';
        c = getchar();
    }
    x = res * f;
}
const ll N = 500000 + 10;
const int mod = 1e9 + 7;
int t, n, b[N], du[N];
vector<int> a[N], g[N], g2[N], tag[N];
int main() {
    read(t);
    while (t--) {
        read(n);
        b[0] = 0;
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            int k;
            read(k);
            for (int j = 1; j <= k; j++) {
                int x;
                read(x);
                a[i].push_back(x);
                b[++b[0]] = x;
            }
        }
        sort(b + 1, b + 1 + b[0]);
        b[0] = unique(b + 1, b + 1 + b[0]) - (b + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                a[i][j] = lower_bound(b + 1, b + 1 + b[0], a[i][j]) - b;
            }
        }
        for (int i = 1; i <= b[0] + n; i++)
            g[i].clear(), g2[i].clear(), du[i] = 0, tag[i].clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                g[i].push_back(n + a[i][j]);
                g[n + a[i][j]].push_back(i);
                du[i]++, du[n + a[i][j]]++;
            }
        }
        for (int i = 1; i <= n + b[0]; i++) {
            for (auto to : g[i]) {
                if (du[i] < du[to] || (du[i] == du[to] && i < to))
                    g2[i].push_back(to);
            }
        }
        vector<int> ans;
        for (int i = 1; i <= n + b[0]; i++) {
            for (auto to : g[i])
                for (auto w : g2[to]) {
                    if (du[i] < du[w] || (du[i] == du[w] && i < w)) {
                        if (tag[w].size()) {
                            ans = tag[w];
                            ans.push_back(i);
                            ans.push_back(to);
                            ans.push_back(w);
                            goto todo;
                        } else {
                            tag[w].push_back(i);
                            tag[w].push_back(to);
                            tag[w].push_back(w);
                        }
                    }
                }
            for (auto to : g[i])
                for (auto w : g2[to]) {
                    if (du[i] < du[w] || (du[i] == du[w] && i < w))
                        tag[w].clear();
                }
        }
    todo:
        if (!ans.size())
            printf("-1\n");
        else {
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            printf("%d %d\n", ans[0], ans[1]);
        }
    }

    return 0;
}