#include <bits/stdc++.h>

const int N = 500005;

using namespace std;

int c[N];
int n, cnt;

inline int lowbit(int x) { return x & (-x); }

void add(int x, int d) {
    while (x > 0) {
        if (c[x] < d) c[x] = d;
        x -= lowbit(x);
    }
}

int getmax(int x) {
    int s = -1;
    for (int i = x; i <= cnt; i += lowbit(i)) {
        if (s < c[i]) s = c[i];
    }
    return s;
}

struct node {
    int b, i, r;
    int id;
} d[N];

bool cmp(node a, node b) { return a.b < b.b; }

bool cmp1(node a, node b) { return a.i > b.i; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int i, j, ans;
    while (std::cin >> n) {
        ans = 0;
        for (i = 0; i < n; ++i) std::cin >> d[i].b;
        for (i = 0; i < n; ++i) std::cin >> d[i].i;
        for (i = 0; i < n; ++i) std::cin >> d[i].r;
        sort(d, d + n, cmp), cnt = 1, d[0].id = 1;
        for (i = 1; i < n; ++i) d[i].id = d[i].b == d[i - 1].b ? cnt : ++cnt;
        sort(d, d + n, cmp1);
        for (i = 1; i <= cnt; ++i) c[i] = -1;
        for (i = 0; i < n;) {
            for (j = i; j < n && d[i].i == d[j].i; ++j) {
                ans += getmax(d[j].id + 1) > d[j].r;
            }
            for (j = i; j < n && d[i].i == d[j].i; ++j) add(d[j].id, d[j].r);
            i = j;
        }
        std::cout << ans << '\n';
    }
    return 0;
}