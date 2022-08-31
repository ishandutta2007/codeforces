#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cassert>

using namespace std;
const int M = 6000000;
const int N = 200000;
const int L = 16;
int r[N][18];
int x[N];
int n, m, prime[M], isp[M + 10], tot, low[300], twon[300], S[N];
int mindis[M][8];
vector<pair<int, int> > w[N];

int parse(int num, vector<pair<int, int> > &w) {
    vector<int> p;
    for (int i = 1; 1ll * prime[i] * prime[i] <= num; ++i) {
        if (num % prime[i] == 0) {
            int key = 0;
            while (num % prime[i] == 0) {
                num /= prime[i];
                key ^= 1;
            }
            if (key) {
                p.push_back(prime[i]);
            }
        }
    }
    if (num > 1) {
        p.push_back(num);
    }
    static int mul[300];
    int n = p.size();
    mul[0] = 1;
    for (int i = 0; i < (1 << n); ++i) {
        if (i) {
            int fir = low[i];
            mul[i] = mul[i - (1 << fir)] * p[fir];
        }
        w.push_back(make_pair(mul[i], n - __builtin_popcount(i)));
    }
    return n;
}

struct query {
    int l, r, where;
} Q[2000000];
int res[2000000];

int cmp(query a, query b) {
    return a.l > b.l;
}

int mi[N * 8];

void init(int node, int l, int r) {
    mi[node] = 20;
    if (l < r) {
        int m = (l + r >> 1);
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
    }
}

void update(int node, int l, int r, int loc, int w) {
    if (l == r) {
        mi[node] = min(mi[node], w);
        return;
    }
    int m = (l + r >> 1);
    if (m >= loc) {
        update(node * 2, l, m, loc, w);
    } else {
        update(node * 2 + 1, m + 1, r, loc, w);
    }
    mi[node] = min(mi[node * 2], mi[node * 2 + 1]);
}

int query(int node, int l, int r, int ll, int rr) {
    if (l > rr || r < ll) {
        return 20;
    }
    if (l >= ll && r <= rr) {
        return mi[node];
    }
    int m = (l + r >> 1);
    return min(query(node * 2, l, m, ll, rr), query(node * 2 + 1, m + 1, r, ll, rr));
}

int main() {
    for (int i = 1; i <= 256; i++) {
        if (i & 1) {
            low[i] = 0;
        } else {
            low[i] = low[i >> 1] + 1;
        }
    }
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= M; i++) {
        if (isp[i] == 0) {
            prime[++tot] = i;
            for (int j = i + i; j <= M; j += i) {
                isp[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        S[i] = parse(x[i], w[i]);
    }
    memset(mindis, 0x3f, sizeof mindis);
    memset(r, 0x3f, sizeof r);
    for (int i = n; i; i--) {
        for (int j = 0; j < w[i].size(); j++) {
            int d = w[i][j].second;
            int num = w[i][j].first;
            for (int k = 0; k <= 7; k++) {
                r[i][k + d] = min(r[i][k + d], mindis[num][k]);
            }
            mindis[num][d] = i;
        }
        for (int j = 1; j <= 14; j++) {
            r[i][j] = min(r[i][j], r[i][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &Q[i].l, &Q[i].r);
        Q[i].where = i;
    }
    sort(Q + 1, Q + m + 1, cmp);
    int rr = 1;
    init(1, 1, n);
    for (int i = n; i; i--) {
        for (int j = 0; j <= 14; j++) {
            if (r[i][j] <= n) {
                update(1, 1, n, r[i][j], j);
            }
        }
        while (rr <= m && Q[rr].l == i) {
            res[Q[rr].where] = query(1, 1, n, Q[rr].l, Q[rr].r);
            rr++;
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", res[i]);
    }
}