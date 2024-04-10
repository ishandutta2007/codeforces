#include <bits/stdc++.h>

const int N = 100005;
const int P = 1000000007;

std::string str;

int n, q, x, y;
int fact[N], invf[N];
int cnt[52], save[52][52];
int dp[N], now[N];

void add(int &a, int b) {
    a += b;
    if (a >= P) a -= P;
}

void dec(int &a, int b) {
    a -= b;
    if (a < 0) a += P;
}

int pow_mod(int a, int i) {
    int s = 1;
    while (i) {
        if (i & 1) s = 1LL * s * a % P;
        a = 1LL * a * a % P;
        i >>= 1;
    }
    return s;
}

int comb(int n, int k) {
    if (n < k) return 0;
    return 1LL * fact[n] * invf[k] % P * invf[n - k] % P;
}

int find_id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    fact[0] = invf[0] = 1;
    for (int i = 1; i <= 100000; ++i) fact[i] = 1LL * fact[i - 1] * i % P;
    invf[100000] = pow_mod(fact[100000], P - 2);
    for (int i = 99999; i >= 1; i--) invf[i] = 1LL * invf[i + 1] * (i + 1) % P;
    std::cin >> str;
    n = str.size();
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) cnt[find_id(str[i])]++;
    int res = 1LL * fact[n / 2] * fact[n / 2] % P;
    for (int i = 0; i < 52; ++i) res = 1LL * res * invf[cnt[i]] % P;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 52; ++i) {
        if (!cnt[i]) continue;
        for (int j = n; j >= cnt[i]; j--) add(dp[j], dp[j - cnt[i]]);
    }
    for (int id1 = 0; id1 < 52; ++id1)
        for (int id2 = id1 + 1; id2 < 52; ++id2) {
            if (cnt[id1] + cnt[id2] > n / 2) {
                save[id1][id2] = 0;
                continue;
            }
            now[0] = 1;
            for (int j = 0; j <= n; ++j) {
                now[j] = dp[j];
                if (j >= cnt[id1]) dec(now[j], now[j - cnt[id1]]);
            }
            for (int j = 0; j <= n; ++j) {
                if (j >= cnt[id2]) dec(now[j], now[j - cnt[id2]]);
            }
            save[id1][id2] = 2LL * res * now[n / 2 - cnt[id1] - cnt[id2]] % P;
        }
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> x >> y, --x, --y;
        if (str[x] == str[y]) {
            int id = find_id(str[x]);
            if (cnt[id] > n / 2 && (std::cout << 0 << '\n', true)) continue;
            std::cout << (1LL * dp[n / 2] * res % P) << '\n';
        } else {
            int id1 = find_id(str[x]), id2 = find_id(str[y]);
            if (id1 > id2) std::swap(id1, id2);
            if (id1 == id2 && (std::cout << 1LL * dp[n / 2] * res % P)) {
            }
            std::cout << (id1 == id2 ? 1LL * dp[n / 2] * res % P : save[id1][id2]) << '\n';
        }
    }
    return 0;
}