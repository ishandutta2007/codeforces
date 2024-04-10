#include<bits/stdc++.h>

using namespace std;

const long long p = 101, mod = 1e9 + 7, p2 = 117, mod2 = 1e9 + 13;

vector<long long> power, power2;

void update() {
    power.resize(1000022, 1);
    for (int i = 1; i < power.size(); i++) {
        power[i] = (power[i - 1] * p) % mod;
    }
    power2.resize(1000022, 1);
    for (int i = 1; i < power2.size(); i++) {
        power2[i] = (power2[i - 1] * p2) % mod2;
    }
}

struct Hash {
    int n;
    vector<long long> h, h2;
    Hash() {};
    Hash(string s) : n(s.size()) {
        h.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            h[i] = (h[i - 1] * p + s[i - 1]) % mod;
        }
        h2.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            h2[i] = (h2[i - 1] * p2 + s[i - 1]) % mod2;
        }
    }
    long long get1(int l, int r) const {
        return (h[r + 1] - h[l] * power[r - l + 1] + mod * mod) % mod;
    }
    long long get2(int l, int r) const {
        return (h2[r + 1] - h2[l] * power2[r - l + 1] + mod2 * mod2) % mod2;
    }
    pair<long long, long long> get(int l, int r) const {
        return {get1(l, r), get2(l, r)};
    }
};

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * 1ll * x % mod;
        }
        x = x * 1ll * x % mod;
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    update();
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> suf(n + 2, vector<int> (26));
    for (int i = n; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (i > 0) {
            int pos = t[i - 1] - 'a';
            int x = binpow(2, n - i);
            suf[i][pos] = (suf[i][pos] + x) % mod;
        }
    }
    auto solve = [&] (auto k, auto w) {
        int cnt = (int) s.size(), m = (int) w.size(), c = 0;
        string S = s;
        while (cnt < m && c < n) {
            cnt = cnt * 2 + 1;
            S = S + t[c] + S;
            c++;
        }
        if (c > k) {
            return 0;
        }
        int ans = 0;
        Hash hw(w), hS(S);
        for (int i = 0; i + m - 1 < (int) S.size(); i++) {
            if (hw.get(0, m - 1) == hS.get(i, i + m - 1)) {
                ans++;
            }
        }
        ans = ans * 1ll * binpow(2, k - c) % mod;
        for (int i = 0; i < m; i++) {
            int j = w[i] - 'a';
            if (hw.get(0, i - 1) != hS.get((int) S.size() - i, (int) S.size() - 1)) {
                continue;
            }
            if (hw.get(i + 1, m - 1) != hS.get(0, m - i - 2)) {
                continue;
            }
            int sum = (suf[c + 1][j] - suf[k + 1][j] + mod) % mod;
            sum = sum * 1ll * binpow(binpow(2, mod - 2), n - k) % mod;
            ans = (ans + sum) % mod;
        }
        return ans;
    };
    while (q--) {
        int k;
        string w;
        cin >> k >> w;
        cout << solve(k, w) << '\n';
    }
}