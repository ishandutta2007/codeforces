#include <bits/stdc++.h>

typedef long long int64;

const int N = 1e5 + 5;
const int M = 5e5 + 5;
const int L = N + M;
const int V = L * 2;

char s[L];

int d, l, sn;
int len[V], to[V][27], Lin[V], pos[V], g[L];

int64 f[V];

int code(int c) { return c == '#' ? 26 : c - 'a'; }

void addc(int c, int xxx) {
    s[sn++] = c;
    c = code(c);
    int x = d++;
    f[x] = xxx;
    len[x] = len[l] + 1;
    pos[x] = sn - 1;
    for (; l != -1 && !to[l][c]; l = Lin[l]) to[l][c] = x;
    if (l != -1) {
        int p = to[l][c];
        if (len[p] == len[l] + 1)
            Lin[x] = p;
        else {
            int q = d++;
            len[q] = len[l] + 1;
            Lin[q] = Lin[p];
            pos[q] = pos[p];
            memcpy(to[q], to[p], sizeof(to[q]));
            for (; l != -1 && to[l][c] == p; l = Lin[l]) to[l][c] = q;
            Lin[x] = Lin[p] = q;
        }
    }
    l = x;
}

int a[N];

std::string t[N];

std::vector<int> v[L];

int main() {
    d = 0, l = d++, Lin[l] = -1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", s), t[i] = s;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        addc('#', 0);
        for (char c : t[i]) addc(c, a[i]);
    }
    g[0] = 0;
    for (int i = 1; i < sn; ++i) {
        if (s[i] == '#') {
            g[i] = i;
        } else {
            g[i] = g[i - 1];
        }
    }
    for (int i = 0; i < d; ++i) v[len[i]].push_back(i);
    int64 ans = 0;
    for (int h = sn; h; --h) {
        for (int i : v[h]) {
            int j = Lin[i];
            f[j] += f[i];
            int lng = len[i];
            if (pos[i] - lng + 1 <= g[pos[i]]) lng = pos[i] - g[pos[i]];
            if (lng > len[j]) {
                int64 res = f[i] * lng;
                ans = std::max(ans, res);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}