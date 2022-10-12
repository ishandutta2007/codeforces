// modint + cnk (compile time known modulo)

const int MOD = 998244353;

#include <bits/stdc++.h>

using namespace std;

template<typename T> istream& operator >> (istream& in, vector<T>& a) {

    for (size_t i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator << (ostream& out, const vector<T>& a) {

    for (auto e : a)
    {
        out << e << " ";
    }
    return out;
}

namespace intbinary{
    //
    // Usage note: just use the last 5 functions, don't create additional storages.
    //

    struct _intbinary_storage_{
        static const int B = 16;
        static const int S = (1 << B);
        short* lower_upper_bitcount;
        int* bitreverse;

        _intbinary_storage_()
        {
            lower_upper_bitcount = (short*)malloc(S * sizeof(short));
            bitreverse = (int*)malloc(S * sizeof(int));
            lower_upper_bitcount[0] = 0;
            bitreverse[0] = 0;
            for (int i = 1; i < S; i++)
            {
                int l = -1, u = 0, bc = 0;
                int br = 0;
                for (int j = 0; j < B; j++)
                {
                    br = 2 * br;
                    if (i & (1 << j))
                    {
                        bc++;
                        u = j;
                        if (l == -1) l = j;
                        br++;
                    }
                }
                lower_upper_bitcount[i] = l + (u << 4) + (bc << 8);
                bitreverse[i] = br;
            }
        }

        inline int lowerbit(const int &x) const
        {
            return lower_upper_bitcount[x] & 15;
        }

        inline int upperbit(const int &x) const
        {
            return (lower_upper_bitcount[x] & 255) >> 4;
        }

        inline int bitcount(const int &x) const
        {
            return lower_upper_bitcount[x] >> 8;
        }

    };

    const _intbinary_storage_ _intbinary_storage;

    inline int lowerbit(const int &x)
    {
        if (x & (_intbinary_storage.S - 1))
            return _intbinary_storage.lowerbit(x & (_intbinary_storage.S - 1));
        return _intbinary_storage.lowerbit(x >> _intbinary_storage.B)
             + _intbinary_storage.B;
    }

    inline int upperbit(const int &x)
    {
        if (x >= _intbinary_storage.S)
            return _intbinary_storage.upperbit(x >> _intbinary_storage.B)
                 + _intbinary_storage.B;
        return _intbinary_storage.upperbit(x);
    }

    inline int bitcount(const int &x)
    {
        return _intbinary_storage.bitcount(x >> _intbinary_storage.B)
             + _intbinary_storage.bitcount(x & (_intbinary_storage.S - 1));
    }

    inline int bitreverse(const int &x, const int &len)
    {
        if (len <= _intbinary_storage.B)
            return _intbinary_storage.bitreverse[x << (_intbinary_storage.B - len)];
        int fr = len - _intbinary_storage.B;
        int low = _intbinary_storage.bitreverse[x >> fr];
        int high = _intbinary_storage.bitreverse[x & ((1 << fr) - 1)] >> (_intbinary_storage.B - fr);
        return low + (high << _intbinary_storage.B);
    }

    inline int binpow(const int &x, const int &d, const int &mod)
    {
        int res = 1;
        for (int i = upperbit(d); i >= 0; i--)
        {
            res = 1ll * res * res % mod;
            if (d & (1 << i)) res = 1ll * res * x % mod;
        }
        return res;
    }
};

using namespace intbinary;

namespace modint_template{
    //
    // Usage note: use with known module, by default mod = MOD is used.
    //

    template <const int mod = MOD>
    struct modint{
        int val;

        modint()
        {
            val = 0;
        }

        modint(int x)
        {
            if (x < 0 || x >= mod)
                x = x % mod;
            if (x < 0)
                x += mod;
            val = x;
        }

        modint(long long x)
        {
            if (x < 0 || x >= mod)
                x = x % mod;
            if (x < 0)
                x += mod;
            val = x;
        }

        modint<mod> operator += (const modint<mod> &other)
        {
            val += other.val;
            if (val >= mod)
                val -= mod;
            return *this;
        }

        friend modint<mod> operator + (modint<mod> x, const modint<mod> &y)
        {
            x += y;
            return x;
        }

        modint<mod> operator -= (const modint<mod> &other)
        {
            val -= other.val;
            if (val < 0)
                val += mod;
            return *this;
        }

        friend modint<mod> operator - (modint<mod> x, const modint<mod> &y)
        {
            x -= y;
            return x;
        }

        modint<mod> operator *= (const modint<mod> &other)
        {
            long long res = 1ll * val * other.val;
            if (res < mod)
                val = res;
            else
                val = res % mod;
            return *this;
        }

        friend modint<mod> operator * (modint<mod> x, const modint<mod> &y)
        {
            x *= y;
            return x;
        }

        friend modint<mod> binpow(const modint<mod> &x, const int &d)
        {
            modint<mod> res(1);
            for (int i = upperbit(d); i >= 0; i--)
            {
                res = res * res;
                if (d & (1 << i)) res = res * x;
            }
            return res;
        }

        friend modint<mod> binpow(const modint<mod> &x, long long d)
        {
            if (x.val == 0) return 0;
            d = d % (mod - 1);
            return binpow(x, (int)d);
        }

        friend modint<mod> inv(const modint<mod> &x)
        {
            return binpow(x, mod - 2);
        }

        modint<mod> operator /= (const modint<mod> &other)
        {
            *this *= inv(other);
            return *this;
        }

        friend modint<mod> operator / (modint<mod> x, const modint<mod> &y)
        {
            x /= y;
            return x;
        }

        friend istream& operator >> (istream& in, modint<mod> &a)
        {
            in >> a.val;
            return in;
        }

        friend ostream& operator << (ostream& out, const modint<mod> &a)
        {
            out << a.val;
            return out;
        }

        bool operator == (const modint<mod> &other)
        {
            return val == other.val;
        }
    };
};

using namespace modint_template;

namespace easy_combinatorics{
    //
    // Usage note: use fact, inv, ifact, cnk with mod = MOD by default.
    // ? For other modules, create _ec_storage_<mod2> E() and send E as an argument to function.
    //

    const int _ec_limit = 5e6;

    template<const int mod = MOD>
    struct _ec_storage_{
        vector<modint<mod> > fact, ifact, inv;

        inline void touch(int n)
        {
            if (n < 2) n = 2;
            if (fact.size() > size_t(n)) return;
            int pn = fact.size();
            fact.resize(n); ifact.resize(n); inv.resize(n);
            if (pn == 0)
            {
                inv[1] = 1;
                fact[0] = 1;
                fact[1] = 1;
                ifact[0] = 1;
                ifact[1] = 1;
                pn = 2;
            }
            for (int i = pn; i < n; i++)
            {
                inv[i] = mod - inv[mod % i] * (mod / i);
                fact[i] = fact[i - 1] * i;
                ifact[i] = ifact[i - 1] * inv[i];
            }
        }
    };
    _ec_storage_ _ec_storage;

    template<const int mod = MOD>
    inline modint<mod> fact(int n, _ec_storage_<mod> &st = _ec_storage)
    {
        st.touch(n + 1);
        return st.fact[n];
    }

    template<const int mod = MOD>
    inline modint<mod> inv(int n, _ec_storage_<mod> &st = _ec_storage)
    {
        st.touch(n + 1);
        return st.inv[n];
    }

    template<const int mod = MOD>
    inline modint<mod> ifact(int n, _ec_storage_<mod> &st = _ec_storage)
    {
        st.touch(n + 1);
        return st.ifact[n];
    }

    template<const int mod = MOD>
    inline modint<mod> cnk2(int n, int k, _ec_storage_<mod> &st = _ec_storage)
    {
        modint<mod> res = 1;
        k = min(k, n - k);
        for (int i = 1; i <= k; i++)
        {
            res *= (n + 1 - i);
            if (i < _ec_limit)
                res *= inv(i, st);
            else
                res /= i;
        }
        return res;
    }

    template<const int mod = MOD>
    inline modint<mod> cnk(int n, int k, _ec_storage_<mod> &st = _ec_storage)
    {
        if (k < 0 || k > n)
            return 0;
        if (n > _ec_limit)
            return cnk2(n, k, st);
        st.touch(n + 1);
        return fact(n, st) * ifact(k, st) * ifact(n - k, st);
    }
};

using namespace easy_combinatorics;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector dp(k + 1, vector(k + 1, modint(0)));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1] * (n - j + 1);
        }
    }

    modint q = inv(modint(m));
    modint z = q;
    modint ans = 0;
    for (int d = 1; d <= k; d++)
    {
        ans += dp[k][d] * z;
        z *= q;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests

    while (t--)
    {
        solve();
    }
}