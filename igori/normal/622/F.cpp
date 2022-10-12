const int MOD = 1e9 + 7;

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
    // 2 * mod should fit in int
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

        inline modint<mod> operator += (const modint<mod> &other)
        {
            val += other.val;
            if (val >= mod)
                val -= mod;
            return *this;
        }

        friend inline modint<mod> operator + (modint<mod> x, const modint<mod> &y)
        {
            x += y;
            return x;
        }

        inline modint<mod> operator -= (const modint<mod> &other)
        {
            val -= other.val;
            if (val < 0)
                val += mod;
            return *this;
        }

        friend inline modint<mod> operator - (modint<mod> x, const modint<mod> &y)
        {
            x -= y;
            return x;
        }

        inline modint<mod> operator *= (const modint<mod> &other)
        {
            val = 1ll * val * other.val % mod;
            return *this;
        }

        friend inline modint<mod> operator * (modint<mod> x, const modint<mod> &y)
        {
            x *= y;
            return x;
        }

        friend inline modint<mod> binpow(const modint<mod> &x, const int &d)
        {
            modint<mod> res(1);
            for (int i = upperbit(d); i >= 0; i--)
            {
                res = res * res;
                if (d & (1 << i)) res = res * x;
            }
            return res;
        }

        inline friend modint<mod> binpow(const modint<mod> &x, long long d)
        {
            if (x.val == 0) return 0;
            d = d % (mod - 1);
            return binpow(x, (int)d);
        }

        friend inline modint<mod> inv(const modint<mod> &x)
        {
            return binpow(x, mod - 2);
        }

        inline modint<mod> operator /= (const modint<mod> &other)
        {
            *this *= inv(other);
            return *this;
        }

        friend inline modint<mod> operator / (modint<mod> x, const modint<mod> &y)
        {
            x /= y;
            return x;
        }

        friend inline istream& operator >> (istream& in, modint<mod> &a)
        {
            in >> a.val;
            return in;
        }

        friend inline ostream& operator << (ostream& out, const modint<mod> &a)
        {
            out << a.val;
            return out;
        }

        inline bool operator == (const modint<mod> &other)
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
    inline modint<mod> fact(const int &n, _ec_storage_<mod> &st = _ec_storage)
    {
        st.touch(n + 1);
        return st.fact[n];
    }

    template<const int mod = MOD>
    inline modint<mod> inv(const int &n, _ec_storage_<mod> &st = _ec_storage)
    {
        st.touch(n + 1);
        return st.inv[n];
    }

    template<const int mod = MOD>
    inline modint<mod> ifact(const int &n, _ec_storage_<mod> &st = _ec_storage)
    {
        st.touch(n + 1);
        return st.ifact[n];
    }

    template<const int mod = MOD>
    inline modint<mod> cnk2(const int &n, const int &k, _ec_storage_<mod> &st = _ec_storage)
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
    inline modint<mod> cnk(const int &n, const int &k, _ec_storage_<mod> &st = _ec_storage)
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

modint<MOD> calc(vector<modint<MOD> > &values, modint<MOD> &x)
{
    if (x.val < values.size()) return values[x.val];

    modint res = 0;

    vector<modint<MOD> > le(values.size()), ri(values.size());
    le[0] = (x - 0);
    for (int i = 1; i < le.size(); i++) le[i] = le[i - 1] * (x - i);
    ri[values.size() - 1] = (x - int(values.size()) + 1);
    for (int i = values.size() - 2; i >= 0; i--) ri[i] = ri[i + 1] * (x - i);

    for (int i = 0; i < values.size(); i++)
    {
        res += values[i] * (i ? le[i - 1] : 1) * (i + 1 < ri.size() ? ri[i + 1] : 1)
        * ifact(i)
        * ifact(values.size() - i - 1)
        * (i % 2 != values.size() % 2 ? 1 : -1);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    modint n;
    int k;
    cin >> n >> k;

    vector<modint<MOD> > values;
    values.push_back(0);

    for (int i = 1; i <= k + 1; i++)
    {
        values.push_back(values.back() + binpow(modint(i), k));
    }

    cout << calc(values, n) << "\n";
}