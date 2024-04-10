#include <bits/stdc++.h>

using int64 = long long;

const int N = 200010;

char getc() {
    char c = getchar();
    while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9')) c = getchar();
    return c;
}

int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }

char s[N];

int64 n, m;
int64 tree[3][N], a[N];

int64 val(char c) {
    if (c == 'R') return 0;
    if (c == 'P') return 1;
    if (c == 'S') return 2;
}

void add(int p, int k, int x) {
    while (k <= n) tree[p][k] += x, k += k & -k;
}

int64 query(int p, int k) {
    int s = 0;
    while (k) s += tree[p][k], k -= k & -k;
    return s;
}

std::set<int> q[3];

int main() {
    std::cin >> n >> m;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) add(a[i] = val(s[i]), i, 1), q[val(s[i])].insert(i);
    for (int j = 0, x; j <= m; ++j) {
        if (j) {
            std::cin >> x;
            int64 y = val(getc());
            add(a[x], x, -1), add(y, x, 1);
            q[a[x]].erase(x), a[x] = y, q[a[x]].insert(x);
        }
        int64 ans = 0;
        for (int i = 0; i < 3; ++i) {
            int sc = (i + 2) % 3, pp = (i + 1) % 3;
            if (q[pp].empty()) {
                ans += query(i, n);
            } else if (!q[sc].empty()) {
                ans += query(i, n);
                std::set<int>::iterator it = q[sc].begin();
                int x = *it;
                it = q[sc].end(), --it;
                int y = *it;
                it = q[pp].begin();
                if ((*it) < x) ans -= query(i, x) - query(i, (*it));
                it = q[pp].end(), --it;
                if ((*it) > y) ans -= query(i, (*it)) - query(i, y);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}