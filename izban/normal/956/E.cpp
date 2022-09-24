#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
const int INF = (int)1.01e9;

const int N = 10010;

int solve(int n, int l, int r, vector<int> _a, vector<int> _b) {
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {1 - _b[i], _a[i]};
    sort(a.begin(), a.end());

    bitset<N> can;
    can[0] = 1;
    vector<int> frst(N, -1);
    frst[0] = n;
    for (int i = n - 1; i >= 0; i--) {
        auto nw = can | (can << a[i].second);
        auto xr = nw ^ can;
        for (int j = xr._Find_first(); j < N; j = xr._Find_next(j)) {
            frst[j] = i;
        }
        can = nw;
    }

    int ans = 0;
    int sum = 0;
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first == 1) break;
        for (int j = 0; j <= r - l; j++) {
            //if (dp[j] == -1) continue;
            int already = sum - j;
            int need = l - already;
            if (need < 0) continue;
            int k = frst[need];
            if (k > i) {
                ans = max(ans, dp[j] + 1);
            }
        }
        for (int j = N - a[i].second; j >= 0; j--) {
            //if (dp[j] == -1) continue;
            dp[j + a[i].second] = max(dp[j + a[i].second], dp[j] + 1);
        }
        sum += a[i].second;
    }
    return ans;
}

int slow(int n, int l, int r, vector<int> _a, vector<int> _b) {
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {_a[i], _b[i]};
    sort(a.begin(), a.end());

    int ans = 0;
    do {
        int cur = 0;
        int cans = 0;
        for (int i = 0; i < n; i++) {
            cans += a[i].second * (cur >= l && cur <= r);
            cur += a[i].first;
        }
        ans = max(ans, cans);
    } while (next_permutation(a.begin(), a.end()));
    return ans;
}

void stress() {
    for (int it = 27;; it++) {
        cout << it << endl;
        srand(it);

        int n = rand() % 10 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rand() % 10 + 1;
        vector<int> b(n);
        for (int i = 0; i < n; i++) b[i] = rand() % 2;

        int sum = 0;
        for (int x : a) sum += x;
        int l = rand() % (sum + 1);
        int r = rand() % (sum + 1);
        if (l > r) swap(l, r);

        auto ans1 = solve(n, l, r, a, b);
        auto ans2 = slow(n, l, r, a, b);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << " " << l << " " << r << endl;
            for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
            for (int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
            slow(n, l, r, a, b);
            solve(n, l, r, a, b);
            exit(0);
        }
    }
}

void test() {
    int n = 1e4;
    int l = 0;
    int r = 1e4;
    vector<int> a(n, 1);
    vector<int> b(n, 1);
    cout << solve(n, l, r, a, b) << endl;
    cout << clock() / (double)CLOCKS_PER_SEC << endl;
    exit(0);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //stress();
    //test();

    int n, l, r;
    while (scanf("%d%d%d", &n, &l, &r) == 3) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        vector<int> b(n);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);

        printf("%d\n", solve(n, l, r, a, b));
    }

    return 0;
}