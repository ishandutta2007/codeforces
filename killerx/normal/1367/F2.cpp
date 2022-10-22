#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, a[mxn];
std::vector <int> vec;
std::vector <int> occ[mxn];

int cnt_false;
std::set <int> avai;

bool is_false(int i, int j) {
    return a[i] > a[j];
}

void add(int i) {
    avai.insert(i);
    auto it = avai.lower_bound(i);
    cnt_false -= is_false(*std::prev(it), *std::next(it));
    cnt_false += is_false(*std::prev(it), i);
    cnt_false += is_false(i, *std::next(it));
}

void del(int i) {
    auto it = avai.lower_bound(i);
    cnt_false -= is_false(*std::prev(it), i);
    cnt_false -= is_false(i, *std::next(it));
    cnt_false += is_false(*std::prev(it), *std::next(it));
    avai.erase(i);
}

bool check() {
    return cnt_false == 0;
}

void Main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i + 1]);
    // eprintf("!! ");
    // for (int i = 1; i <= n; ++ i) eprintf("%d ", a[i]);
    // eprintf("\n");
    a[0] = -0x3f3f3f3f; a[n + 1] = 0x3f3f3f3f;
    n += 2;
    vec.clear();
    rep(i, n) vec.push_back(a[i]);
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    rep(i, vec.size()) occ[i].clear();
    rep(i, n) a[i] = std::lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
    rep(i, n) occ[a[i]].push_back(i);
    avai.clear();
    cnt_false = 0;
    avai.insert(0);
    avai.insert(n - 1);
    int ans = 0;
    for (int i = 1; i < (int) vec.size() - 1; ++ i) {
        ans = std::max(ans, (int) occ[i].size());
    }
    for (int i = 1; i + 1 < (int) vec.size() - 1; ++ i) {
        rep(j, occ[i].size()) {
            int k = std::lower_bound(occ[i + 1].begin(), occ[i + 1].end(), occ[i][j]) - occ[i + 1].begin();
            ans = std::max(ans, j + 1 + (int) occ[i + 1].size() - k);
        }
    }
    for (int L = 1, R = 0; L < (int) vec.size() - 1; ++ L) {
        while (R + 1 < (int) vec.size() - 1) {
            ++ R;
            for (int x : occ[R]) add(x);
            if (!check()) {
                for (int x : occ[R]) del(x);
                -- R;
                break;
            }
        }
        int cur = (int) avai.size() - 2;
        if (L - 1 >= 1) {
            cur += std::lower_bound(occ[L - 1].begin(), occ[L - 1].end(), *std::next(avai.begin())) - occ[L - 1].begin();
        }
        if (R + 1 < (int) vec.size() - 1) {
            cur += occ[R + 1].end() - std::lower_bound(occ[R + 1].begin(), occ[R + 1].end(), *std::prev(-- avai.end()));
        }
        // eprintf("[%d, %d] %d\n", vec[L], vec[R], cur);
        ans = std::max(ans, cur);
        for (int x : occ[L]) del(x);
    }
    printf("%d\n", n - 2 - ans);
}

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}