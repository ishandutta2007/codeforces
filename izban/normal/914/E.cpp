#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int K = 18;
const int N = 1 << K;

int n;
vector<int> e[N];
char s[N];
ll ans[N];
ll up[N];
char alive[N];
int vis[N], tmr;
int cnt[N];

void dfs1(int v) {
    vis[v] = tmr;
    cnt[v] = 1;
    for (int to : e[v]) {
        if (!alive[to] || vis[to] == tmr) continue;
        dfs1(to);
        cnt[v] += cnt[to];
    }
}

//unordered_map<int, int> mp;
int mp[1 << ('t' - 'a' + 1)];

void dfs2(int v, int mask, const function<void(int)> &f) {
    vis[v] = tmr;
    f(mask);
    for (int to : e[v]) {
        if (!alive[to] || vis[to] == tmr) continue;
        dfs2(to, mask ^ (1 << (s[to] - 'a')), f);
    }
}

int need;
int vv;
void dfs3(int v, int mask) {
    vis[v] = tmr;
    up[v] = 0;
    for (int to : e[v]) {
        if (!alive[to] || vis[to] == tmr) continue;
        dfs3(to, mask ^ (1 << (s[to] - 'a')));
        up[v] += up[to];
    }
    int omask = mask ^ need;
    if (__builtin_popcount(omask) <= 1) {
        up[v] += 1;
        ans[vv] += 1;
    }
    /*if (mp.count(mask)) {
        up[v] += mp[mask];
    }*/
    up[v] += mp[mask];
    for (int i = 0; i < 't' - 'a' + 1; i++) {
        int nmask = mask ^ (1 << i);
        //if (mp.count(nmask)) {
        up[v] += mp[nmask];
        //}
    }
    ans[v] += 2 * up[v];
}

void solve(int v) {
    tmr++;
    dfs1(v);
    int all = cnt[v], prev = -1;
    while (1) {
        int f = 0;
        for (int to : e[v]) {
            if (!alive[to] || to == prev) continue;
            if (cnt[to] * 2 >= all) {
                prev = v;
                v = to;
                f = 1;
                break;
            }
        }
        if (!f) break;
    }
    alive[v] = 0;
    //mp.clear();
    tmr++;
    dfs2(v, 1 << (s[v] - 'a'), [&](int mask) {
        mp[mask]++;
    });
    need = 1 << (s[v] - 'a');
    vv = v;
    mp[need]--;
    for (int to : e[v]) {
        if (!alive[to]) continue;
        tmr++;
        dfs2(to, (1 << (s[v] - 'a')) ^ (1 << (s[to] - 'a')), [&](int mask) {
            mp[mask]--;
        });

        tmr++;
        dfs3(to, (1 << (s[to] - 'a')));
        ans[v] += up[to];

        tmr++;
        dfs2(to, (1 << (s[v] - 'a')) ^ (1 << (s[to] - 'a')), [&](int mask) {
            mp[mask]++;
        });
    }
    mp[need]++;
    tmr++;
    dfs2(v, 1 << (s[v] - 'a'), [&](int mask) {
        mp[mask]--;
    });
    ans[v] += 2;

    for (int to : e[v]) {
        if (!alive[to]) continue;
        solve(to);
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
            ans[i] = 0;
            alive[i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        scanf("%s", s);

        solve(0);
        for (int i = 0; i < n; i++) {
            ans[i] /= 2;
            printf("%lld%c", ans[i], " \n"[i + 1 == n]);
        }
    }

    return 0;
}