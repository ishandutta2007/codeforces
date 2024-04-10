const int MOD = 998'244'353;
const int MOD2 = 1'004'535'809;
const int MOD3 = 1'007'681'537;

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

namespace fft{
    const int fft_cutoff = 250;

    template <const int mod = MOD>
    constexpr pair<int, int> find_g_constexpr()
    {
        int mxsz = 0;
        int z = mod - 1;
        while (z % 2 == 0) z /= 2, mxsz++;

        mxsz = min(mxsz, 20);

        for (int i = 3; ; i += 2)
        {
            int x = i;
            int fl = 1;
            for (int j = 0; j < mxsz - 1; j++)
            {
                x = 1ll * x * x % mod;
                if (x == 1)
                {
                    fl = 0;
                    break;
                }
            }
            x = 1ll * x * x % mod;
            if (fl == 1 && x == 1)
                return {mxsz, i};
        }
    }

    template <const int mod = MOD>
    struct fft_runner{
        int mxsz;
        modint<mod>** pw;

        fft_runner()
        {
            pair<int, int> prec = find_g_constexpr<mod>();
            mxsz = prec.first;
            modint<mod> g = prec.second;
            modint<mod> inv_g = inv(g);
            pw = (modint<mod>**)malloc(2 * sizeof(modint<mod>*));
            pw[0] = (modint<mod>*)malloc((1 << mxsz) * sizeof(modint<mod>));
            pw[1] = (modint<mod>*)malloc((1 << mxsz) * sizeof(modint<mod>));
            pw[0][0] = 1, pw[1][0] = 1;
            for (int i = 1; i < (1 << mxsz); i++)
                pw[0][i] = pw[0][i - 1] * g, pw[1][i] = pw[1][i - 1] * inv_g;
        }

        void dft(vector<modint<mod> > &a, int fl, int lg) const
        {
            for (size_t i = 0; i < a.size(); i++)
            {
                size_t br = bitreverse(i, lg);
                if (i < br)
                    swap(a[i], a[br]);
            }
            modint<mod> v, u;
            for (size_t len = 2, deep = mxsz - 1; len <= a.size(); len <<= 1, deep--)
            {
                for (size_t i = 0; i < a.size(); i += len)
                {
                    for (size_t j = 0; j < len / 2; j++)
                    {
                        v = a[i + j], u = a[i + j + len / 2] * pw[fl][j << deep];
                        a[i + j] = v + u;
                        a[i + j + len / 2] = v - u;
                    }
                }
            }
        }

        vector<modint<mod> > fft(vector<modint<mod> > a, vector<modint<mod> > b) const
        {
            int deg = a.size() + b.size() - 1;

            if (deg <= fft_cutoff)
            {
                vector<modint<mod> > ans(deg);
                for (size_t i = 0; i < a.size(); i++)
                {
                    for (size_t j = 0; j < b.size(); j++)
                    {
                        ans[i + j] += a[i] * b[j];
                    }
                }
                return ans;
            }

            int lg = upperbit(deg);
            int sz = (1 << lg);
            if (sz < deg) sz <<= 1, lg++;
            assert(lg <= lowerbit(mod - 1) && "degree of polynomials is too high for this modulo");
            assert(lg <= 20 && "degree of polynomials is larger than pow(2, 20)");
            a.resize(sz);
            b.resize(sz);
            dft(a, 0, lg);
            dft(b, 0, lg);
            for (int i = 0; i < sz; i++)
                a[i] *= b[i];
            dft(a, 1, lg);
            modint<mod> q = inv(modint<mod>(sz));
            for (int i = 0; i < sz; i++)
                a[i] *= q;
            a.resize(deg);
            return a;
        }
    };
};

using namespace fft;

namespace polynomial{

    template <const int mod = MOD>
    struct poly{
        inline static const fft_runner<mod> run;
        inline static _ec_storage_<mod> _poly_ec_storage;
        vector<modint<mod> > a;

        size_t deg() const
        {
            return a.size() - 1;
        }

        poly(const vector<int> &_a)
        {
            a.resize(_a.size());
            for (size_t i = 0; i < a.size(); i++)
            {
                a[i] = _a[i];
            }
        }

