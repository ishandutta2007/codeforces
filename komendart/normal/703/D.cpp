#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int tree[maxn];

void add(int p, int x) {
    for (int i = p; i < maxn; i |= i + 1) {
        tree[i] ^= x;
    }
}

int get(int r) {
    int ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans ^= tree[i];
    }
    return ans;
}

int n, m;
int a[maxn];
#define next psodjfposdjgs
int next[maxn];
int pref[maxn];
int ans[maxn];

signed main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ a[i - 1];
    }
    map<int, int> d;
    for (int i = n - 1; i >= 0; i--) {
        if (d.find(a[i]) != d.end()) {
            next[i] = d[a[i]];
        } else {
            next[i] = -1;
        }
        d[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (i == d[a[i]]) {
            add(i, a[i]);
        }
    }

    vector< pair< pair<int, int>, int> > queries(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--; r--;
        queries[i] = {{l, r}, i};
    }
    sort(queries.begin(), queries.end());
    int prev = 0;
    for (auto it: queries) {
        int l, r, i;
        l = it.first.first; r = it.first.second;
        i = it.second;
        while (prev != l) {
            add(prev, a[prev]);
            if (next[prev] != -1) add(next[prev], a[prev]);
            prev++;
        }
        ans[i] = pref[r + 1] ^ pref[l] ^ get(r);
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
}