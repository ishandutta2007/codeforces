#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LEN = 100;
const int MASK = 1 << 10;
const int B = 11;

ll dp[B][LEN][MASK];


ll fastsolve(int b, ll x) {
    if (x == 0) return 0;

    vector<int> a;
    ll y = x;
    while (y) {
        a.push_back(y % b);
        y /= b;
    }
    reverse(a.begin(), a.end());
    int n = a.size();

    ll ans = 0;
    for (int len = 1; len < n; len++) {
        for (int x = 1; x < b; x++) {
            ans += dp[b][len - 1][1 << x];
        }
    }

    int cmask = 0;
    for (int i = 0; i < n; i++) {
        for (int j = (i == 0); j < a[i]; j++) {
            int nmask = cmask ^ (1 << j);
            ans += dp[b][n - 1 - i][nmask];
        }
        cmask ^= 1 << a[i];
    }
    if (cmask == 0) ans++;
    return ans;
}

ll slow(int b, ll n) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        vector<int> a;
        ll y = i;
        int mask = 0;
        while (y) {
            mask ^= 1 << (y % b);
            y /=b;
        }
        if (mask == 0) ans++;
    }
    return ans;
}

void init() {
    memset(dp, 0, sizeof(dp));
    for (int b = 2; b <= 10; b++) {
        dp[b][0][0] = 1;
        for (int i = 0; i < LEN - 1; i++) {
            for (int j = 0; j < (1 << b); j++) {
                for (int x = 0; x < b; x++) {
                    dp[b][i + 1][j ^ (1 << x)] += dp[b][i][j];
                }
            }
        }
    }
}

void stress() {
    for (int n = 1; n <= 100; n++) {
        cout << n << endl;
        for (int b = 2; b <= 10; b++) {
            ll ans1 = fastsolve(b, n);
            ll ans2 = slow(b, n);
            if (ans1 != ans2) {
                cout << "FAIL" << endl;
                assert(0);
            }
        }
    }
    exit(0);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    /*;*/

    init();
    //stress();

    int q;
    while (scanf("%d", &q) == 1) {
        while (q--) {
            int b;
            ll l, r;
            scanf("%d%lld%lld", &b, &l, &r);
            printf("%lld\n", fastsolve(b, r) - fastsolve(b, l - 1));
        }
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}