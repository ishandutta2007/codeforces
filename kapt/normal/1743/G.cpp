#include <bits/stdc++.h>
using namespace std;

const int MAXF = 2178309, MAXLEN = 32;
bitset<MAXF> fs;
int fib[MAXLEN];

void build(int rk) {
    static int i = 0;
    if (rk < 2) {
        fs[i] = rk;
        i++;
        return;
    }
    build(rk - 1);
    build(rk - 2);
}

const int MAXN = 3e6 + 100;
bitset<MAXN> s;

int get(int i) {
    int cur = fib[30 + s[i]] - 1;
    int j = 0;
    int rk = s[i];
    while (j <= cur && j <= i && fs[cur - j] == s[i - j]) {
        j++;
        if (j >= fib[rk + 2]) {
            rk += 2;
        }
    }
    return rk;
}

const int MAXMEM = 52e4, MOD = 998244353;
int dp[MAXMEM];

int main() {
    fib[0] = fib[1] = 1;
    for (int i = 2; i < MAXLEN; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    build(31);
    int n;
    cin >> n;
    vector<int> bord;
    int len = 0;
    string st;
    for (int i = 0; i < n; ++i) {
        cin >> st;
        for (auto ch : st) {
            s[len] = ch - '0';
            len++;
        }
        bord.push_back(len);
    }
    n = len;
    map<int, int> mem;
    for (int i = 0; i < n; ++i) {
        int rk = get(i);
        if (rk >= 29) {
            mem[i - fib[rk] + 1] = 0;
        }
    }
    dp[0] = 1;
    if (mem.count(0)) {
        mem[0] = 1;
    }
    int fl = 0;
    int sum = 1;
    for (int i = 1; i <= n; ++i) {
        int rk = get(i - 1);
        int j = i % MAXMEM;
        dp[j] = sum;
        for (int t = rk; t >= 0; t -= 2) {
            if (t >= 29) {
                dp[j] -= mem[i - fib[t]];
            } else {
                dp[j] -= dp[(i - fib[t]) % MAXMEM];
            }
            dp[j] = (dp[j] % MOD + MOD) % MOD;
        }
        sum += dp[j];
        sum %= MOD;
        if (i == bord[fl]) {
            cout << dp[j] << endl;
            fl++;
        }
        if (mem.count(i)) {
            mem[i] = dp[j];
        }
    }
    return 0;
}