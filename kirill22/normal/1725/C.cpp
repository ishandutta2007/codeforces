#include "bits/stdc++.h"

using namespace std;

const int mod = 998244353;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * 1ll * x % mod;
        }
        x = x * 1ll * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> fact(m + 1, 1), ifact(m + 1, 1);
    for (int i = 1; i <= m; i++) {
        fact[i] = fact[i - 1] * 1ll * i % mod;
    }
    ifact.back() = binpow(fact.back(), mod - 2);
    for (int i = m; i >= 1; i--) {
        ifact[i - 1] = ifact[i] * 1ll * i % mod;
    }

    auto C = [&] (int n, int k) {
        return fact[n] * 1ll * ifact[n - k] % mod * ifact[k] % mod;
    };
    long long sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1) {
        cout << binpow(m, n);
        return 0;
    }
    int cnt = 0;
    long long cursum = 0;
    set<long long> st;
    for (int i = 0; i + 1 < n; i++) {
        st.insert(cursum);
        cursum += a[i];
        if (st.find(cursum - sum / 2) != st.end()) {
            cnt++;
        }
    }
    int ans = 0;
    for (int x = 0; x <= min(m, cnt); x++) {
        int res = C(m, x) * 1ll * fact[x] % mod;
        res = res * 1ll * C(cnt, x) % mod;
        int f = m - x;
        res = res * 1ll * binpow(f, n - 2 * cnt) % mod;
        res = res * 1ll * binpow(f * 1ll * (f - 1) % mod, cnt - x) % mod;
        ans = (ans + res) % mod;
        //cout << x << " " << cnt << " " << res << endl;
    }
    cout << ans;
}