#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;

int m[3][N];
set <int> s[3];
int p[N], v, n;

void als(int s, int i, int j) {
    i = i + v -2;
    m[s][i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[s][i] = m[s][2*i + 1] + m[s][2*i + 2];
    }
}

int sum(int s, int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return m[s][v];
    else if (l >= vr || vl >= r)
            return 0;
        else
            return sum(s, 2*v + 1, vl, (vl + vr) / 2, l, r) + sum(s, 2*v + 2, (vl + vr) / 2, vr, l, r);
}

int frt(int a) {
    if (s[a].size() == 0)
        return n + 1;
    else
        return *s[a].begin();
}

int lst(int a) {
    if (s[a].size() == 0)
        return 0;
    else {
        set <int> :: iterator it = s[a].end();
        --it;
        return (*it);
    }
}

int main() {
    int i, j,k, a, b, q;
    char c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i) {
        cin >> c;
        if (c == 'R')
            p[i] = 0;
        if (c == 'P')
            p[i] = 1;
        if (c == 'S')
            p[i] = 2;
        als(p[i], i, 1);
        s[p[i]].insert(i);
    }
    for (i = 0; i <= q; ++i) {
        if (i != 0) {
            cin >> j >> c;
            int pp;
            if (c == 'R')
                pp = 0;
            if (c == 'P')
                pp = 1;
            if (c == 'S')
                pp = 2;
            als(p[j], j, 0);
            als(pp, j, 1);
            s[p[j]].erase(j);
            s[pp].insert(j);
            p[j] = pp;
        }
        int ans = n;
        for (j = 0; j < 3; ++j) {
            int fP = frt((j + 1) % 3);
            int fG = frt((j + 2) % 3);
            int lP = lst((j + 1) % 3);
            int lG = lst((j + 2) % 3);
            int l1 = fP, r1 = fG;
            if (l1 <= r1 && lG <= lP && lG <= r1 && lP >= l1) {
                r1 = lP;
                ans -= sum(j, 0, 1, v + 1, min(fP, lG), max(fG, lP));
            } else
                ans -= sum(j, 0, 1, v + 1, l1, r1) + sum(j, 0, 1, v + 1, lG, lP);
        }
        cout << ans << "\n";
    }

}