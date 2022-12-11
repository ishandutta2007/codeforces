#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int K = 10;
const int base = int(1e8);
const int mod = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

struct Number {
    int m[K];
    Number() {
        memset(m, 0, sizeof(m));
    }
    Number(ll x) {
        memset(m, 0, sizeof(m));
        int ptr = 0;
        while (x) {
            m[ptr++] = x % base;
            x /= base;
        }
    }
    Number operator+(const Number& other) const {
        Number res;
        for (int i = 0; i < K; ++i) {
            res.m[i] += m[i] + other.m[i];
            if (res.m[i] >= base) {
                res.m[i] -= base;
                ++res.m[i + 1];
            }
        }
        return res;
    }
    Number operator*(int b) const {
        Number res;
        int c = 0;
        for (int i = 0; i < K; ++i) {
            res.m[i] = c + m[i] * b;
            c = res.m[i] / base;
            res.m[i] %= base;
        }
        return res;
    }
    Number operator-(const Number& other) const {
        Number res;
        for (int i = 0; i < K; ++i) {
            res.m[i] += m[i] - other.m[i];
            if (res.m[i] < 0) {
                res.m[i] += base;
                --res.m[i + 1];
            }
        }
        return res;
    }
};

void print(Number ans) {
    int val = 0;
    for (int i = K - 1; i >= 0; --i) {
        mul(val, base % mod);
        add(val, ans.m[i] % mod);
    }
    cout << val << endl;
}

Number solve(ll rg, int k) {
    if (rg == 0) {
        return 0;
    }
    vector<int> d;
    while (rg) {
        d.pb(rg % 10);
        rg /= 10;
    }
    reverse(all(d));
    vector<vector<Number> > dp(2, vector<Number>(1 << 10));
    vector<vector<ll> > cnt(2, vector<ll>(1 << 10, 0));
    cnt[1][0] = 1;
    for (int i = 0; i < sz(d); ++i) {
        vector<vector<Number> > nx(2, vector<Number>(1 << 10));
        vector<vector<ll> > cntNext(2, vector<ll>(1 << 10, 0));
        for (int mask = 0; mask < (1 << 10); ++mask) {
            int x = d[i];
            nx[1][mask | (1 << x)] = nx[1][mask | (1 << x)] + dp[1][mask] * 10 + Number(cnt[1][mask]) * x;
            cntNext[1][mask | (1 << x)] += cnt[1][mask];
            int lf = 0, rg = d[i] - 1;
            if (i == 0) {
                ++lf;
            }
            for (int y = lf; y <= rg; ++y) {
                nx[0][mask | (1 << y)] = nx[0][mask | (1 << y)] + dp[1][mask] * 10 + Number(cnt[1][mask]) * y;
                cntNext[0][mask | (1 << y)] += cnt[1][mask];
            }
            for (int y = 0; y < 10; ++y) {
                nx[0][mask | (1 << y)] = nx[0][mask | (1 << y)] + dp[0][mask] * 10 + Number(cnt[0][mask]) * y;
                cntNext[0][mask | (1 << y)] += cnt[0][mask];
            }            
        }
        dp.swap(nx);
        cnt.swap(cntNext);
    }
    //cout << "!" << cnt[0][1 << 1] << endl;
    Number ans;
    for (int mask = 0; mask < (1 << 10); ++mask) {
        if (__builtin_popcount(mask) <= k) {
            ans = ans + dp[1][mask];
            ans = ans + dp[0][mask];
        }
    }
    return ans;
}

Number f(ll rg, int k) {
    if (rg == 0) {
        return Number(0);
    }
    Number ans = solve(rg, k);
    int len = 0;
    while (rg) {
        ++len;
        rg /= 10;
    }
    for (int i = 1; i < len; ++i) {
        ll val = 0;
        for (int j = 0; j < i; ++j) {
            val *= 10;
            val += 9;
        }
        ans = ans + solve(val, k);
    }
    return ans;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll l, r;
    int k;
    cin >> l >> r >> k;

    //Number ans = solve(l - 1, k);
    Number ans = f(r, k);
    ans = ans - f(l - 1, k);
    print(ans);

}