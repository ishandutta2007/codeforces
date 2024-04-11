#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>
#include <memory>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;

const int MX = 1e6 + 7;
vector<int> g[MX];
vector<int> p(MX, -1);
int sz[MX];
vector<int> ctr;
int n;

void get_sz(int v) {
    sz[v] = 1;
    bool c = true;
    for (int i : g[v]) {
        if (i == p[v]) continue;
        get_sz(i);
        sz[v] += sz[i];
        c &= sz[i] <= n / 2;
    }
    c &= (n - sz[v]) <= n / 2;
    if (c) ctr.push_back(v);
}

int used[MX];

ll doit(int v, int h) {
    used[v] = 1;
    ll res = h;
    for (int i : g[v]) {
        if (used[i]) continue;
        res += doit(i, h + 1);
    }
    return res;
}

ll get_ans(int v) {
    fill(used, used + MX, 0);
    ll cur = doit(v, 1);
    vector<int> s;
    vector<int> cnt(n);
    for (int i : g[v]) {
        if (i != p[v]) cnt[sz[i]]++;
    }
    cnt[n - sz[v]]++;

    bitset<MX / 2> c;
    c[0] = 1;
    for (int i = 1; i < n; i++) {
        if (!cnt[i]) continue;
        for (int j = 1; j <= cnt[i]; j *= 2) {
            c |= (c << (j * i));
            cnt[i] -= j;
        }
        c |= (c << (cnt[i] * i));
    }
    for (int i = (n - 1) / 2; i >= 0; i--) {
        if (c[i]) {
            int x = min((n - 1) / 2, i + cnt[1]);
            return cur + (n - 1 - x) * 1ll * x;
        }
    }
    return cur;
}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }

    get_sz(0);
    ll ans = -1;
    for (int c : ctr) {
        ans = max(get_ans(c), ans);
    }
    cout << ans << '\n';



    return 0;
}