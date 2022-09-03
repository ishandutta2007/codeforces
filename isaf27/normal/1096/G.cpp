/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
//const ll MOD = 998244353;
//const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxb[4] = {-1, 1, 1, -1};
const int dyb[4] = {-1, 1, -1, 1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const ll bt = 30;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd(239);

//constants
const int M = 2e5 + 239;
const int N = (2 * M);
const int L = 18;
const int T = (1 << 21);
const int B = trunc(sqrt(M)) + 1;
const int X = 110;

//fft
const int MOD = 998244353;
const ll MOD2 = MOD * MOD;
const ll root = 3;
const ll sub = 15311432;
const ll sub_inv = 469870224;

int st[T], rev[T];
int p_fft, w_fft, z_fft, s_fft, k_fft;

inline int power(int a, ll n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1LL) ans = 1LL * ans * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1LL;
    }
    return ans;
}

inline int inv(int x)
{
    return power(x, MOD - 2);
}

inline void fft(vector<int> &a)
{
    for (int i = 0; i < s_fft; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int k = 1; k < s_fft; k <<= 1)
        for (int i = 0; i < s_fft; i += k + k)
            for (int j = i, t = i + k; j < i + k; j++, t++)
            {
                z_fft = 1LL * a[t] * st[t - i] % MOD;
                a[t] = a[j] - z_fft;
                if (a[t] < 0) a[t] += MOD;
                a[j] = a[j] + z_fft;
                if (a[j] >= MOD) a[j] -= MOD;
            }
}

inline vector<int> multiply(vector<int> a, vector<int> b)
{
    k_fft = ((int)a.size() + (int)b.size()) - 1;
    p_fft = 0;
    while ((1 << p_fft) < k_fft) p_fft++;
    //cerr << p_fft << "!!\n";
    s_fft = (1 << p_fft);
    for (int i = 0; i < s_fft; i++) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (p_fft - 1));
    st[0] = 0;
    st[1] = 1;
    for (int b = 1; b < p_fft; b++)
    {
        w_fft = power(sub, 1 << (22 - b));
        for (int i = (1 << (b - 1)); i < (1 << b); i++)
        {
            st[i << 1] = st[i];
            st[(i << 1) + 1] = 1LL * st[i] * w_fft % MOD;
        }
    }
    while (a.size() < s_fft) a.push_back(0);
    while (b.size() < s_fft) b.push_back(0);
    fft(a);
    fft(b);
    for (int b = 1; b < p_fft; b++)
    {
        w_fft = power(sub_inv, 1 << (22 - b));
        for (int i = (1 << (b - 1)); i < (1 << b); i++)
        {
            st[i << 1] = st[i];
            st[(i << 1) + 1] = 1LL * st[i] * w_fft % MOD;
        }
    }
    vector<int> v;
    for (int i = 0; i < s_fft; i++) v.push_back(1LL * a[i] * b[i] % MOD);
    fft(v);
    while (v.back() == 0) v.pop_back();
    k_fft = inv(s_fft);
    for (int i = 0; i < (int)v.size(); i++) v[i] = 1LL * k_fft * v[i] % MOD;
    return v;
}

struct poly : vector<int>
{
    poly(const vector<int> &a) : vector<int>(a) {}
    poly(int n) : vector<int>(n, 1) {}

    inline void normalize()
    {
        while (size() > 1 && back() == 0) pop_back();
    }

    inline int& operator[](int pos)
    {
        if (pos >= (int)size()) resize(pos + 1);
        return vector<int>::operator[](pos);
    }

    inline int operator[](int pos) const
    {
        if (pos < (int)size()) return vector<int>::operator[](pos);
        return 0;
    }

