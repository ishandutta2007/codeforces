#include<bits/stdc++.h>

using namespace std;

void gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0, y = 1;
        return;
    }
    long long x1, y1;
    gcd(b % a, a, x1, y1);
    x = y1 - x1 * (b / a);
    y = x1;
    return;
}

template<const int& MOD>
struct modint {
    int val;

    modint(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = (int) v;
    }

    modint(unsigned long long v) {
        if (v >= MOD) v %= MOD;
        val = (int) v;
    }

    modint(int v) : modint((long long) v) {}
    modint(unsigned v) : modint((unsigned long long) v) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator long long() const { return val; }
    explicit operator unsigned long long() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    modint& operator+= (const modint& other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    modint& operator-= (const modint& other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(unsigned long long x, unsigned m = MOD) {
        return unsigned(x % m);
    }

    modint& operator*= (const modint& other) {
        val = fast_mod((unsigned long long) val * other.val);
        return *this;
    }

    modint& operator/= (const modint& other) {
        return *this *= other.inv();
    }

    friend modint operator+ (const modint& a, const modint& b) { return (modint) a += b; }
    friend modint operator- (const modint& a, const modint& b) { return (modint) a -= b; }
    friend modint operator* (const modint& a, const modint& b) { return (modint) a *= b; }
    friend modint operator/ (const modint& a, const modint& b) { return (modint) a /= b; }

    modint& operator++ () {
        val = (val == MOD - 1 ? 0 : val + 1);
        return *this;
    }

    modint& operator-- () {
        val = (val == 0 ? MOD - 1 : val - 1);
        return *this;
    }

    modint operator++ (int) { modint before = *this; ++*this; return before; }
    modint operator-- (int) { modint before = *this; --*this; return before; }

    modint operator- () const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator== (const modint& a, const modint& b) { return a.val == b.val; }
    friend bool operator!= (const modint& a, const modint& b) { return a.val != b.val; }
    friend bool operator< (const modint& a, const modint& b) { return a.val < b.val; }
    friend bool operator> (const modint& a, const modint& b) { return a.val > b.val; }
    friend bool operator<= (const modint& a, const modint& b) { return a.val <= b.val; }
    friend bool operator>= (const modint& a, const modint& b) { return a.val >= b.val; }

    static int inv_mod(int a, int m = MOD) {
        long long x, y;
        gcd(a, m, x, y);
        return (x % m + m);
    }

    modint inv() const {
        return inv_mod(val);
    }

    modint pow(long long p) const {
        if (p < 0) return pow(-p).inv();
        modint a = *this, result = 1;
        while (p > 0) {
            if (p & 1) result *= a;
            p >>= 1;
            if (p > 0) a *= a;
        }
        return result;
    }

    friend ostream& operator<< (ostream& os, const modint& m) {
        return os << m.val;
    }
};

extern const int MOD = 1e9 + 7;
using mint = modint<MOD>;

vector<mint> inv, factorial, inv_factorial;
int pr = 0;

void precalc_fact(long long mx) {
    if (pr == 0) {
        inv = {0, 1};
        factorial = inv_factorial = {1, 1};
        pr = 1;
    }
    if (mx <= pr) return;
    inv.resize(mx + 1);
    factorial.resize(mx + 1);
    inv_factorial.resize(mx + 1);
    for (int i = pr + 1; i <= mx; i++) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i);
        factorial[i] = i * factorial[i - 1];
        inv_factorial[i] = inv[i] * inv_factorial[i - 1];
    }
    pr = mx;
}

mint C(long long n, long long k) {
    if (k < 0 || k > n) return 0;
    return factorial[n] * inv_factorial[k] * inv_factorial[n - k];
}

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto c : s) if (c == '?') cnt++;
    mint ans = 0;
    {
        // abc
        mint t = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') t += 1;
            else if (s[i] == 'b') {
                t2 += t;
            }
            else if (s[i] == 'c') {
                ans += ((mint) 3).pow(cnt) * t2;
            }
        }
    }
    {
        // ab?
        mint t = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') t += 1;
            else if (s[i] == 'b') {
                t2 += t;
            }
            else if (s[i] == '?') {
                ans += ((mint) 3).pow(cnt - 1) * t2;
            }
        }
    }
    {
        // ?bc
        mint t = 0, t2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'c') t++;
            else if (s[i] == 'b') {
                t2 += t;
            }
            else if (s[i] == '?') {
                ans += ((mint) 3).pow(cnt - 1) * t2;
            }
        }
    }
    {
        // a?c
        vector<mint> cnta(n, 0), cntc(n, 0);
        for (int i = 1; i < n; i++) {
            cnta[i] = cnta[i - 1] + (s[i - 1] == 'a');
        }
        for (int i = n - 2; i >= 0; i--) {
            cntc[i] = cntc[i + 1] + (s[i + 1] == 'c');
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') ans += cnta[i] * cntc[i] * ((mint) 3).pow(cnt - 1);
        }
    }
    {
        // ???
        if (cnt >= 3) {
            mint p = (cnt * (cnt - 1) * (cnt - 2)) / 6;
            ans += p * ((mint) 3).pow(cnt - 3);
        }
    }
    {
        // ??c
        mint t = 0, t2 = 0;
        for (int i = n - 1; i >= 0 && cnt >= 2; i--) {
            if (s[i] == 'c') t++;
            else if (s[i] == '?') {
                ans += t2 * ((mint) 3).pow(cnt - 2);
                t2 = t2 + t;
            }
        }
    }
    {
        // a??
        mint t = 0, t2 = 0;
        for (int i = 0; i < n && cnt >= 2; i++) {
            if (s[i] == 'a') t++;
            else if (s[i] == '?') {
                ans += t2 * ((mint) 3).pow(cnt - 2);
                t2 = t2 + t;
            }
        }
    }
    {
        // ?b?
        vector<mint> cnta(n, 0), cntc(n, 0);
        for (int i = 1; i < n; i++) {
            cnta[i] = cnta[i - 1] + (s[i - 1] == '?');
        }
        for (int i = n - 2; i >= 0; i--) {
            cntc[i] = cntc[i + 1] + (s[i + 1] == '?');
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') ans += cnta[i] * cntc[i] * ((mint) 3).pow(cnt - 2);
        }
    }
    cout << ans;
}