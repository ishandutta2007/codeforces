#include <iostream>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
const int N = 4444;
const int M = 22222;
const int B = 4001;
int n, p;
struct cell {
    int start;
    int happiness;
    int cost;

    bool operator<(const cell& A) const {
        return start < A.start;
    }
} a[N];
struct query {
    int from, to, budget;
    int id;

    bool operator <(const query& A) const {
        return from < A.from;
    }
} q[M];

int lft[N][N];
int rght[N][N];
int ans[M];

void rec(int l, int r, vector<query> q) {
    if (l >= r || q.size() == 0) return;

    if (l + 1 == r) {
        for (size_t i = 0; i < q.size(); ++i) {
            if (q[i].from <= l && q[i].to > l && q[i].budget >= a[l].cost) {
                ans[q[i].id] = a[l].happiness;
            }
        }
        return;
    }

    int center = (l + r) >> 1;
    vector<query> toleft, toright, nw;
    for (size_t i = 0; i < q.size(); ++i) {
        if (q[i].to <= center) toleft.push_back(q[i]);
        else if (q[i].from >= center) toright.push_back(q[i]);
        else nw.push_back(q[i]);
    }
    q = nw;

    rec(l, center, toleft);
    rec(center, r, toright);

    int maxb = 0, lim = r - center;
    for (int i = 1; i <= lim; ++i) {
        int no = center + i - 1;
        int cost = a[no].cost;
        int hap = a[no].happiness;
        memset(rght[i], 0, sizeof(rght[i]));

        for (int j = min(maxb + cost, B); j >= cost; --j) {
            rght[i][j] = max(rght[i - 1][j], rght[i - 1][j - cost] + hap);
        }
        for (int j = 0; j < cost; ++j) rght[i][j] = rght[i - 1][j];
        maxb += cost;

        for (int j = 1; j < B; ++j) {
            rght[i][j] = max(rght[i][j], rght[i][j - 1]);
        }
    }

    maxb = 0; lim = center - l;
    for (int i = 1; i <= lim; ++i) {
        int no = center - i;
        int cost = a[no].cost;
        int hap = a[no].happiness;
        memset(lft[i], 0, sizeof(lft[i]));

        for (int j = min(maxb + cost, B); j >= cost; --j) {
            lft[i][j] = max(lft[i - 1][j], lft[i - 1][j - cost] + hap);
        }
        for (int j = 0; j < cost; ++j) lft[i][j] = lft[i - 1][j];
        maxb += cost;

        for (int j = 1; j < B; ++j) {
            lft[i][j] = max(lft[i][j], lft[i][j - 1]);
        }
    }

    for (size_t i = 0; i < q.size(); ++i) {
        int nol = center - q[i].from;
        int nor = q[i].to - center;

        for (int c1 = 0; c1 <= q[i].budget; ++c1) {
            int c2 = q[i].budget - c1;
            ans[q[i].id] = max(ans[q[i].id], lft[nol][c1] + rght[nor][c2]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i].cost, &a[i].happiness, &a[i].start);
    }
    sort(a, a + n);

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        int ts;
        scanf("%d%d", &ts, &q[i].budget);
        q[i].id = i;

        q[i].from = n;
        q[i].to = n;
        for (int j = 0; j < n; ++j) {
            if (a[j].start > ts) q[i].to = min(q[i].to, j);
            if (a[j].start >= ts - p + 1) q[i].from = min(q[i].from, j);
        }
    }

    rec(0, n, vector<query>(q, q + Q));

    for (int i = 0; i < Q; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}