    inline poly operator+(const poly &b) const
    {
        const poly &a = *this;
        poly ans(max((int)a.size(), (int)b.size()));
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = (a[i] + b[i]);
            if (ans[i] >= MOD) ans[i] -= MOD;
        }
        return ans;
    }

    inline poly operator+=(const poly &p)
    {
        return *this = *this + p;
    }

    inline poly operator-(const poly &b) const
    {
        const poly &a = *this;
        poly ans(max((int)a.size(), (int)b.size()));
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = (a[i] - b[i]);
            if (ans[i] < 0) ans[i] += MOD;
        }
        return ans;
    }

    inline poly operator-=(const poly &p)
    {
        return *this = *this - p;
    }

    inline poly operator*(int d) const
    {
        poly ans = *this;
        for (int i = 0; i < (int)ans.size(); i++)
            ans[i] = (1LL * ans[i] * d % MOD);
        return ans;
    }

    inline poly operator*=(int d)
    {
        return *this = *this * d;
    }

    inline poly operator/(int d) const
    {
        d = inv(d);
        poly ans = *this;
        for (int i = 0; i < (int)ans.size(); i++)
            ans[i] = (1LL * ans[i] * d % MOD);
        return ans;
    }

    inline poly operator/=(int d)
    {
        return *this = *this / d;
    }

    inline poly operator*(const poly &p) const
    {
        return poly(multiply(*this, p));
    }

    inline poly operator*=(const poly &p)
    {
        return *this = *this * p;
    }

    inline poly cut(int n) const
    {
        poly a = (*this);
        a.resize(n);
        return a;
    }

    inline poly invp() const
    {
        poly a(1);
        if ((*this)[0] != 1) a[0] = inv((*this)[0]);
        for (int n = 1; n < (int)size(); n <<= 1)
        {
            poly ca = cut(n + n);
            poly ra = (a * a);
            ra.cut(n + n);
            ra = (ra * ca);
            ra.cut(n + n);
            a += a;
            a -= ra;
            a = a.cut(n + n);
        }
        a.resize(size());
        return a;
    }

    inline poly rev() const
    {
        poly a = (*this);
        reverse(a.begin(), a.end());
        return a;
    }

    inline poly getdiv(poly b) const
    {
        poly a = (*this);
        a.normalize();
        b.normalize();
        if (a.size() < b.size()) return poly({0});
        int k = (int)a.size() - (int)b.size() + 1;
        if (b.back() != 1) b /= b.back();
        poly rb = b.rev().cut(k);
        return (rb.invp() * a.rev()).cut(k).rev();
    }

    inline poly operator/(const poly &b) const
    {
        return getdiv(b);
    }

    inline poly operator/=(const poly &b)
    {
        return *this = *this / b;
    }

    inline poly operator%(const poly &b) const
    {
        poly a = (*this);
        if (a.size() < b.size()) return a;
        poly r = (a - (a / b) * b);
        r.normalize();
        return r;
    }

    inline poly operator%=(const poly &b)
    {
        return *this = *this % b;
    }

    inline poly der() const
    {
        poly a = (*this);
        vector<int> ans;
        for (int i = 1; i < a.size(); i++)
            ans.push_back(1LL * i * a[i] % MOD);
        return poly(ans);
    }

    inline poly integral() const
    {
        poly a = (*this);
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < (int)a.size() - 1; i++)
            ans.push_back(1LL * inv(i + 1) * a[i] % MOD);
        return poly(ans);
    }
};

inline poly log(poly a)
{
    poly b = a;
    b = b.der();
    poly x = a.invp();
    b *= x;
    b.resize(a.size());
    b = b.integral();
    b[0] = 0;
    return b;
}

inline poly exp(poly f)
{
    poly a(1);
    for (int n = 1; n < (int)f.size(); n <<= 1)
    {
        while (a.size() < n + n) a.push_back(0);
        poly ca = f.cut(n + n);
        a += (ca - log(a)) * a;
        a = a.cut(n + n);
    }
    a.resize(f.size());
    return a;
}
//end

const int D = 10;

int n, k;

poly power(poly x, int k)
{
    if (k == 1) return x;
    poly t = power(x, k >> 1);
    t *= t;
    if (k & 1) t *= x;
    return t;
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    poly p = poly(10);
    for (int i = 0; i < 10; i++)
        p[i] = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        p[d]++;
    }
    poly u = power(p, (n / 2));
    ll ans = 0;
    for (int i = 0; i < u.size(); i++)
        ans += (1LL * u[i] * u[i]) % MOD;
    cout << (ans % MOD);
    return 0;
}