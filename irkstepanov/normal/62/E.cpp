#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

const ll inf = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;

    vector<vector<ll> > hor(m, vector<ll>(n));
    for (int j = 0; j < m - 1; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> hor[j][i];
        }
    }

    vector<vector<ll> > dp(2, vector<ll>(1 << n));
    dp[0].assign(1 << n, inf);
    dp[0][0] = 0;
    int ptr = 0;

    vector<ll> ver(n);
    for (int i = 0; i < n; ++i) {
        cin >> ver[i];
    }

    for (int j = 0; j < m - 1; ++j) {
        dp[ptr ^ 1].assign(1 << n, inf);
        for (int i = 0; i < n; ++i) {
            cin >> ver[i];
        }
        for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
            ll sum = 0;
            for (int i = 0; i < n; ++i) {
                if (bit(mask2, i) != bit(mask2, (i + 1) % n)) {
                    sum += ver[i];
                }
            }
            for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
                ll curr = sum;
                for (int i = 0; i < n; ++i) {
                    if (bit(mask1, i) != bit(mask2, i)) {
                        curr += hor[j][i];
                    }
                }
                dp[ptr ^ 1][mask2] = min(dp[ptr ^ 1][mask2], dp[ptr][mask1] + curr);
            }
        }
        ptr ^= 1;
    }

    cout << dp[ptr][(1 << n) - 1] << "\n";

}