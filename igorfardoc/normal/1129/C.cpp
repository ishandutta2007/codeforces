#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define maxn 3000
#define P 100019
#define MOD1 1000000007
#define MOD2 1000000009
#define MOD3 1791791791
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int a[maxn];
int dp[maxn][maxn];
int p1[maxn + 1], h1[maxn + 1], p2[maxn + 1], h2[maxn + 1];


void precalc() {
    p1[0] = 1;
    for(int i = 1; i <= maxn; i++) {
        p1[i] = (ll)p1[i - 1] * P % MOD1;
    }
    p2[0] = 1;
    for(int i = 1; i <= maxn; i++) {
        p2[i] = (ll)p2[i - 1] * P % MOD2;
    }
}

void calc_dp(int l, int r) {
    if(l == r) {
        dp[l][r] = 1;
        return;
    }
    dp[l][r] = 0;
    for(int len = 1; len <= min(4, r - l + 1); len++) {
        string s = "";
        for(int j = l; j < l + len; j++) {
            if(a[j]) {
                s += "1";
            } else {
                s += "0";
            }
        }
        if(s == "0011" || s == "0101" || s == "1110" || s == "1111") continue;
        if(len == r - l + 1) {
            dp[l][r] = (dp[l][r] + 1) % mod;
            break;
        }
        dp[l][r] = (dp[l][r] + dp[l + len][r]) % mod;
    }
}

ll get_hash(int l, int r) {
    int j1 = (h1[r + 1] - (ll)p1[r - l + 1] * h1[l] % MOD1 + MOD1) % MOD1;
    int j2 = (h2[r + 1] - (ll)p2[r - l + 1] * h2[l] % MOD2 + MOD2) % MOD2;
    return (ll)j1 * MOD1 + j2;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    precalc();
    int n;
    cin >> n;
    vi ans(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = i; j >= 0; j--) {
            calc_dp(j, i);
        }
        h1[i + 1] = ((ll)h1[i] * P + a[i] + 1) % MOD1;
        h2[i + 1] = ((ll)h2[i] * P + a[i] + 1) % MOD2;
    }
    for(int len = 1; len <= n; len++) {
        gp_hash_table<ll, bool> s;
        int now = 0;
        for(int i = 0; i < n - len + 1; i++) {
            ll here = get_hash(i, i + len - 1);
            if(s.find(here) == s.end()) {
                now = (now + dp[i][i + len - 1]) % mod;
                s[here] = true;
            }
            ans[i + len - 1] = (ans[i + len - 1] + now) % mod;
        }
    }
    for(const auto& el : ans) {
        cout << el << '\n';
    }
}