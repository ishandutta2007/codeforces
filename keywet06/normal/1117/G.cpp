#include <bits/stdc++.h>

typedef long long i6;
typedef std::pair<int, int> i5;
typedef std::pair<i6, i6> pi6;

const int N = 1000005;
const int M = 4194304;

int n, q;
int P[N];
int lef[N], rig[N];
int B[2][M], C[2][M];
int qa[N], qb[N];

i6 qres[N];
i6 A[2][M];

std::vector<int> S;
std::vector<int> upd[N], quer[N];

void Add(int s, int v, int l, int r, int a, int b, i6 aA, i6 aB, i6 aC) {
    if (l == a && r == b) {
        A[s][v] += aA;
        B[s][v] += aB;
        C[s][v] += aC;
    } else {
        int m = l + r >> 1;
        if (b <= m) {
            Add(s, 2 * v, l, m, a, b, aA, aB, aC);
        } else if (m + 1 <= a) {
            Add(s, 2 * v + 1, m + 1, r, a, b, aA, aB, aC);
        } else {
            Add(s, 2 * v, l, m, a, m, aA, aB, aC);
            Add(s, 2 * v + 1, m + 1, r, m + 1, b, aA + aB * (m + 1 - a), aB, aC);
        }
    }
}

pi6 Get(int s, int v, int l, int r, int x) {
    pi6 res = pi6(A[s][v] + i6(B[s][v]) * (x - l), C[s][v]);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m) {
            pi6 g = Get(s, 2 * v, l, m, x);
            res.first += g.first;
            res.second += g.second;
        } else {
            pi6 g = Get(s, 2 * v + 1, m + 1, r, x);
            res.first += g.first;
            res.second += g.second;
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &P[i]);
        while (!S.empty() && P[S.back()] < P[i]) {
            rig[S.back()] = i - 1;
            S.pop_back();
        }
        if (S.empty()) {
            lef[i] = 1;
        } else {
            lef[i] = S.back() + 1;
        }
        S.push_back(i);
    }
    while (!S.empty()) {
        rig[S.back()] = n;
        S.pop_back();
    }
    for (int i = 1; i <= n; ++i) {
        Add(0, 1, 1, n, i, rig[i], i - lef[i] + 1, 1, 1);
        if (rig[i] < n) Add(0, 1, 1, n, rig[i] + 1, n, rig[i] - lef[i] + 1, 0, 1);
        upd[lef[i]].push_back(i);
        upd[i + 1].push_back(i);
    }
    for (int i = 1; i <= q; ++i) scanf("%d", &qa[i]);
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &qb[i]);
        quer[qa[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < upd[i].size(); ++j) {
            int ind = upd[i][j];
            if (i == lef[ind]) {
                Add(0, 1, 1, n, ind, rig[ind], -(ind - lef[ind] + 1), -1, -1);
                if (rig[ind] < n) Add(0, 1, 1, n, rig[ind] + 1, n, -(rig[ind] - lef[ind] + 1), 0, -1);
                Add(1, 1, 1, n, ind, rig[ind], ind + 1, 1, 1);
                if (rig[ind] < n) Add(1, 1, 1, n, rig[ind] + 1, n, rig[ind] + 1, 0, 1);
            } else {
                Add(1, 1, 1, n, ind, rig[ind], -(ind + 1), -1, -1);
                if (rig[ind] < n) Add(1, 1, 1, n, rig[ind] + 1, n, -(rig[ind] + 1), 0, -1);
            }
        }
        for (int j = 0; j < quer[i].size(); ++j) {
            int ind = quer[i][j];
            i6 A = Get(0, 1, 1, n, qb[ind]).first;
            pi6 got = Get(1, 1, 1, n, qb[ind]);
            qres[ind] = A + i6(got.first) - i6(i) * got.second;
        }
    }
    for (int i = 1; i <= q; ++i) printf("%I64d%c", qres[i], i + 1 <= q ? ' ' : '\n');
    return 0;
}