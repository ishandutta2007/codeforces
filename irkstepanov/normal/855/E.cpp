#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int lmax = 70;

ll bin[lmax][lmax];
ll dp[11][lmax][11];

ll solve(const int b, ll val) {
    vector<int> s;
    while (val) {
        s.pb(val % b);
        val /= b;
    }
    reverse(all(s));
    ll ans = 0;
    for (int f = 1; f < sz(s); ++f) {
        for (int d = 1; d < b; ++d) {
            ans += dp[b][sz(s) - f - 1][1];
        }
    }
    for (int d = 1; d < s[0]; ++d) {
        ans += dp[b][sz(s) - 1][1];
    }
    int cnt[b];
    int sum = 1;
    memset(cnt, 0, sizeof(cnt));
    cnt[s[0]] = 1;
    for (int f = 1; f < sz(s); ++f) {
        for (int d = 0; d < s[f]; ++d) {
            cnt[d] ^= 1;
            if (cnt[d] == 0) {
                --sum;
            } else {
                ++sum;
            }
            ans += dp[b][sz(s) - f - 1][sum];
            cnt[d] ^= 1;
            if (cnt[d] == 0) {
                --sum;
            } else {
                ++sum;
            }
        }
        cnt[s[f]] ^= 1;
        if (cnt[s[f]] == 0) {
            --sum;
        } else {
            ++sum;
        }
    }
    ans += dp[b][0][sum];
    return ans;
}

int main() {

    //ifstream cin("input.txt");
    //freopen("defend.out", "w", stdout);
    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    bin[0][0] = 1;
    for (int i = 1; i < lmax; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j < lmax; ++j) {
            bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
        }
    }

    dp[1][0][0] = 1;
    for (int len = 1; len < lmax; ++len) {
        dp[1][len][len % 2] = 1;
    }

    for (int b = 2; b <= 10; ++b) {
        dp[b][0][0] = 1;
        for (int len = 1; len < lmax; ++len) {
            for (int cnt = 0; cnt <= b; ++cnt) {
                if (cnt == 0) {
                    for (int z = 0; z <= len; z += 2) {
                        dp[b][len][cnt] += dp[b - 1][len - z][cnt] * bin[len][z];
                    }
                } else {
                    /*for (int z = 0; z <= len; z += 2) {
                        dp[b][len][cnt] += dp[b - 1][len - z][cnt] * bin[len][z];
                    }*/
                    for (int z = 1; z <= len; z += 2) {
                        dp[b][len][cnt] += dp[b - 1][len - z][cnt - 1] * bin[len][z];
                    }
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int b;
        ll l, r;
        cin >> b >> l >> r;
        ll ans = solve(b, r);
        if (l > 1) {
            ans -= solve(b, l - 1);
        }
        cout << ans << "\n";
    }

}