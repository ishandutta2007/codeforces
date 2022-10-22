#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int t, n, a[MN], b[MN], vis[MN], id[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], id[a[i]] = i, vis[i] = 0;
        for (int i = 1; i <= n; i++) cin >> b[i];
        vector<int> cycs;
        for (int i = 1; i <= n; i++) {
            if (vis[a[i]]) continue;
            int cur = i, len = 1;
            vis[a[i]] = 1;
            while (!vis[b[cur]]) vis[b[cur]] = 1, cur = id[b[cur]], len++;
            cycs.push_back(len);
        }
        int ans = 0;
        deque<int> deq;
        for (int i = 1; i <= n; i++) deq.push_back(i);
        for (int p : cycs) {
            int num = p / 2 * 2;
            if (!num) continue;
            vector<int> cyc;
            for (int i = 0; i < num; i++) {
                if (i & 1) cyc.push_back(deq.back()), deq.pop_back();
                else cyc.push_back(deq.front()), deq.pop_front();
            }
            for (int i = 0; i < num; i++) ans += abs(cyc[i] - cyc[(i + 1) % num]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}