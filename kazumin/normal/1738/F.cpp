#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1005;

int t, n, d[MN], col[MN], par[MN], sz[MN], cnt[MN];

int ask(int u) {
    cout << "? " << u << endl;
    int ret;
    cin >> ret;
    assert(ret != -1);
    return ret;
}

bool cmp(int x, int y) {
    return d[x] > d[y];
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[y] = par[x];
    sz[x] += sz[y];
    cnt[x] += cnt[y];
    return true;
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            cin >> d[i], v.push_back(i);
            par[i] = i;
            sz[i] = d[i];
            cnt[i] = 1;
        }
        sort(v.begin(), v.end(), cmp);
        for (int cur : v) {
            while (sz[find(cur)] > cnt[find(cur)] * cnt[find(cur)]) {
                int nxt = ask(cur);
                merge(cur, nxt);
            }
        }
        cout << "!";
        for (int i = 1; i <= n; i++) cout << " " << find(i);
        cout << endl;
    }

    return 0;
}