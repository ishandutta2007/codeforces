#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct book {
    int v, i;
};

bool operator < (const book &a, const book &b) {
    return a.v != b.v ? a.v < b.v : a.i < b.i;
}

struct Query {
    int curn;
    std::multiset <book> used, unused;
    int sum, totsum;

    void clear() {
        curn = sum = totsum = 0;
        used.clear(), unused.clear();
    }

    void insert(book x) {
        totsum -= x.v;
        used.insert(x);
        sum += x.v;
        if ((int) used.size() > curn) {
            book y = *-- used.end();
            used.erase(used.find(y));
            sum -= y.v;
            unused.insert(y);
        }
    }

    void erase(book x) {
        totsum += x.v;
        if (used.find(x) != used.end()) {
            used.erase(used.find(x));
            sum -= x.v;
            if (!unused.empty()) {
                book y = *unused.begin();
                unused.erase(unused.find(y));
                used.insert(y);
                sum += y.v;
            }
        } else {
            unused.erase(unused.find(x));
        }
    }

    int query(int n) {
        while (curn < n) {
            if (!unused.empty()) {
                book y = *unused.begin();
                used.insert(y);
                sum += y.v;
                unused.erase(unused.find(y));
            }
            ++ curn;
        }
        return sum;
    }
} tr;

int n, m, K;
std::vector <book> vec[2][2];

int main() {
    scanf("%d %d %d", &n, &m, &K);
    rep(i, n) {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        vec[a][b].push_back({t, i});
    }
    rep(a, 2) rep(b, 2) std::sort(vec[a][b].begin(), vec[a][b].end());
    int imin = 0, imax = K;
    imin = std::max(imin, 2 * K - m);
    imin = std::max(imin, K - (int) vec[1][0].size());
    imin = std::max(imin, K - (int) vec[0][1].size());
    imax = std::min(imax, (int) vec[1][1].size());
    tr.clear();
    rep(a, 2) rep(b, 2) for (book x : vec[a][b]) tr.totsum += x.v, tr.insert(x);
    std::pair <int, int> ans = {(1LL << 31) - 1, -1};
    int ptr11 = 0, ptr10 = 0, ptr01 = 0;
    for (int i = imin; i <= imax; ++ i) {
        while (ptr11 < i) tr.erase(vec[1][1][ptr11 ++]);
        while (ptr10 < K - i) tr.erase(vec[1][0][ptr10 ++]);
        while (ptr10 > K - i) tr.insert(vec[1][0][-- ptr10]);
        while (ptr01 < K - i) tr.erase(vec[0][1][ptr01 ++]);
        while (ptr01 > K - i) tr.insert(vec[0][1][-- ptr01]);
        ans = std::min(ans, {tr.query(m - (2 * K - i)) + tr.totsum, i});
    }
    if (ans.first > 2e9) puts("-1");
    else {
        printf("%d\n", ans.first);
        std::vector <int> ss;
        rep(i, ans.second) ss.push_back(vec[1][1][i].i);
        rep(i, K - ans.second) ss.push_back(vec[1][0][i].i);
        rep(i, K - ans.second) ss.push_back(vec[0][1][i].i);
        std::vector <book> temp;
        rep(i, vec[1][1].size()) if (i >= ans.second) temp.push_back(vec[1][1][i]);
        rep(i, vec[1][0].size()) if (i >= K - ans.second) temp.push_back(vec[1][0][i]);
        rep(i, vec[0][1].size()) if (i >= K - ans.second) temp.push_back(vec[0][1][i]);
        rep(i, vec[0][0].size()) temp.push_back(vec[0][0][i]);
        std::sort(temp.begin(), temp.end());
        rep(i, m - (2 * K - ans.second)) ss.push_back(temp[i].i);
        rep(i, ss.size()) printf("%d ", ss[i] + 1);
        printf("\n");
    }
    return 0;
}

/*
6 3 1
6 0 0
11 1 0
9 0 1
21 1 1
10 1 0
8 0 1

6 3 2
6 0 0
11 1 0
9 0 1
21 1 1
10 1 0
8 0 1

*/