        poly(const vector<long long> &_a)
        {
            a.resize(_a.size());
            for (size_t i = 0; i < a.size(); i++)
            {
                a[i] = _a[i];
            }
        }

        poly(const initializer_list<int> &_b)
        {
            vector<int> _a = _b;
            a.resize(_a.size());
            for (size_t i = 0; i < a.size(); i++)
            {
                a[i] = _a[i];
            }
        }

        poly(const initializer_list<long long> &_b)
        {
            vector<long long> _a = _b;
            a.resize(_a.size());
            for (size_t i = 0; i < a.size(); i++)
            {
                a[i] = _a[i];
            }
        }

        poly operator += (const poly &other)
        {
            a.resize(max(a.size(), other.a.size()));
            for (size_t i = 0; i < other.a.size(); i++)
            {
                a[i] += other.a[i];
            }
            return *this;
        }

        friend poly operator + (poly x, const poly &y)
        {
            x += y;
            return x;
        }

        poly operator -= (const poly &other)
        {
            a.resize(max(a.size(), other.a.size()));
            for (size_t i = 0; i < other.a.size(); i++)
            {
                a[i] -= other.a[i];
            }
            return *this;
        }

        friend poly operator - (poly x, const poly &y)
        {
            x -= y;
            return x;
        }

        poly operator *= (const poly &other)
        {
            a = run.fft(a, other.a);
            return *this;
        }

        friend poly operator * (poly x, const poly &y)
        {
            x *= y;
            return x;
        }

        poly cut(const size_t &n)
        {
            a.resize(n);
            return *this;
        }

        friend poly copycut(poly a, const size_t &n)
        {
            a.cut(n);
            return a;
        }

        friend poly inv(const poly &a, const size_t &n)
        {
            poly b{1};
            b.a[0] = inv(a.a[0]);
            size_t sz = 1;
            while (sz < n)
            {
                b *= (poly{2} - copycut(a, 2 * sz) * b);
                b.cut(2 * sz);
                sz <<= 1;
            }
            b.cut(n);
            return b;
        }

        friend poly deriv(const poly &a)
        {
            poly b{1};
            b.a.resize(a.a.size() - 1);
            for (size_t i = 0; i + 1 < a.a.size(); i++)
            {
                b.a[i] = a.a[i + 1] * (int(i) + 1);
            }
            return b;
        }

        friend poly integr(const poly &a)
        {
            poly b{0};
            b.a.resize(a.a.size() + 1);
            for (size_t i = 0; i < a.a.size(); i++)
            {
                b.a[i + 1] = a.a[i] * inv(i + 1, _poly_ec_storage);
            }
            return b;
        }

        friend poly lg(const poly &a, const size_t &n)
        {
            return integr(deriv(a) * inv(a, n)).cut(n);
        }

        friend poly exp(const poly &a, const size_t &n)
        {
            poly b{1};
            size_t sz = 1;
            while (sz < n)
            {
                b *= (poly{1} + copycut(a, 2 * sz) - lg(b, 2 * sz));
                b.cut(2 * sz);
                sz <<= 1;
            }
            b.cut(n);
            return b;
        }

        friend ostream& operator << (ostream &out, const poly &a)
        {
            out << "[";
            for (size_t i = 0; i < a.a.size(); i++)
                out << a.a[i] << " ]"[i + 1 == a.a.size()];
            return out;
        }
    };
};

using namespace polynomial;

typedef long long ll;
typedef vector<ll> vll;

#define all(x) (x).begin(), (x).end()

