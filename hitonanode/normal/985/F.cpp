#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


// Rolling Hash (Rabin-Karp), 1dim
template<typename V>
struct rolling_hash
{
    V B;
    vector<V> hash; // hash[i] = s[0] * B^(i - 1) + ... + s[i - 1]
    vector<V> power; // power[i] = B^i
    rolling_hash() {}
    rolling_hash(const string &s, V b) : B(b)
    {
        int N = s.length();
        hash.resize(N + 1), power.resize(N + 1, 1);
        for (int i = 0; i < N; i++)
        {
            power[i + 1] = power[i] * B;
            hash[i + 1] = hash[i] * B + s[i];
        }
    }
    V get_hash(int l, int r) // s[l] * B^(r - l - 1) + ... + s[r - 1]
    {
        return hash[r] - hash[l] * power[r - l];
    }
};

using lint = long long;
using plint = pair<lint, lint>;
struct DoubleHash : public plint
{
    static plint MODs;
    DoubleHash(plint x) : plint(x) {}
    DoubleHash(lint x, lint y) : plint(x, y) {}
    DoubleHash(lint x) : DoubleHash(x, x) {}
    DoubleHash() : DoubleHash(0) {}
    static inline DoubleHash mod_subtract(plint x)
    {
        if (x.first >= MODs.first) x.first -= MODs.first;
        if (x.second >= MODs.second) x.second -= MODs.second;
        return x;
    }
    DoubleHash operator+(const DoubleHash &x) const
    {
        return mod_subtract(plint(this->first + x.first, this->second + x.second));
    }
    DoubleHash operator+(lint x) const
    {
        return mod_subtract(plint(this->first + x, this->second + x));
    }
    DoubleHash operator-(const DoubleHash &x) const
    {
        return mod_subtract(plint(this->first - x.first + MODs.first, this->second - x.second + MODs.second));
    }
    DoubleHash operator*(const DoubleHash &x) const
    {
        return make_pair(this->first * x.first % MODs.first, this->second * x.second % MODs.second);
    }
    DoubleHash operator*(lint x) const
    {
        return make_pair(this->first * x % MODs.first, this->second * x % MODs.second);
    }
};
plint DoubleHash::MODs = plint(1000000007, 998244353);

struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;

int main()
{
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<rolling_hash<DoubleHash>> rh;
    DoubleHash b(rnd(2, 1000000), rnd(2, 10000000));
    REP(d, 26)
    {
        string tmp(N, '0');
        REP(i, N) if (S[i] == 'a' + d) tmp[i] = '1';
        rh.push_back(rolling_hash<DoubleHash>(tmp, b));
    }
    vector<DoubleHash> hx(26), hy(26);
    while (M--) {
        int x, y, len;
        cin >> x >> y >> len;
        x--, y--;
        REP(d, 26) hx[d] = rh[d].get_hash(x, x + len), hy[d] = rh[d].get_hash(y, y + len);
        sort(hx.begin(), hx.end());
        sort(hy.begin(), hy.end());
        cout << (hx == hy ? "YES" : "NO") << "\n";
    }
}