#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll dp[2][5005];
ll a[5005];

// ce prodje valjda i segmentno, ali moze i u O(n^2)

ll b[16384];

ll gett(int l, int r, int x = 1, int xl = 0, int xr = 8191) {
        if (r < xl || xr < l)
                return -123123123123123123ll;
        if (l <= xl && xr <= r)
                return b[x];
        int xm = (xl + xr) >> 1;
        return max(gett(l, r, 2*x, xl, xm), gett(l, r, 2*x+1, xm+1, xr));
}

void sett(int x, ll y) {
        x += 8192;
        b[x] = y;
        while (x > 1) {
                x >>= 1;
                b[x] = max(b[2*x], b[2*x+1]);
        }
}

void clr() {
        memset(b, 128, sizeof(b));
}

// old[x-k..x-1] -> nu[x]

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, k, x;
        cin >> n >> k >> x;
        for (int i=1; i<=n; i++)
                cin >> a[i];

        memset(dp[0], 128, sizeof(dp[0]));
        dp[0][0] = 0;
        auto ol = dp[0];
        auto nu = dp[1];
        for (int i=0; i<x; i++) {
                // postavi
                clr();
                memset(nu, 0, sizeof(dp[0]));
                for (int j=0; j<=n; j++)
                        sett(j, ol[j]);
                for (int j=1; j<=n; j++)
                        nu[j] = gett(j-k, j-1) + a[j];

                swap(ol, nu);

                for (int j=0; j<=n; j++)
                        cerr << max(-1ll, ol[j]) << ' ';
                cerr << '\n';
        }
        ll sol = -1;
        for (int i=n-k+1; i<=n; i++)
                sol = max(sol, ol[i]);
        cout << sol << '\n';
}