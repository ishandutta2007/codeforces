#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

std::vector <int> solve(int a[], int n) {
    static int len[1 << 15];
    len[0] = 0;
    rep(i, 1 << 15) if (i) len[i] = len[i ^ (i & -i)] + 1;
    int n0 = n >> 1, n1 = n - n0;
    std::map <int, std::pair <int, int> > map[30][30];
    rep(mask, 1 << n0) {
        int rest = ((1 << n0) - 1) ^ mask;
        for (int mask0 = rest; ; mask0 = (mask0 - 1) & rest) {
            int sum = 0;
            rep(i, n0) if (mask >> i & 1) sum += a[i];
            else if (mask0 >> i & 1) sum -= a[i];
            map[len[mask]][len[mask0]][sum] = {mask, mask0};
            if (!mask0) break;
        }
    }
    int MASK = -1, MASK0 = -1;
    rep(mask, 1 << n1) {
        int rest = ((1 << n1) - 1) ^ mask;
        for (int mask0 = rest; ; mask0 = (mask0 - 1) & rest) {
            int sum = 0;
            rep(i, n1) if (mask >> i & 1) sum += a[i + n0];
            else if (mask0 >> i & 1) sum -= a[i + n0];
            for (int x = std::max(1, std::max(len[mask], len[mask0])); x <= n; ++ x) {
                if (map[x - len[mask]][x - len[mask0]].find(-sum) != map[x - len[mask]][x - len[mask0]].end()) {
                    MASK = mask << n0 | map[x - len[mask]][x - len[mask0]][-sum].first;
                    MASK0 = mask0 << n0 | map[x - len[mask]][x - len[mask0]][-sum].second;
                    goto FOUND;
                }
            }
            if (!mask0) break;
        }
    }
    return {};
    FOUND: {}
//    eprintf("%d %d\n", MASK, MASK0);
    std::vector <int> e0, e1;
    rep(i, n) if (MASK >> i & 1) e0.push_back(i);
    else if (MASK0 >> i & 1) e1.push_back(i);
    std::vector <int> e;
    rep(i, e0.size()) e.push_back(e0[i]), e.push_back(e1[i]);
    std::vector <int> A;
    rep(i, e.size()) if (i == 0) A.push_back(0);
    else A.push_back(a[e[i - 1]] - A.back());
    std::sort(e.begin(), e.end());
    rep(i, n) {
        auto it = std::lower_bound(e.begin(), e.end(), i);
        if (it == e.end() || *it != i) A.push_back(a[i]);
    }
    return A;
}

const int mxn = 1005;

int n, a[mxn];

inline void fail() {
    puts("NO");
    exit(0);
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    if (n == 2) {
        if (a[0] != a[1]) fail();
        puts("YES");
        printf("%d %d\n", 0, a[0]);
        return 0;
    }
    int cnt = 0;
    rep(i, n) if (a[i] % 2 == 0) ++ cnt;
    if (cnt) {
        std::vector <int> vec;
        rep(i, n) if (a[i] % 2 == 0) vec.push_back(i);
        if ((int) vec.size() <= 2) {
            vec = {vec[0]};
            rep(i, n) if (a[i] % 2 == 1) vec.push_back(i);
        }
        if ((int) vec.size() < 3) fail();
        vec.resize(3);
        std::sort(vec.begin(), vec.end());
        // x + y = vec[0]
        // y + z = vec[1]
        // x + z = vec[2]
        // x + y + z = (vec[0] + vec[1] + vec[2]) / 2
        int sum = (a[vec[0]] + a[vec[1]] + a[vec[2]]) / 2;
        int x = sum - a[vec[1]];
        int y = sum - a[vec[2]];
        int z = sum - a[vec[0]];
        puts("YES");
        printf("%d %d %d", x, y, z);
        rep(i, n) {
            auto it = std::lower_bound(vec.begin(), vec.end(), i);
            if (it == vec.end() || *it != i) printf(" %d", a[i] - x);
        }
        printf("\n");
        return 0;
    }
    auto vec = solve(a, std::min(n, 27));
    if (vec.empty()) fail();
    for (int i = std::min(n, 27); i < n; ++ i) vec.push_back(a[i] - vec[0]);
    puts("YES");
    rep(i, n) printf("%d ", vec[i]);
    puts("");
    return 0;
}