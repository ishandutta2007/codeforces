#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> adj[300000];
bool vis[300000];
bool instk[300000];
vector<int> stk;
int np;
pair<int, int> ps[150000];
int maxgoodj[300000];
long long sumgoodj[300001];

void dfs(int u, int p = -1) {
    // printf("push %d\n", u);
    vis[u] = true;
    instk[u] = true;
    stk.push_back(u);
    for (int c : adj[u]) {
        if (c != p) {
            if (!vis[c]) {
                dfs(c, u);
            } else if (instk[c]) {
                // a cycle
                int mini = c, maxi = c;
                for (int i = stk.size() - 1; stk[i] != c; i--) {
                    mini = min(mini, stk[i]);
                    maxi = max(maxi, stk[i]);
                }
                ps[np++] = make_pair(mini, maxi + 1);
                // fprintf(stderr, "%d %d\n", mini, maxi + 1);
            }
        }
    }
    // printf("pop %d\n", stk.back());
    stk.pop_back();
    instk[u] = false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);

    fill_n(maxgoodj, n, n);
    for (int i = 0; i < np; i++)
        maxgoodj[ps[i].first] = min(maxgoodj[ps[i].first], ps[i].second - 1);
    for (int i = n - 2; i >= 0; i--)
        maxgoodj[i] = min(maxgoodj[i], maxgoodj[i + 1]);
    for (int i = 0; i < n; i++)
        sumgoodj[i + 1] = sumgoodj[i] + maxgoodj[i];

    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        int lb = lower_bound(maxgoodj + l, maxgoodj + r, r) - maxgoodj;
        long long ans = 0;
        ans += sumgoodj[lb] - sumgoodj[l];
        ans += 1LL * r * (r - lb);
        ans -= 1LL * (r - 1 + l) * (r - l) / 2;
        printf("%lld\n", ans);
    }
}