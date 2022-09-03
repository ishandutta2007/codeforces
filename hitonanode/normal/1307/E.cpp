#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

template <int mod>
struct ModInt
{
    using lint = long long;
    int val;
    constexpr ModInt() : val(0) {}
    constexpr ModInt &_setval(lint v) { val = (v >= mod ? v - mod : v); return *this; }
    constexpr ModInt(lint v) { _setval(v % mod + mod); }
    explicit operator bool() const { return val != 0; }
    constexpr ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    constexpr ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + mod); }
    constexpr ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % mod); }
    constexpr ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % mod); }
    constexpr ModInt operator-() const { return ModInt()._setval(mod - val); }
    constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    constexpr ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend constexpr ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend constexpr ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend constexpr ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend constexpr ModInt operator/(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.inv() % mod); }
    constexpr bool operator==(const ModInt &x) const { return val == x.val; }
    constexpr bool operator!=(const ModInt &x) const { return val != x.val; }
    bool operator<(const ModInt &x) const { return val < x.val; }  // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) { lint t; is >> t; x = ModInt(t); return is; }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { os << x.val;  return os; }
    constexpr lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    constexpr lint inv() const { return this->power(mod - 2); }
    constexpr ModInt operator^(lint n) const { return ModInt(this->power(n)); }
    constexpr ModInt &operator^=(lint n) { return *this = *this ^ n; }

    inline ModInt fac() const {
        static std::vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val) return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs[i] = (i == 0 ? ModInt(1) : facs[i - 1] * ModInt(i));
        return facs[this->val];
    }

    ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        if (this->val & 1) return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
        else return ModInt(k).fac() * ModInt(2).power(k);
    }

    ModInt nCr(const ModInt &r) const {
        if (this->val < r.val) return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }
};

using mint = ModInt<1000000007>;
constexpr int MAXI = 5001;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    cin >> S;
    vector<vector<int>> len(2, vector<int>(M, 1e9));
    vector<int> F(M), H(M);
    REP(i, M) cin >> F[i] >> H[i];

    REP(d, 2)
    {
        REP(i, M) {
            int cnt = 0;
            REP(now, N) {
                if (S[now] == F[i]) cnt++;
                if (cnt == H[i]) mmin(len[d][i], now + 1);
            }
        }
        reverse(S.begin(), S.end());
    }

    int nbmax = 0;
    mint patt = 0;
    REP(lmv, N + 1) {
        bool just = false;
        vector<int> LR(MAXI), L(MAXI), R(MAXI);
        int cc = -1;
        if (lmv) cc = S[lmv - 1];
        REP(i, M) {
            if (len[0][i] == lmv) {
                L[F[i]]++;
                just = true;
            }
            else if (len[0][i] <= lmv and len[1][i] <= N - lmv) {
                if (F[i] != cc) {
                    LR[F[i]]++;
                }
                else R[F[i]]++;
            }
            else if (len[0][i] <= lmv) {
                if (F[i] != cc) L[F[i]]++;
            }
            else if (len[1][i] <= N - lmv)
            {
                R[F[i]]++;
            }
        }
        if (!just and lmv != 0) continue;
        int nb_tmp = 0;
        mint patt_tmp = 1;
        REP(i, MAXI) {
            if (LR[i] >= 2 or (LR[i] and (L[i] or R[i])) or (L[i] and R[i])) {
                patt_tmp *= (L[i] * R[i] + LR[i] * R[i] + L[i] * LR[i] + LR[i] * (LR[i] - 1));
                nb_tmp += 2;
            }
            else if (LR[i] + L[i] + R[i]) {
                patt_tmp *= LR[i] * 2 + L[i] + R[i];
                nb_tmp++;
            }
        }
        if (mmax(nbmax, nb_tmp)) patt = patt_tmp;
        else if (nbmax == nb_tmp) patt += patt_tmp;
    }
    cout << nbmax << " " << patt.val << endl;
}