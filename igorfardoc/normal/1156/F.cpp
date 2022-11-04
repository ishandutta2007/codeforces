#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 998244353;
int fact[10000], rfact[10000];

int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) res = ((ll)res * a) % mod;
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}


int c(int n, int k) {
    if(n < 0 || k < 0 || k > n) return 0;
    int res = (ll)fact[n] * rfact[k] % mod;
    res = (ll)res * rfact[n - k] % mod;
    return res;
}


void precalc() {
    fact[0] = 1;
    for(int i = 1; i < 10000; i++) {
        fact[i] = (ll)fact[i - 1] * i % mod;
        rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
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
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vi am;
    int prev = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[prev]) continue;
        am.push_back(i - prev);
        prev = i;
    }
    am.push_back(n - prev);
    int ans = 0;
    vi dp(n + 1, 0);
    vi dp1(n + 1, 0);
    dp1[0] = 1;
    for(int i = 0; i < am.size(); i++) {
        if(am[i] > 1) {
            for(int bef = 0; bef <= i; bef++) {
                int can = (ll)dp1[bef] * c(am[i], 2) * 2 % mod;
                can = (ll)can * fact[n - bef - 2] % mod;
                ans = (ans + can) % mod;
            }
        }
        for(int j = 0; j <= n; j++) {
            dp[j] = dp1[j];
            if(j > 0) {
                dp[j] = (dp[j] + (ll)dp1[j - 1] * am[i]) % mod;
            }
        }
        swap(dp, dp1);
    }
    ans = (ll)ans * rfact[n] % mod;
    cout << ans;
}