template<const int mod = MOD>
vector<modint<mod> > find_h(vll c, vll d)
{
    if (c.size() == 0 && d.size() == 0)
        return vector<modint<mod> >(4, 0);

    poly<mod> F(c), G(d), FF(c);
    poly<mod> H = F * G;

    for (int i = 1; i < F.a.size(); i++) F.a[i] += F.a[i - 1];
    for (int i = 0; i < FF.a.size(); i++) FF.a[i] *= FF.a[i];
    for (int i = 1; i < FF.a.size(); i++) FF.a[i] += FF.a[i - 1];

    modint<mod> Gsum = 0, Gsumsq = 0;
    for (int i = 0; i < G.a.size(); i++) Gsum += G.a[i], Gsumsq += G.a[i] * G.a[i];

    vector<modint<mod> > res(c.size(), modint<mod>(0));

    int m = d.size();
    for (int pos = d.size() - 1; pos < res.size(); pos++)
    {
        res[pos] = -2 * H.a[pos] + Gsumsq - Gsum;
        res[pos] += FF.a[pos] - (pos - m >= 0 ? FF.a[pos - m] : 0);
        res[pos] += F.a[pos] - (pos - m >= 0 ? F.a[pos - m] : 0);
    }
    reverse(all(res));
    res.resize(res.size() + 2);
    reverse(all(res));

    return res;
}

void solve()
{
    #define tests

    int n;
    cin >> n;
    vll a(n);
    cin >> a;
    int m;
    cin >> m;
    vll b(m);
    cin >> b;

    vll c(n - 2), d(m - 2);
    for (int i = 0; i < n - 2; i++) c[i] = a[i + 2] + 2 * a[i + 1] + a[i];
    for (int i = 0; i < m - 2; i++) d[i] = b[i + 2] + 2 * b[i + 1] + b[i];

    reverse(all(d));

    //vector<modint<MOD> > h = find_h<MOD>(c, d);
    vector<modint<MOD2> > h2 = find_h<MOD2>(c, d);
    //vector<modint<MOD3> > h3 = find_h<MOD3>(c, d);

    reverse(all(d));

    auto segm_sum = [&](ll l, ll r)
    {
        return (l + r) * (r - l + 1) / 2;
    };

    for (int i = 0; i < n - m + 1; i++)
    {
        int ok = h2[i + m - 1] == 0;
        if (ok)
        {
            //cout << "try match on position " << i << "\n";
            ll D = i + 1;
            ll can_sub = (D / 2) * (D / 2 + 1);

            ll mn = a[i] - can_sub;
            ll q = a[i] + a[i + 1] + D / 2 + 1;
            ll operations = q - b[0] - b[1];
            //cout << "q = " << q << "\n";
            //cout << "mn, ops = " << mn << " " << operations << "\n";
            if (0 <= operations && operations <= D + 1)
            {
                ll add = b[0] - mn;
                //cout << "add = " << add << "\n";
                //cout << "D = " << D << "\n";
                if (segm_sum(0, operations - 1) <= add && add <= segm_sum(D - operations + 1, D))
                {
                    // answer is YES
                    vector<int> inuse(D + 1);
                    for (int i = 0; i <= D; i += 2)
                        inuse[i] = 1;

                    //cout << "going to add " << add << ", " << operations << "\n";
                    if (operations != D + 1)
                    {
                        add -= segm_sum(0, operations - 1);
                        for (int i = 0; i < operations; i++)
                        {
                            inuse[i] ^= 1;
                        }
                        ll cnt_move = add / (D - operations + 1);
                        for (int i = D - cnt_move + 1; i <= D; i++)
                        {
                            add -= (D - operations + 1);
                            inuse[i - (D - operations + 1)] ^= 1;
                            inuse[i] ^= 1;
                        }
                        //cout << inuse << " ( " << cnt_move << "\n";
                        ll rem = add;
                        inuse[operations - 1 - cnt_move] ^= 1;
                        inuse[operations - 1 - cnt_move + rem] ^= 1;
                        //cout << inuse << " ( " << rem << "\n";
                    }
                    else
                    {
                        for (int i = 0; i <= D; i++) inuse[i] ^= 1;
                    }

                    vector<int> ans;
                    for (int j = 2; j < m; j++)
                    {
                        assert(d[j - 2] == c[i + j - 2] || d[j - 2] == c[i + j - 2] + 1);
                        if (d[j - 2] != c[i + j - 2])
                            ans.push_back(i + j + 1);
                    }
                    for (int j = 0; j <= D; j++)
                    {
                        if (inuse[j])
                        {
                            ans.push_back(i + 2 - j);
                        }
                    }
                    sort(all(ans));
                    cout << ans.size() << "\n" << ans << "\n";
                    return;
                }
            }
        }
    }
    cout << -1 << "\n";
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