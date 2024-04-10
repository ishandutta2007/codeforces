#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;

ll solve(vector<int> a) {
    int n = a.size();
    ll res = 0;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];

        int k = min(x / 2, ones);
        x -= 2 * k;
        ones -= k;
        res += k;

        k = x / 3;
        res += k;
        x %= 3;

        ones += x;
    }
    return res;
}

ll slow(vector<int> a) {
    ll sum = 0;
    for (int x : a) sum += x;

    vector<int> dp(sum + 1, -1);
    dp[0] = 0;
    for (int x : a) {
        vector<int> ndp(sum + 1, -1);
        for (int i = 0; i <= sum; i++) {
            if (dp[i] < 0) continue;
            for (int j = 0; j <= i && j * 2 <= x; j++) {
                for (int t = 0; j * 2 + t * 3 <= x; t++) {
                    int nleft = i - j + (x - j * 2 - t * 3);
                    int nval = dp[i] + j + t;
                    ndp[nleft] = max(ndp[nleft], nval);
                }
            }
        }
        dp = ndp;
    }
    int ans = *max_element(dp.begin(), dp.end());
    return ans;
}

void stress() {
    for (int it = 0;; it++) {
        db(it);
        srand(it);


        int n = rand() % 30 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rand() % 15 + 1;

        auto ans1 = solve(a);
        auto ans2 = slow(a);
        if (ans1 != ans2) {
            cout << ans1 << " instead of " << ans2 << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
//    stress();
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        ll res = solve(a);
        cout << res << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}